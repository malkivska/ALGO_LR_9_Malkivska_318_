#ifndef UTILS_H
#define UTILS_H

#include <string>

// Оголошення функцій для обробки рядків та файлів
void my_replace(char* str, size_t pos, size_t len, const char* repl);
int count_words(const std::string& str);
bool is_valid(const std::string& str);
void create_sample_file();
void process_file();

#endif
