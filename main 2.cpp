#include <iostream>
#include "task1.h"
#include "task2.h"

using namespace std;

int main() {
    create_sample_file(); // Створюємо файл з тестовими рядками

    int choice;
    do {
        // Меню для вибору завдання
        cout << "\n1. Замінити частину рядка (task1)\n";
        cout << "2. Порахувати кількість слів у введеному рядку (task2)\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // очищуємо буфер перед введенням

        switch (choice) {
            case 1:
                task1(); // Виклик першого завдання
                break;
            case 2:
                task2(); // Виклик другого завдання
                break;
            case 0:
                cout << "Вихід..." << endl;
                break;
            default:
                cout << "Невірний вибір!" << endl; // Невірний вибір
        }

    } while (choice != 0);

    return 0;
}
