#include <iostream>
#include "Header.h"
int main() {
	int choice;
	setlocale(LC_ALL, "");
	std::cout << "Добро пожаловать в <<Магический квадрат>>." << std::endl;
	std::cout << "Меню." << std::endl;
	std::cout << "1 - Генерация Магического квадрата нечётного порядка\n2 - Проверка корректности" << std::endl;
	std::cout << "3 - Вывод сумм строк, столбцов, диагоналей\n4 - Проверка уникальности чисел" << std::endl;
	std::cout << "5 - Вывод в файл\n0 - Выход\nВыбор: ";
	std::cin >> choice;
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
			std::cout << "1 - Генерация Магического квадрата нечётного порядка\n2 - Проверка корректности" << std::endl;
			std::cout << "3 - Вывод сумм строк, столбцов, диагоналей\n4 - Проверка уникальности чисел" << std::endl;
			std::cout << "5 - Вывод в файл\n0 - Выход\nВыбор: ";
			std::cin >> choice;
		}
		else {
			std::cout << "Некорректный ввод, попробуйте снова ввести НОМЕР нужного ПУНКТА" << std::endl;
			std::cout << "Выбор: ";
			std::cin >> choice;
		}
	}
	std::cout << "Завершение работы...";
	return 0;
}