#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
vector<vector<int>> generationSquare(vector<vector<int>> matrix, int size, int center_num) {//сиамский метод генерации, о том как он работает можно узнать здесь:https://stepik.org/lesson/441778/step/4
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
vector<vector<int>> generationPlayersSquare(vector<vector<int>> matrix, int size){
	vector < vector <int> > player_matrix1(size, vector <int>(size));
	srand(time(0));
	int column_one = rand() % size; //выбираем рандомно строку и столбец, куда будем заносить 3 числа из сгенерированного маг. квадрта
	int line_one = rand() % size;
	int column_two = rand() % size;
	int line_two = rand() % size;
	int column_three = rand() % size;
	int line_three = rand() % size;
	player_matrix1[line_one][column_one] = matrix[line_one][column_one];
	player_matrix1[line_two][column_two] = matrix[line_two][column_two];
	player_matrix1[line_three][column_three] = matrix[line_three][column_three];//вставляем эти числа в эти ячейки матрицы, которая будет показываться пользователю.
	return player_matrix1;
	}
bool checkCorrectSquare(vector<vector<int>> matrix, int size) { //условие магического квадрата
	int summa = 0;
	for (int i = 0; i < size; i++) { //проверка суммы в 1-ой строке, будем сравнивать с ней все остальные суммы
		summa += matrix[0][i];
	}
	for (int i = 0; i < size; i++) {
		int temp_summ = 0;
		for (int j = 0; j < size; j++) {
			temp_summ += matrix[i][j]; //подсчет суммы по строкам
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	for (int j = 0; j < size; j++) {
		int temp_summ = 0;
		for (int i = 0; i < size; i++) {
			temp_summ += matrix[i][j]; //подсчет суммы по столбцам
		}
		if (temp_summ != summa) {
			return false;
		}
	}
	int temp_sum1 = 0;
	int temp_sum2 = 0;
	for (int i = 0; i < size; i++) {
		temp_sum1 += matrix[i][i]; //подсчет суммы по диагоналям 
		temp_sum2 += matrix[i][2 - i];
	}
	if (temp_sum1 != summa || temp_sum2 != summa) {
		return false;
	}
	return true;
}
vector <int> possibleMoves(vector<vector<int>> matrix, vector<vector<int>> player_matrix, int size) {//вычисление возможных ходов игрока
	vector <int> moves;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != player_matrix[i][j]) {//сравниваем значения в исходном квадрате и квадрате игрока
				moves.push_back(matrix[i][j]);
			}
		}
	}
	//Возможность добавить перемешивание ходов
	//shuffle(moves.begin(), moves.end(), default_random_engine rand_pos(time(0))); 
	return moves;
}
bool testEndGame(vector<vector<int>> player_matrix, vector <int> moves) {//проверка на окончание игры, игра окончена когда ходов больше нет
	if (moves.size() == 0) {
		return 1;
	}
	else {
		return 0;
	}
}