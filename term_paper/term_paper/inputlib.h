#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <random>
#include <array>


namespace Input 
{

	//Ввод int, min <= int <= max
	int int_(int min = INT_MIN / 10, int max = INT_MAX / 10);
	//Возвращает случайный int, min <= int <= max
	int int_rand(int min = INT_MIN, int max = INT_MAX);

	//Выбор для менюшек, моментально считывает цифру, которую нажал пользователь в диапозоне от min до max, при нажатии esc возвращает esc_return (-1 по дефолту)
	int choice(int min = 0, int max = 9, int esc_return = -1);
	//
	bool bool_(char lie = '0', char truth = '1');

	//Ввод double, min <= double <= max
	double double_(double min = ((DBL_MAX / 10) * -1), double max = (DBL_MAX / 10));
	//Возвращает случайный double, min <= double <= max
	double double_rand(double min = DBL_MIN, double max = DBL_MAX);

	//Ввод строки, min_len <= длина <= max_len (для ввода доступны только буквы и цифры)
	std::string str(int max_len, int min_len = 1);
	//Ввод строки, min_len <= длина <= max_len (для ввода доступны только буквы, первая буква всегда заглавная)
	std::string name(int max_len, int min_len = 1);

	//Ввод даты, min_year <= год <= max_year
	std::string date(unsigned min_year = 0, unsigned max_year = 9999, bool esc = 0);

}