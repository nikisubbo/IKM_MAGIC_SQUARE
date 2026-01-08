#include "Header.h"
#include <iostream>
#include <vector>
int generationSquare() {
	cout << "Идет генерация магического квадрата..." << endl;
	int matrix_size = 0;
	cout << "Сколько будет чисел в строках и столбцах магического квадрата?" << endl;
	cout << "Введите целое число: ";
	cin >> matrix_size;
	vector <int> matrix(2, matrix_size);
	return 1;
}