#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
int input() {
	setlocale(LC_ALL, "");
	string key_input;
	int number;
	cin >> key_input;
	number = stoi(key_input);
	if (number >= 0 && number < INT_MAX - 1) {
		return number;
	}
	else {
		cout << "Ошибка! Некорректный ввод, попробуйте еще раз: ";
		input();
	}
}
void outputMatrix(vector<vector<int>> matrix) {
	cout << "----------------" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << setw(4) << matrix[i][j];
		}
		cout << "|" << endl;
		cout << "----------------" << endl;
	}
}
void outputSumm() {
	cout << "Вывод суммы" << endl;
}