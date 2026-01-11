#include <iostream>
#include <vector>
#include "Header.h"
#include <iomanip>
#include <ctime>
void game() {
	int size = 3;
	vector < vector <int> > matrix(size, vector <int>(size));
	vector < vector <int> > player_matrix((size), vector <int>(size));
	vector <int> moves;
	matrix = generationSquare(matrix, 10, size);
	player_matrix = generationPlayersSquare(matrix, size);
	//outputMatrix(matrix);

	if (checkCorrectSquare(matrix, size)) {
		outputMatrix(player_matrix);
		moves = possibleMoves(matrix, player_matrix, size);
		outputVector(moves);
		playersMove(player_matrix, moves);
		cout << "Ход сделан." << endl; 
		outputMatrix(player_matrix);
		outputVector(moves);
	}
	else {
		game();
	}
}
void inGameMassage() {

}