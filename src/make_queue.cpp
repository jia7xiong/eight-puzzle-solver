#include "make_queue.h"

priority_queue<Node*, vector<Node*>, cmp>  Make_Queue(Problem puzzle) 
{
	puzzle.displayProblem();
	Node *node = new Node(puzzle.initial_state);
	priority_queue<Node*, vector<Node*>, cmp> frontier; // Nodes in queue are waiting for expanded
	frontier.push(node);
	return frontier;
}