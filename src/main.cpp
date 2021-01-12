#include <iostream>
#include "constant.h"
#include "node.h"
#include "problem.h"
#include "check_solvable.h"
#include "solution.h"
#include "make_queue.h"

using namespace std;

int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Change the message within "cout" accordingly if you modify the N.
	int initial_state[N] = {4,1,5,7,2,0,3,6,8 }; // Default initial state of a puzzle for test
	cout << "Welcome to JIAQI XIONG's 8-puzzle solver!" << endl;
	int direction;
	cout << "Please type '1' to use a default puzzle, or '2' to enter your own puzzle." << endl;
	cin >> direction;
	if (direction == 2)
	{
		cout << "Now ready for your puzzle (use a zero to represent the blank)" << '\n' << "Enter the first row (use space or tabs between numbers):" << endl;
		for (int i = 0; i < length; i++) cin >> initial_state[i];
		cout << "Enter the second row (use space or tabs between numbers):" << endl;
		for (int i = 0; i < length; i++) cin >> initial_state[i + length];
		cout << "Enter the third row (use space or tabs between numbers):" << endl;
		for (int i = 0; i < length; i++) cin >> initial_state[i + 2 * length];
		// Add more if needed as you change the N.
	}
	else if (direction != 1)
	{
		cout << "Invaid input! Please check and restart." << endl;
		system("read -p 'Press Enter to continue...' var");
		return (0);
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Problem puzzle(initial_state); // Generate the puzzle according to the initial condition
	if (!checkSolvable(puzzle)) // Check if the puzzle can be solved at first.
	{
		cout << "Unfortunately, this puzzle is unsolvable. Please retry." << endl;
		system("read -p 'Press Enter to continue...' var");
		return (0);
	}

	int algorithm;
	cout << "Please enter your choice of algorithm:" << '\n' << "1. Uniform Cost Search." << '\n' << "2. A* with the Misplaced Tile heuristic." << '\n' << "3. A* with the Manhattan distance heuristic." << endl;
	cin >> algorithm;
	if (algorithm != 1 && algorithm != 2 && algorithm != 3)
	{
		cout << "Invaid input! Please check and restart." << endl;
		system("read -p 'Press Enter to continue...' var");
		return (0);
	}

	priority_queue<Node*, vector<Node*>, cmp> frontier = Make_Queue(puzzle); // Prepare for search from the initial state of the problem using priority queue
	Node explored[L]; // Store the nodes which have been expanded.
	int k = 0; // The number of nodes which have been expanded.
	while (1)
	{
		if (frontier.empty())
		{
			cout << "Failure!" << endl;
			system("read -p 'Press Enter to continue...' var");
			return (0);
		}

		Node *node = frontier.top(); // Expand the node with lowest total cost
		frontier.pop();  // Remove the node which has been searched
		if (puzzle.Goal_Test(node->state)) // If we reach the goal node, then give the solution.
		{
			int depth = Solution(puzzle, node);
			cout << "Congratulations! We succeed arriving the goal!" << endl;
			cout << "To solve this problem the search algorithm expanded a total of " << k + frontier.size() << " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time was " << frontier.size()+1 << '.' << endl;
			cout << "The depth of the goal node was " << depth << '.' << endl;
			system("read -p 'Press Enter to continue...' var");
			return (0);
		}

		explored[k] = *node; // If we don't reach the goal, then keep searching.
		k = k + 1;
		puzzle.Move_Up(node, frontier, algorithm, explored, k);
		puzzle.Move_Down(node, frontier, algorithm, explored, k);
		puzzle.Move_Left(node, frontier, algorithm, explored, k);
		puzzle.Move_Right(node, frontier, algorithm, explored, k);
	}
}

