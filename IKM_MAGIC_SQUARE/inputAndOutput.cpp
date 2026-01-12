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
	cout << "  \x1b[33m| 1  |  2 |  3 |\x1b[0m" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\x1b[33m" << i + 1 << "\x1b[0m ";
		for (int j = 0; j < 3; j++) {
			cout << "|" << setw(4) << matrix[i][j];
		}
		cout << "|" << endl;
		cout << "------------------" << endl;
	}
}
void outputVector(vector<int> moves) {
	cout << "Возможные ходы: ";
	for (int i = 0; i < moves.size(); i++) {
		cout << "\x1b[33m" << i + 1 << ")" << "\x1b[0m" << moves[i] << "  ";
	}
	cout << endl;
}
void outputSumm(vector<vector<int>> matrix) {
	int summ = matrix[0][0] + matrix[0][1] + matrix[0][2];
	cout << "Магическая сумма равна \x1b[33m" << summ << "\x1b[0m" << endl;
}
void playersMove(vector<vector<int>>& player_matrix, vector <int>& moves) {
	int column = 0, line = 0;
	int number = 0;
	cout << "Выберите ячеку, куда хотите вставить число (ввод в формате" << " \x1b[33mСТРОКА СТОЛБЕЦ\x1b[0m): ";
	line = input() - 1;
	column = input() - 1;
	cout << "Выберите \x1b[33mНОМЕР\x1b[0m числа, которое вы хотите вставить в эту ячейку, введите \x1b[33mНОМЕР\x1b[0m выбранного числа: ";
	number = input() - 1;
	//cout << "| " << line << " " << column << " " << number << " " << moves[number] << " |\n";
	player_matrix[line][column] = moves[number];
	moves = deleteUsedMove(moves, number);
}
vector <int> deleteUsedMove(vector <int> moves, int number) {
	number -= 1;
	for (int i = 0; i < size(moves); i++) {
		if (number == i) {
			moves.erase(moves.begin() + i);
			break;
		}
	}
	return moves;
}