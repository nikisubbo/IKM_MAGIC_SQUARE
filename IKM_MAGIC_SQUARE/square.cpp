#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
int generationSquare() {
	srand(time(0));
	vector <vector <int>> matrix(3, vector <int>(3));
	cout << "Идет генерация квадрата..." << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix[i][j] = 0;
		}
	}
	int num_one = rand() % 101;
	int num_two = rand() % 101;
	int num_three = rand() % 101;
	int column_one = 0, line_one = 0, column_two = 0, line_two = 0, column_three = 0, line_three = 0;
	do {
		column_one = rand() % 3;
		line_one = rand() % 3;
		column_two = rand() % 3;
		line_two = rand() % 3;
		column_three = rand() % 3;
		line_three = rand() % 3;
	} while ((column_one == column_two && line_one == line_two) || (column_one == column_three && line_one == line_three) || (column_two == column_three && line_two == line_three));
	matrix[column_one][line_one] = num_one;
	matrix[column_two][line_two] = num_two;
	matrix[column_three][line_three] = num_three;
	//cout << column_one << " " << line_one << " | " << column_two << " " << line_two << " | " << column_three << " " << line_three << " | " << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << setw(4) << matrix[i][j];
		}
		cout << "|" << endl;
		cout << "----------------" << endl;
	}
	return 1;

}
void checkCorrectSquare() {
	cout << "Проверка корректности" << endl;
}