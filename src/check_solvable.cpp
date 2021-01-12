#include "check_solvable.h"

bool checkSolvable(Problem puzzle) // If a problem is solvable, then return true; Otherwise return false.
{
	bool solvable = false;
	int inversion = 0; // A pair of tiles (a, b) form an inversion if a appears before b but a > b.
	int bindex = -1; // The position of the "blank"
	for (int i = 0; i < N; i++)
	{
		if (puzzle.initial_state[i] == 0) bindex = i;
		for (int j = i + 1; j < N; j++)
			if (puzzle.initial_state[i] > puzzle.initial_state[j] && puzzle.initial_state[j] != 0) inversion = inversion + 1;
	}
	if (!(N % 2)) 
	{
		int pb = length - bindex % length;
		if ((!(pb % 2) && inversion % 2) || (pb % 2 && !(inversion % 2))) solvable = true; // If N is even, a puzzle is solvable if the "blank" is on an even row counting from the bottom and number of inversions is odd or the "blank" is on an odd row counting from the bottom and number of inversions is even.
	}
	else if (!(inversion % 2)) solvable = true; // If N is odd, then a puzzle is solvable if number of inversions in the initial state.
	return solvable;
}