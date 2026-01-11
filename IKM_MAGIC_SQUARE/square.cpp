#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
vector<vector<int>> generationSquare(vector<vector<int>> matrix, int n, int m) {
	vector <vector <int>> magic_square = { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } };
	int center = (5 + (rand() % (n - 5 + 1))) - 5;
	srand(time(0));
	cout << "Идет генерация квадрата..." << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = magic_square[i][j] + center;
		}
	}
	return matrix;
}
vector<vector<int>> generationPlayersSquare(vector<vector<int>> matrix, int m){
	vector < vector <int> > player_matrix1(3, vector <int>(3));
	srand(time(0));
	int column_one = rand() % m;
	int line_one = rand() % m;
	int column_two = rand() % m;
	int line_two = rand() % m;
	int column_three = rand() % m;
	int line_three = rand() % m;
	player_matrix1[line_one][column_one] = matrix[line_one][column_one];
	player_matrix1[line_two][column_two] = matrix[line_two][column_two];
	player_matrix1[line_three][column_three] = matrix[line_three][column_three];
	return player_matrix1;
	}
bool checkCorrectSquare(vector<vector<int>> matrix, int m) { //условие магического квадрата
	int summa = 0;
	for (int i = 0; i < m; i++) {
		summa += matrix[0][i];
	}
	for (int i = 0; i < m; i++) {
		int temp_summ = 0;
		for (int j = 0; j < m; j++) {
			temp_summ += matrix[i][j];
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	for (int j = 0; j < m; j++) {
		int temp_summ = 0;
		for (int i = 0; i < m; i++) {
			temp_summ += matrix[i][j];
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	int temp_sum1 = 0;
	int temp_sum2 = 0;
	for (int i = 0; i < m; i++) {
		temp_sum1 += matrix[i][i];
		temp_sum2 += matrix[i][2 - i];
	}
	if (temp_sum1 != summa || temp_sum2 != summa) {
		return false;
	}
	return true;
}
vector <int> possibleMoves(vector<vector<int>> matrix, vector<vector<int>> player_matrix, int m) {
	vector <int> moves;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != player_matrix[i][j]) {
				moves.push_back(matrix[i][j]);
			}
		}
	}
	return moves;
}