#include <iostream>
#include <fstream>
#include <string>
#include "task2.h"
#include "utils.h"

using namespace std;

// Функція для виконання другого завдання
void task2() {
    string line;
    cout << "Введіть рядок для підрахунку слів: ";
    getline(cin, line);

    // Підрахунок кількості слів у рядку
    int count = count_words(line);
    cout << "Кількість слів: " << count << endl;

    // Запис результату підрахунку в файл
    ofstream result_file("task2_output.txt", ios::app);
    if (result_file) {
        result_file << "Рядок: " << line << "\nКількість слів: " << count << endl;
        result_file.close();
    } else {
        cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
    }
}
