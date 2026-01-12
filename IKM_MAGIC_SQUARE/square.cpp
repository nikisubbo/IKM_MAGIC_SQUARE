#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
vector<vector<int>> generationSquare(vector<vector<int>> matrix, int size, int center_num) {
	int number = 1;
	int column = size / 2;
	int line = 0; //для первого числа
	while (number <= size * size) {
		matrix[line][column] = number;
		int current_line = line;
		int current_column = column;
		line--;
		column++;
		if (line < 0) {
			line = size - 1;
		}
		if (column == size) {
			column = 0;
		}
		if (matrix[line][column]){
			line = current_line + 1;
			column = current_column;
			if (line == size) {
				line = 0;
			}
		}
		number++;
	}
	int center_position = size / 2;
	int current_center_num = matrix[center_position][center_position];
	int difference = center_num - current_center_num;	
	int min_value = matrix[0][0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] += difference;
			if (matrix[i][j] < min_value) {
				min_value = matrix[i][j];
			}
		}
	}
	if (min_value <= 0) {
		int shift = 1 - min_value;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] += shift;
			}
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
	return true;// 8 1 6 / 3 5 7 / 4 9 2 
}
vector <int> possibleMoves(vector<vector<int>> matrix, vector<vector<int>> player_matrix, int m) {
	vector <int> moves;
	//default_random_engine rand_pos(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] != player_matrix[i][j]) {
				moves.push_back(matrix[i][j]);
			}
		}
	}
	//shuffle(moves.begin(), moves.end(), rand_pos);
	return moves;
}
bool testEndGame(vector<vector<int>> player_matrix, vector <int> moves) {
	if (moves.size() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}