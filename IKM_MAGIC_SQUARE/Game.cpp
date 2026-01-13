#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
void newGame() {
	srand(time(0));
	int center_num = rand() % 11;
	int size = 3;
	vector < vector <int> > matrix(size, vector <int>(size));
	vector < vector <int> > player_matrix((size), vector <int>(size));
	vector <int> moves;
	matrix = generationSquare(matrix, size, center_num);
	player_matrix = generationPlayersSquare(matrix, size);
	//outputSumm(matrix);
	//outputMatrix(matrix);
	moves = possibleMoves(matrix, player_matrix, size);
	while (!testEndGame(player_matrix, moves)) {
		outputMatrix(player_matrix);
		outputVector(moves);
		playersMove(player_matrix, moves);
		cout << "\x1b[33mХод сделан.\x1b[0m" << endl;
		cout << "Если вы хотите сохранить игру, введите 1, если хотите продолжить введите 0: ";
		int choice = input();
		if (choice == 1) {
			saveGame(player_matrix, size, moves);
			return;
		}
		else if (choice != 0 && choice != 1) {
			cout << "Ошибка. Некорректный ввод." << endl;
		}
	}
	cout << "\x1b[33mВаш квадрат:\x1b[0m " << endl;
	outputMatrix(player_matrix);
	cout << "\x1b[33mПроверим, магический ли он...\x1b[0m" << endl;
	if (checkCorrectSquare(player_matrix, size)) {
		cout << "\x1b[33mДа, этот квадрат магический,\x1b[0m \x1b[32mвы победили!\x1b[0m" << endl;
	}
	else {
		cout << "\x1b[33mУпс, этот квадрат не магический, вы проиграли\x1b[0m" << endl;
		cout << "\x1b[33mИскомая сумма была равна\x1b[0m ";
		outputSumm(matrix);
	}
	saveGame(player_matrix, size, moves);
}
void loadGame() {
	int size = 3;
	vector<vector<int>> player_matrix(size, vector<int>(size));
	vector<int> moves;
	string file_name;
	cout << "Введите название сохранения (название файла): ";
	cin >> file_name;
	player_matrix = loadFromFileMatrix(player_matrix, file_name);
	moves = loadFromFileMoves(moves, file_name);
	while (!testEndGame(player_matrix, moves)) {
		outputMatrix(player_matrix);
		outputVector(moves);
		playersMove(player_matrix, moves);
		cout << "\x1b[33mХод сделан.\x1b[0m" << endl;
		cout << "Если вы хотите сохранить игру, введите 1, если хотите продолжить введите 0: ";
		int choice = input();
		if (choice == 1) {
			saveGame(player_matrix, size, moves);
			return;
		}
		else if (choice != 0 && choice != 1) {
			cout << "Ошибка. Некорректный ввод." << endl;
		}
	}
	cout << "\x1b[33mВаш квадрат:\x1b[0m " << endl;
	outputMatrix(player_matrix);
	cout << "\x1b[33mПроверим, магический ли он...\x1b[0m" << endl;
	if (checkCorrectSquare(player_matrix, size)) {
		cout << "\x1b[33mДа, этот квадрат магический,\x1b[0m \x1b[32mвы победили!\x1b[0m" << endl;
	}
	else {
		cout << "\x1b[33mУпс, этот квадрат не магический, вы проиграли\x1b[0m" << endl;
	}
	saveGame(player_matrix, size, moves);
}
void saveGame(vector <vector <int>> player_matrix, int size, vector <int> moves) {
	int choice = 0;
	cout << "\x1b[33Хотите ли вы сохранить игру?\n1 - Да\n2 - Нет\x1b[0m" << endl;
	cout << "\x1b[33Выбор: \x1b[0m";
	choice = input();
	if (choice == 1) {
		outputToFile(player_matrix, size, moves);
	}
	else if (choice == 2) {
		return;
	}
	else {
		cout << "Некорректный выбор." << endl;
		saveGame(player_matrix, size, moves);
	}

}