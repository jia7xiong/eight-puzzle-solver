#include "problem_helper.h"

bool equalState(int state1[], int state2[])
{
	for (int i = 0; i < N - 1; i++) if (state1[i] != state2[i]) return false;
	return true;
}

bool checkRepeat(Node *node, Node explored[], int &k)
{
	bool repeat = false;
	if (node == node->parent->parent) repeat = true; //If a child of a node is exactly its grandparent, then we don't want to go back to that state.
	else
	{
		for (int i = 0; i <= k; i++)
		{
			if (equalState(explored[i].state, node->state)) // If a node is exactly the same as a node in explored. then it must have been expanded.
			{
				repeat = true;
				break;
			}

		}
	}
	return repeat;
}

void Queue_Function(priority_queue<Node*, vector<Node*>, cmp>& frontier, Node *child, int algorithm, Node explored[], int & k)
{
	if (algorithm == 1) child->MD = -1; // h(n)=0
	else if (algorithm == 2)
	{
		child->MT = child->getMT();
		child->priority = child->priority + child->MT; 
	}
	else
	{
		child->MD = child->getMD();
		child->priority = child->priority + child->MD;
	}
	if (!checkRepeat(child, explored, k)) frontier.push(child);
}