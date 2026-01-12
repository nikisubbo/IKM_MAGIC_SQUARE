#include <iostream>
#include <vector>
#include "Header.h"
#include <iomanip>
#include <ctime>
void game() {
	srand(time(0));
	int center_num = rand() % 11;
	int size = 3;
	vector < vector <int> > matrix(size, vector <int>(size));
	vector < vector <int> > player_matrix((size), vector <int>(size));
	vector <int> moves;
	matrix = generationSquare(matrix, size, center_num);
	player_matrix = generationPlayersSquare(matrix, size);
	outputSumm(matrix);
	outputMatrix(matrix);
	while (!testWinOrLose(matrix, player_matrix)) {
		outputMatrix(player_matrix);
		moves = possibleMoves(matrix, player_matrix, size);
		outputVector(moves);
		playersMove(player_matrix, moves);
		cout << "\x1b[33mХод сделан.\x1b[0m" << endl;
	}
	cout << "\x1b[33mВаш квадрат:\x1b[0m " << endl;
	outputMatrix(player_matrix);
	cout << "\x1b[33mПроверим, магический ли он...\x1b[0m" << endl;
	if (checkCorrectSquare(player_matrix, size)) {
		cout << "\x1b[33mДа, этот квадрат магический,\x1b[0m \x1b[32mвы победили!\x1b[0m" << endl;
	}
	else {
		cout << "\x1b[33mВУпс, этот квадрат не магический,\x1b[0m \x1b[30mвы проиграли\x1b[0m" << endl;
		cout << "\x1bИскомая сумма была равна\x1b[0m ";
		outputSumm(matrix);
	}
}
void inGameMassage() {

}