#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
#include <string>
int input() {//фукнция для ввода, чтобы автоматически проверять на "критические" значения
	setlocale(LC_ALL, "");
	string key_input;
	cin >> key_input;
	long long number = stoll(key_input);
	if (number >= INT_MIN && number <= INT_MAX) {
		return static_cast<int>(number);//безопасный переход от long long в int
	}
	else {
		cout << "Ошибка. Некорректный ввод, попробуйте еще раз: " ;
		return input();
	}
}
void outputMatrix(vector<vector<int>> matrix) {//вывод матрицы в виде таблицы
	cout << "  \x1b[33m| 1  |  2 |  3 |\x1b[0m" << endl;//\x1b[33m \x1b[0m нужны для окрашивания в желтый цвет
	cout << "------------------" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		cout << "\x1b[33m" << i + 1 << "\x1b[0m ";
		for (int j = 0; j < matrix.size(); j++) {
			cout << "|" << setw(4) << matrix[i][j];
		}
		cout << "|" << endl;
		cout << "------------------" << endl;
	}
}
void outputVector(vector<int> moves) { // вывод вектора с ходами через скобку 
	cout << "Возможные ходы: "; 
	for (int i = 0; i < moves.size(); i++) {
		cout << "\x1b[33m" << i + 1 << ")" << "\x1b[0m" << moves[i] << "  ";
	}
	cout << endl;
}
void outputSumm(vector<vector<int>> matrix) { // вывод магической суммы
	int summ = matrix[0][0] + matrix[0][1] + matrix[0][2];//подходит любая сумма по любой линии
	cout << "\x1b[33m" << summ << "\x1b[0m" << endl;
}
void playersMove(vector<vector<int>>& player_matrix, vector <int>& moves) { //ход игрока
	int column = 0, line = 0;
	int number = 0;
	int choice = 0;
	cout << "Выберите ячеку, куда хотите вставить число (ввод в формате" << " \x1b[33mСТРОКА СТОЛБЕЦ\x1b[0m): ";
	line = input() - 1; //-1 потому что пользователю проще начинать подсчет с единицы а не с нуля
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
			if (player_matrix[line][column] != 0) {
				cout << "Ячейка уже занята.\nЕсли вы хотите заменить в ней значение, введите 1, если хотите оставить как есть, введите 0: ";
				choice = input();
				if (choice == 0) {
					return;
				}
				else if (choice == 1) {
					int old_value = player_matrix[line][column];
					player_matrix[line][column] = moves[number];
					moves.push_back(old_value);//вставляем в конец то значение, которое было в матрице до замены
					moves = deleteUsedMove(moves, number);//удаляем то, что вставили
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
vector <int> deleteUsedMove(vector <int> moves, int number) {//удаление хода из вектора, после хода игрока
	for (int i = 0; i < size(moves); i++) {
		if (number == i) {//если номер числа совпал с номером в векторе, то удалить
			moves.erase(moves.begin() + i);
			break;
		}
	}
	return moves;
}