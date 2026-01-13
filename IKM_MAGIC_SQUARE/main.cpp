#include <iostream>
#include "Header.h"
#include <string>
int main() {
	setlocale(LC_ALL, "");
	int choice = 0; 
	cout << "Добро пожаловать в игру << Магический квадрат >> " << endl;
	string menu_massage = "Меню:\n1) Начать игру\n2) Загрузить игру\n3) Выйти из игры\nВведите номер выбранно пункта меню: ";
	cout << menu_massage;
	choice = input();
	if (choice <= 0) {
		cout << "Введено некорректное число." << endl;
		main();
	}
	while (choice != 3) {
		if (choice < 3) {
			switch (choice) {
			case 1: newGame();
				break;
			case 2: loadGame();
				break;
			}
			cout << menu_massage;
			choice = input();
		}
		else {
			cout << "Ошибка! Некорректный ввод, попробуйте еще раз: ";
			choice = input();
		}
	}
	cout << "Завершение работы...";
	return 0;
}