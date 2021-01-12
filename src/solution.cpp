#include <stack>
#include <iostream>
#include "solution.h"

using namespace std;

int Solution(Problem puzzle, Node *node) // Trace the final node to the initial node using a stack
{
	stack<Node*> solution;
	while (!equalState(node->state, puzzle.initial_state))
	{
		solution.push(node);
		node = node->parent;
	}
	int depth = 0;
	while (!solution.empty())
	{
		depth = depth + 1; // Record the depth of the solution
		node = solution.top();
		solution.pop();
		node->displayNode();
		cout << "     Expanding this node..." << "\n" << endl;
	}
	return depth;
}