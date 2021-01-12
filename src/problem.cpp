#include <iostream>
#include "problem.h"

Problem::Problem() { memset(initial_state, 0, N); } // Initialization { for (int i = 0; i < N; i++) initial_state[i] = 0; }  
Problem::Problem(int istate[]) { for (int i = 0; i < N; i++) initial_state[i] = istate[i]; } //Initialization

bool Problem::Goal_Test(int state[]) { return equalState(state, goal_state); } // The object of the puzzle is to slide the tiles horizontally or vertically into the empty space until the configuration matches the goal configuration.

void Problem::displayProblem() // Description of the puzzle 
{
    cout << "Expanding state..." << endl;
    for (int i = 0; i < length; i++) cout << initial_state[i] << ' ';
    cout << endl;
    for (int i = 0; i < length; i++) cout << initial_state[i + length] << ' ';
    cout << endl;
    for (int i = 0; i < length; i++) cout << initial_state[i + 2 * length] << ' ';
    cout << '\n' << endl;
}

void Problem::Move_Up(Node *node, priority_queue<Node*, vector<Node*>, cmp>& frontier, int algorithm, Node explored[], int & k) // If the "blank" is not in the first line, then it could be moved up.
{
    if (node->blankIndex > length - 1)
    {
        int state[N];
        for (int i = 0; i < N; i++) state[i] = node->state[i]; 
        state[node->blankIndex] = state[node->blankIndex - 3];
        state[node->blankIndex - 3] = 0;
        Node * child = new Node(state, node, node->blankIndex - 3);
        Queue_Function(frontier, child, algorithm, explored, k);
    }
}
void Problem::Move_Down(Node *node, priority_queue<Node*, vector<Node*>, cmp> &frontier, int algorithm, Node explored[], int & k) // If the "blank" is not in the last line, then it could be moved down.
{
    if (node->blankIndex < N - length)
    {
        int state[N];
        for (int i = 0; i < N; i++) state[i] = node->state[i]; 
        state[node->blankIndex] = state[node->blankIndex + 3];
        state[node->blankIndex + 3] = 0;
        Node *child = new Node(state, node, node->blankIndex + 3);
        Queue_Function(frontier, child, algorithm, explored, k);
    }
}
void Problem::Move_Left(Node *node, priority_queue<Node*, vector<Node*>, cmp> &frontier, int algorithm, Node explored[], int & k) // If the "blank" is not in the leftmost column, then it could be moved left.
{
    if (node->blankIndex % 3 > 0)
    {
        int state[N];
        for (int i = 0; i < N; i++) state[i] = node->state[i]; 
        state[node->blankIndex] = state[node->blankIndex - 1];
        state[node->blankIndex - 1] = 0;
        Node *child = new Node(state, node, node->blankIndex - 1);
        Queue_Function(frontier, child, algorithm, explored, k);
    }
}
void Problem::Move_Right(Node *node, priority_queue<Node*, vector<Node*>, cmp>& frontier, int algorithm, Node explored[], int & k) // If the "blank" is not in the rightmost column, then it could be moved right.
{
    if (node->blankIndex % 3 < length - 1)
    {
        int state[N];
        for (int i = 0; i < N; i++) state[i] = node->state[i]; 
        state[node->blankIndex] = state[node->blankIndex + 1];
        state[node->blankIndex + 1] = 0;
        Node* child = new Node(state, node, node->blankIndex + 1);
        Queue_Function(frontier, child, algorithm, explored, k);
    }
}