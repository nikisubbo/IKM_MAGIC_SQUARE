#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
#include <string>
int input() {
	setlocale(LC_ALL, "");
	string key_input;
	int number;
	cin >> key_input;
	number = stoi(key_input);
	if (number < INT_MAX - 1) {
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
	cout << "\x1b[33m" << summ << "\x1b[0m" << endl;
}
void playersMove(vector<vector<int>>& player_matrix, vector <int>& moves) {
	int column = 0, line = 0;
	int number = 0;
	int choice = 0;
	cout << "Выберите ячеку, куда хотите вставить число (ввод в формате" << " \x1b[33mСТРОКА СТОЛБЕЦ\x1b[0m): ";
	//cout << "|||" << moves.size() << "|||" << endl;
	line = input() - 1;
	column = input() - 1;
	if (line > player_matrix.size() || column > player_matrix.size()) {
		cout << "Ошибка, введите корректные СТРОКУ СТОЛБЕЦ (число от 1 до 3)" << endl;
		playersMove(player_matrix, moves);
		return;
	}
	else {
		cout << "Выберите \x1b[33mНОМЕР\x1b[0m числа, которое вы хотите вставить в эту ячейку, введите \x1b[33mНОМЕР\x1b[0m выбранного числа: ";
		number = input() - 1;
		if (number < 0 || number >= (int)moves.size()) {
			cout << "Ошибка, введите корректный НОМЕР числа, номера указаны слева от числа" << endl;
			playersMove(player_matrix, moves);
			return;
		}
		else {
			//cout << "| " << line << " " << column << " " << number << " " << moves[number] << " |\n";
			if (player_matrix[line][column] != 0) {
				cout << "Ячейка уже занята.\nЕсли вы хотите заменить в ней значение, введите 1, если хотите оставить как есть, введите 0: ";
				choice = input();
				if (choice == 0) {
					return;
				}
				else if (choice == 1) {
					int old_value = player_matrix[line][column];
					player_matrix[line][column] = moves[number];
					moves.push_back(old_value);
					moves = deleteUsedMove(moves, number);
				}
				else {
					cout << "\x1b[33mОшибка. Некорректный ввод\x1b[0m" << endl;
					return;
				}
			}
			else {
				player_matrix[line][column] = moves[number];
				moves = deleteUsedMove(moves, number);
			}
		}
	}
}
vector <int> deleteUsedMove(vector <int> moves, int number) {
	for (int i = 0; i < size(moves); i++) {
		if (number == i) {
			moves.erase(moves.begin() + i);
			break;
		}
	}
	return moves;
}