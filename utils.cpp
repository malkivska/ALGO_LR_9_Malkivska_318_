#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "utils.h"

using namespace std;

// Реалізація свого методу заміни частини рядка
void my_replace(char* str, size_t pos, size_t len, const char* repl) {
    size_t i = 0;
    // Замінюємо символи в рядку відповідно до заданих параметрів
    while (repl[i] != '\0' && i < len && pos + i < strlen(str)) {
        str[pos + i] = repl[i];
        i++;
    }
}

// Підрахунок слів у рядку
int count_words(const string& str) {
    int count = 0;
    bool in_word = false;

    // Перебір символів рядка для визначення меж слів
    for (char ch : str) {
        if (ch != ' ') {
            if (!in_word) {
                in_word = true;
                count++; // Збільшуємо кількість слів
            }
        } else {
            in_word = false; // Кінець слова
        }
    }

    return count;
}

// Перевірка рядка на наявність лише допустимих символів
bool is_valid(const string& str) {
    for (char ch : str) {
        // Якщо символ не є буквою, цифрою або пропуском, рядок недопустимий
        if (!(isalpha((unsigned char)ch) || isdigit((unsigned char)ch) || ch == ' ' || ch == '_'))
            return false;
    }
    return true;
}

// Створення текстового файлу з 10 рядками для тестування
void create_sample_file() {
    ofstream file("sample.txt");
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    // Записуємо тестові рядки
    file << "привіт світ" << endl;
    file << "я люблю програмування" << endl;
    file << "це тестовий рядок" << endl;
    file << "штучний інтелект змінює світ" << endl;
    file << "це п’ята стрічка" << endl;
    file << "ми вивчаємо C++" << endl;
    file << "КХАІ найкращий" << endl;
    file << "лабораторна робота" << endl;
    file << "треба рахувати слова" << endl;
    file << "остання стрічка" << endl;
    file.close();
}

// Обробка текстового файлу рядок за рядком
void process_file() {
    ifstream file("sample.txt");
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    ofstream out("output.txt");
    if (!out) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    string line;
    // Читаємо файл по рядку
    while (getline(file, line)) {
        if (is_valid(line)) {
            // Якщо рядок допустимий, підраховуємо слова
            int count = count_words(line);
            out << "Рядок: \"" << line << "\" має " << count << " слів." << endl;
        } else {
            out << "Рядок \"" << line << "\" недопустимий." << endl;
        }
    }

    file.close();
    out.close();
}
