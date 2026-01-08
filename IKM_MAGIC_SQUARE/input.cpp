#include "Header.h"
#include <iostream>
#include <string>
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