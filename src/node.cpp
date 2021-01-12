#include <iostream>
#include "node.h"

using namespace std;

Node::Node() { memset(state, 0, N); } // Initialization {for (int i = 0; i < N; i++) state[i] = 0;}
Node::Node(int s[]) // Initialization
{
    for (int i = 0; i < N; i++) state[i] = s[i];
    blankIndex = getBlank();
}
Node::Node(int s[], Node* node, int blank) :blankIndex(blank), parent(node) // Initialization
{
    for (int i = 0; i < N; i++) state[i] = s[i];
    PC = parent->PC + 1; //Each single slide costs 1.
    priority = PC; // For all three algorithms, f(n)=g(n)+h(n)
}

int Node::getBlank() 
	{
		for (int i = 0; i < N; i++)
			if (state[i] == 0) return i;
        
        cout << "Failure!" << endl;
		system("read -p 'Press Enter to continue...' var");
		return (0);
	}

int Node::getMT() // MT is the number of misplaced tiles.
{
    int count = 0;
    for (int i = 0; i < N - 1; i++)
        if (state[i] != (i + 1)) count = count + 1;
    return count;
}

int Node::getMD() // MD is the sum of the distances of the tiles from their goal positions.
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (state[i] != (i + 1) && state[i] != 0) count = count + abs(i / length - (state[i] - 1) / length) + abs((i + 1) % length - state[i] % length);
    return count;
}

void Node::displayNode() // Visualization of the state of the puzzle from 1-D to 2-D
{
    cout << "The best state to expand with a g(n) = " << PC;
    if (MD == -1) cout << endl; // "MD=-1" means the user choose Uniform Cost Search algorithm.
    else if (MD == -2) cout << " and h1(n)= " << MT << " is" << endl; // "MD=-2" means the user choose A* with h1(n) algorithm.
    else cout << " and h2(n)= " << MD << " is" << endl; //"MD �� -1 and MD �� -2" means the user choose A* with h2(n) algorithm.
    for (int i = 0; i < length; i++) cout << state[i] << ' ';
    cout << endl;
    for (int i = 0; i < length; i++) cout << state[i + length] << ' ';
    cout << endl;
    for (int i = 0; i < length; i++) cout << state[i + 2 * length] << ' ';
}
