#include "Header.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
#include <fstream>
void outputToFile(vector <vector<int>> player_matrix, int size, vector <int> moves) {//Сохранение матрицы в файл
	string file_name;
	cout << "Введите название сохранения (название файла): ";//игроку нужно ввести только название сохранение, расширение файла вставляется автоматически
	cin >> file_name;
	string file_name_matrix = "D:\\Programming\\repos\\IKM_MAGIC_SQUARE\\IKM_MAGIC_SQUARE\\x64\\Debug\\" + file_name + "_matrix" + ".txt";
	cout << file_name_matrix;
	ofstream file(file_name_matrix);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file << player_matrix[i][j] << " "; //запись в файл всей матрицы
		}
		file << endl;
	}
	file.close();
	string file_name_moves = file_name;//отдельный файл для хранения ходов, новое название игроку вводить не надо, так как каждому файлу добавляется префикс с тем, что он хранит
	file_name_moves = "D:\\Programming\\repos\\IKM_MAGIC_SQUARE\\IKM_MAGIC_SQUARE\\x64\\Debug\\" + file_name_moves + "_moves" + ".txt";
	ofstream file_(file_name_moves);
	for (int i = 0; i < moves.size(); i++) { 
		file_ << moves[i] << "  ";
	}
}
vector<vector<int>> loadFromFileMatrix(vector<vector<int>> player_matrix, string file_name) {//загрузка матрицы игрового поля из файла
	string file_name_matrix = file_name;
	file_name_matrix = "D:\\Programming\\repos\\IKM_MAGIC_SQUARE\\IKM_MAGIC_SQUARE\\x64\\Debug\\" + file_name_matrix + "_matrix" + ".txt";
	ifstream file(file_name_matrix);
	for (int i = 0; i < player_matrix.size(); i++) {
		for (int j = 0; j < player_matrix.size(); j++) {
			file >> player_matrix[i][j];
		}

	}
	return player_matrix;
}
vector<int> loadFromFileMoves(vector<int> moves, string file_name) {//загрузка вектора ходов из файла
	string file_name_moves = file_name;
	file_name_moves = "D:\\Programming\\repos\\IKM_MAGIC_SQUARE\\IKM_MAGIC_SQUARE\\x64\\Debug\\" + file_name_moves + "_moves" + ".txt";
	ifstream file(file_name_moves);
	int move;
	while (file >> move) {
		moves.push_back(move);
	}
	return moves;
}