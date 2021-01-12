#ifndef __NODE_H__
#define __NODE_H__

#include "constant.h"

class Node // A node represent a state of a puzzle.
{
    public:

	int state[N]; // Dimensionality reduction from 2-D to 1-D, where 0 represents "blank"
	int blankIndex = -1; // Corresponding 1-D position of "blank"
	int PC = 0; // Path cost g(n)
	int MT = -1; // Misplaced Tile heuristic h1(n)
	int MD = -2; // Manhattan Distance heuristic h2(n)
	int priority = 0; // f(n) 

	Node *parent = nullptr; // Point to the previous state. 

    Node(); // Initialization {for (int i = 0; i < N; i++) state[i] = 0;}
	Node(int s[]); // Initialization
	Node(int s[], Node* node, int blank); // Initialization

	int getBlank(); 
	
	int getMT(); // MT is the number of misplaced tiles.
	
	int getMD(); // MD is the sum of the distances of the tiles from their goal positions.
	
	void displayNode(); // Visualization of the state of the puzzle from 1-D to 2-D
};

#endif