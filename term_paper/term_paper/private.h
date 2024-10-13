#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <random>
#include <array>

//Смещение курсора назад с удалением символа
void back(std::string& str);

//Ивенты нужны для определения присутствия 0, тк если мин будет больше 0, первая проверка на минимум не должна оказаться неуспешной, иначе пользователь не сможет ничего написать)
int event(int min, int max);
//Ивенты нужны для определения присутствия 0, тк если мин будет больше 0, первая проверка на минимум не должна оказаться неуспешной, иначе пользователь не сможет ничего написать)
int event(double min, double max);

//Если проверка успешна, то число достигло максимума/минимума для int
bool size_check(std::string number, int min, int max, int event);
//Если проверка успешна, то число достигло максимума/минимума для double
bool size_check(std::string number, double min, double max, int event);

//Проверка существования даты
bool isValidDate(int day, int month, int year, int min_year, int max_year);