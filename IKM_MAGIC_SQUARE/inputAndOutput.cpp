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
void outputVector(vector<int> moves) {
	cout << "Возможные ходы: ";
	for (int i = 0; i < moves.size(); i++) {
		cout << moves[i] << " ";
	}
	cout << endl;
}
void outputSumm() {
	cout << "Вывод суммы" << endl;
}
void playersMove(vector<vector<int>>& player_matrix, vector <int>& moves) {
	int column = 0, line = 0;
	int number;
	cout << "Выберите ячеку, куда хотите вставить число (ввод в формате СТРОКА СТОЛБЕЦ): ";
	line = input();
	column = input();
	cout << "Выберите число, которое вы хотите вставить в эту ячейку, введите НОМЕР выбранного числа: ";
	number = input();
	cout << "| " << line << " " << column << " " << number << " " << moves[number] << " |\n";
	player_matrix[line][column] = moves[number];
	moves = deleteUsedMove(moves, number);
}
vector <int> deleteUsedMove(vector <int> moves, int number) {
	for (int i = 0; i < size(moves); i++) {
		if (number == moves[i]) {
			moves.erase(moves.begin() + i);
			break;
		}
	}
	return moves;
}