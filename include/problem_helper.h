#ifndef __PROBLEM_HELPER_H__
#define __PROBLEM_HELPER_H__

#include <queue>
#include "node.h"

using namespace std;

struct cmp // Operator overloading allows sorting a queue based on the priority that the node with lowest priority is poped firstly.
{ 
    bool operator() (Node* &a, Node* &b)const { return a->priority > b->priority; } 
};  

bool equalState(int state1[], int state2[]); // If two state are the same, then return true; Otherwise return false.

bool checkRepeat(Node *node, Node explored[], int &k); // If the node has already been expanded, then return true; Otherwise return false.

void Queue_Function(priority_queue<Node*, vector<Node*>, cmp>& frontier, Node *child, int algorithm, Node explored[], int & k); // Enqueue 

#endif