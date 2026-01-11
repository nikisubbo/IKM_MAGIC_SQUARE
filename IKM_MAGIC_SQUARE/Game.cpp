#include <iostream>
#include <vector>
#include "Header.h"
#include <iomanip>
#include <ctime>
void game() {
	vector < vector <int> > matrix(3, vector <int>(3));
	vector < vector <int> > player_matrix(3, vector <int>(3));
	vector <int> moves;
	matrix = generationSquare(matrix);
	player_matrix = generationPlayersSquare(matrix);
	//outputMatrix(matrix);
	if (checkCorrectSquare(matrix)) {
		outputMatrix(player_matrix);
		moves = possibleMoves(matrix, player_matrix);
		outputVector(moves);
	}
	else {
		game();
	}
}
