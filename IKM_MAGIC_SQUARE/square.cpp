#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
vector<vector<int>> generationSquare(vector<vector<int>> matrix) {
	int n = 10;
	vector <vector <int>> magic_square = { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } };
	int center = (rand() % n) - 5;
	srand(time(0));
	cout << "Идет генерация квадрата..." << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = magic_square[i][j] + center;
		}
	}
	return matrix;
}
vector<vector<int>> generationPlayersSquare(vector<vector<int>> matrix){
	vector < vector <int> > player_matrix1(3, vector <int>(3));
	srand(time(0));
	int column_one = rand() % 3;
	int line_one = rand() % 3;
	int column_two = rand() % 3;
	int line_two = rand() % 3;
	int column_three = rand() % 3;
	int line_three = rand() % 3;
	player_matrix1[line_one][column_one] = matrix[line_one][column_one];
	player_matrix1[line_two][column_two] = matrix[line_two][column_two];
	player_matrix1[line_three][column_three] = matrix[line_three][column_three];
	return player_matrix1;
	}
bool checkCorrectSquare(vector<vector<int>> matrix) { //условие магического квадрата
	int summa = 0;
	for (int i = 0; i < 3; i++) {
		summa += matrix[0][i];
	}
	for (int i = 0; i < 3; i++) {
		int temp_summ = 0;
		for (int j = 0; j < 3; j++) {
			temp_summ += matrix[i][j];
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	for (int j = 0; j < 3; j++) {
		int temp_summ = 0;
		for (int i = 0; i < 3; i++) {
			temp_summ += matrix[i][j];
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	int temp_sum1 = 0;
	int temp_sum2 = 0;
	for (int i = 0; i < 3; i++) {
		temp_sum1 += matrix[i][i];
		temp_sum2 += matrix[i][2 - i];
	}
	if (temp_sum1 != summa || temp_sum2 != summa) {
		return false;
	}
	return true;
}
vector <int> possibleMoves(vector<vector<int>> matrix, vector<vector<int>> player_matrix) {
	vector <int> moves;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] != player_matrix[i][j]) {
				moves.push_back(matrix[i][j]);
			}
		}
	}
	return moves;
}