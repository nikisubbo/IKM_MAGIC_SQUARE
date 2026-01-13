#include <iostream>
#include "Header.h"
#include <string>
int main() {
    setlocale(LC_ALL, "");
    int choice = 0;

    cout << "Добро пожаловать в игру << Магический квадрат >> " << endl;
    cout << "Правила игры:\nВам дана таблица, в ней 3 числа, и возможные ходы, состоящие из чисел\nВам нужно вставить эти числа так, чтобы сумма по строкам, столбцам и диагоналям была равна одному и тому же числу, удачной игры!" << endl;
    string menu_message = "Меню:\n1) Начать игру\n2) Загрузить игру\n3) Выйти из игры\nВведите номер выбранного пункта меню: ";
    cout << menu_message;
    choice = input();
    while (choice != 3) {
        if (choice < 1 || choice > 3) {
            cout << "Ошибка. Некорректный ввод, попробуйте еще раз: " << endl;
        }
        else {
            switch (choice) {
            case 1:
                newGame();
                break;
            case 2:
                loadGame();
                break;
            }
        }
        cout << menu_message;
        choice = input();
    }
    cout << "Завершение работы..." << endl;
    return 0;
}