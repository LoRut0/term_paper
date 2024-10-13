#pragma once
#include "private.h"

void back(std::string& str)
{
	if (!str.empty()) {
		std::cout << '\b' << ' ' << '\b';
		str.pop_back();
	}
}

int event(int min, int max)
{
	if (min > 0) return 1;
	else if (max < 0) return 2;
	return 0;
}

int event(double min, double max)
{
	if (min > 0) return 1;
	else if (max < 0) return 2;
	return 0;
}

bool size_check(std::string number, int min, int max, int event)
{
	switch (event)
	{
	case 1:
		if ((std::stoi(number) < 0) or (std::stoi(number) > max)) return true;
		break;
	case 2:
		if ((std::stoi(number) > 0) or (std::stoi(number) < min)) return true;
		break;
	case 0:
		if ((std::stoi(number) > max) or (std::stoi(number) < min)) return true;
		break;
	default:
		break;
	}
	return false;
}

bool size_check(std::string number, double min, double max, int event)
{
	switch (event)
	{
	case 1:
		if ((std::stod(number) < 0) or (std::stod(number) > max)) return true;
		break;
	case 2:
		if ((std::stod(number) > 0) or (std::stod(number) < min)) return true;
		break;
	case 0:
		if ((std::stod(number) > max) or (std::stod(number) < min)) return true;
		break;
	default:
		break;
	}
	return false;
}

//Проверка существования даты
bool isValidDate(int day, int month, int year, int min_year, int max_year) {
	// Проверка корректности года
	if (year < min_year || year > max_year) {
		return false;
	}

	// Проверка корректности месяца
	if (month < 1 || month > 12) {
		return false;
	}

	// Проверка корректности дня
	// Количество дней в месяце
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Високосный год
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	// Если февраль и год високосный, добавляем день
	if (isLeapYear && month == 2) {
		daysInMonth[1] = 29;
	}

	// Проверка на допустимость дня в данном месяце
	if (day < 1 || day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}