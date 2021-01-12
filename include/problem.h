#ifndef __PROBLEM_H__
#define __PROBLEM_H__

#include "constant.h"
#include "problem_helper.h"

class Problem // A N-1_puzzle problem 
{
    public:

	int initial_state[N];
	int goal_state[N] = { 1,2,3,4,5,6,7,8,0 };

    Problem();// Initialization { for (int i = 0; i < N; i++) initial_state[i] = 0; }  
	Problem(int istate[]); //Initialization

	bool Goal_Test(int state[]); // The object of the puzzle is to slide the tiles horizontally or vertically into the empty space until the configuration matches the goal configuration.
	
    void displayProblem(); // Description of the puzzle 
	
	void Move_Up(Node *node, priority_queue<Node*, vector<Node*>, cmp>& frontier, int algorithm, Node explored[], int & k); // If the "blank" is not in the first line, then it could be moved up.
	void Move_Down(Node *node, priority_queue<Node*, vector<Node*>, cmp> &frontier, int algorithm, Node explored[], int & k); // If the "blank" is not in the last line, then it could be moved down.
	void Move_Left(Node *node, priority_queue<Node*, vector<Node*>, cmp> &frontier, int algorithm, Node explored[], int & k); // If the "blank" is not in the leftmost column, then it could be moved left.
	void Move_Right(Node *node, priority_queue<Node*, vector<Node*>, cmp>& frontier, int algorithm, Node explored[], int & k); // If the "blank" is not in the rightmost column, then it could be moved right.
};

#endif