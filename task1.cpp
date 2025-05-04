#include <iostream>
#include <fstream>
#include <string>
#include "task1.h"
#include "utils.h"

using namespace std;

// Функція для виконання першого завдання
void task1() {
    // Отримання введеного рядка від користувача
    string str;
    cout << "Введіть рядок: ";
    getline(cin, str);

    // Копіюємо рядок у масив символів для роботи з ним через C-рядки
    char c_str[256];
    strncpy(c_str, str.c_str(), sizeof(c_str));
    c_str[sizeof(c_str) - 1] = '\0'; // Завжди ставимо завершальний нуль

    size_t pos, len;
    string repl;

    // Отримуємо параметри для заміни
    cout << "Введіть позицію для заміни: ";
    cin >> pos;
    cout << "Введіть довжину для заміни: ";
    cin >> len;
    cin.ignore(); // Очищаємо буфер перед введенням рядка
    cout << "Введіть рядок для вставки: ";
    getline(cin, repl);

    // Стандартний метод заміни за допомогою string::replace
    string str_copy = str;
    if (pos <= str_copy.length())
        str_copy.replace(pos, len, repl);
    cout << "Результат string::replace: " << str_copy << endl;

    // Власна реалізація заміни через масив символів
    my_replace(c_str, pos, len, repl.c_str());
    cout << "Результат my_replace: " << c_str << endl;

    // Запис результату заміни в файл
    ofstream result_file("task1_output.txt", ios::app);
    if (result_file) {
        result_file << "Рядок: " << str << "\nРезультат заміни: " << c_str << endl;
        result_file.close();
    } else {
        cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
    }
}
