#include <iostream>
#include "Header.h"
int main() {
	int choice;
	setlocale(LC_ALL, "");
	cout << "Добро пожаловать в <<Машический квадрат>>" << endl;
	cout << "1 - Генерация Магического квадрата нечётного порядка\n2 - Проверка корректности" << endl;
	cout << "3 - Вывод сумм строк, столбцов, диагоналей\n4 - Проверка уникальности чисел" << endl;
	cout << "5 - Вывод в файл\n0 - Выход\nВыбор: ";
	cin >> choice;
	while (choice != 0) {
		if (choice >= 1 && choice <= 5) {
			switch (choice) {
			case 1: generationSquare();
				break;
			case 2: checkCorrectSquare();
				break;
			case 3: outputSumm();
				break;
			case 4: checkUniqueness();
				break;
			case 5: outputInFile();
				break;
			}
			cout << "1 - Генерация Магического квадрата нечётного порядка\n2 - Проверка корректности" << endl;
			cout << "3 - Вывод сумм строк, столбцов, диагоналей\n4 - Проверка уникальности чисел" << endl;
			cout << "5 - Вывод в файл\n0 - Выход\nВыбор: ";
			cin >> choice;
		}
		else {
			cout << "Некорректный ввод, попробуйте снова ввести НОМЕР нужного ПУНКТА" << endl;
			cout << "Выбор: ";
			cin >> choice;
		}
	}
	cout << "Завершение работы...";
	return 0;
}