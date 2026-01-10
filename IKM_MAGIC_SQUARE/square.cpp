#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
vector<vector<int>> generationSquare(vector<vector<int>> matrix) {
	vector <vector <int>> magic_square = { { 8, 1, 6 }, { 3, 5, 7 }, { 4, 9, 2 } };
	int center = (rand() % 100) - 5;
	srand(time(0));
	cout << "Идет генерация квадрата..." << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = magic_square[i][j] + center;
		}
	}

	//int num_one = rand() % 101;
	//int num_two = rand() % 101;
	//int num_three = rand() % 101;
	//int column_one = 0, line_one = 0, column_two = 0, line_two = 0, column_three = 0, line_three = 0;
	//while ((column_one == column_two && line_one == line_two) || (column_one == column_three && line_one == line_three) || (column_two == column_three && line_two == line_three)) {
		//column_one = rand() % 3;
		//line_one = rand() % 3;
		//column_two = rand() % 3;
		//line_two = rand() % 3;
		//column_three = rand() % 3;
		//line_three = rand() % 3;
	//} 
	//matrix[line_one][column_one] = num_one;
	//matrix[line_two][column_two] = num_two;
	//matrix[line_three][column_three] = num_three;
	//cout << line_one << " " << column_one << " | " << line_two << " " << column_two << " | " << line_three << " " << column_three << " | " << endl;
	return matrix;
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
