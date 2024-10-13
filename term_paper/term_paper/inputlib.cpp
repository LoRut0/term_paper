#pragma once
#include "inputlib.h"
#include "private.h"


int Input::int_(int min, int max)
{
	if (min > max) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	if ((min < INT_MIN / 10) or (max > INT_MAX / 10)) {
		std::cout << "\nERROR: invalid min or max" << std::endl;
		abort();
	}
	int case_event = event(min, max);
	std::string future_number{};
	int get;
	while (true)
	{
		get = _getch();
		if (isdigit(get))
		{
			if (size_check(future_number + char(get), min, max, case_event))
			{
				continue;
			}
			future_number.push_back(char(get));
			std::cout << char(get);
		}
		if ((get == 45) and (future_number.length() == 0) and (min < 0))
		{
			future_number.push_back('-');
			std::cout << char(get);
		}
		if (get == 8) back(future_number);
		if (get == 27) return INT_MIN;
		if (get == 13) {
			if ((future_number.empty()) or (std::stoi(future_number) > max) or (std::stoi(future_number) < min)) continue;
			std::cout << std::endl;
			return std::stoi(future_number);
		}
	}
}

int Input::choice(int min, int max, int esc_return)
{
	if (min > max) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	if (min < 0) {
		std::cout << "\nERROR: min cant be less than 0" << std::endl;
		abort();
	}
	if (max > 9) {
		std::cout << "\nERROR: max cant be more than 9" << std::endl;
		abort();
	}
	min += 48; max += 48;
	int get;
	while (true)
	{
		get = _getch();
		if (isdigit(get))
		{
			if ((get > max) or (get < min))
			{
				continue;
			}
			return int(get) - 48; //Коды цифр начинаются с 48
		}
		if (get == 27) return esc_return;
	}
}

double Input::double_(double min, double max)
{
	if (min > max) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	int case_event = event(min, max);
	std::string future_number{};
	int get;
	while (true)
	{
		get = _getch();
		if (isdigit(get))
		{
			if (size_check(future_number + char(get), min, max, case_event))
			{
				continue;
			}
			future_number.push_back(char(get));
			std::cout << char(get);
		}
		if ((get == 45) and (future_number.length() == 0) and (min < 0))
		{
			future_number.push_back('-');
			std::cout << char(get);
		}
		if ((get == '.') and (future_number.find(',') == std::string::npos) and (((future_number.length() >= 1) and
			(future_number[0] != '-')) or (future_number.length() >= 2))) {
			future_number.push_back(',');
			std::cout << char(get);
		}
		if (get == 8) back(future_number);
		if (get == 27) return DBL_MIN;
		if (get == 13) {
			if ((future_number.empty()) or (std::stod(future_number) > max) or (std::stod(future_number) < min)) continue;
			std::cout << std::endl;
			return std::stod(future_number);
		}
	}
}

bool Input::bool_(char lie, char truth)
{
	int get;
	while (true)
	{
		get = _getch();
		if (get == truth) return true;
		if (get == lie) return false;
	}
}

std::string Input::str(int max_len, int min_len) {
	std::string future_string{};
	int get;
	while (true)
	{
		get = _getch();
		if (isalpha(get) or isdigit(get))
		{
			if (future_string.length() >= max_len)
			{
				continue;
			}
			future_string.push_back(char(get));
			std::cout << char(get);
		}
		if (get == 8) back(future_string);
		if (get == 27) return "\n";
		if (get == 13)
		{
			if (future_string.length() >= min_len) {
				std::cout << std::endl;
				return future_string;
			}
		}
	}
}

std::string Input::name(int max_len, int min_len) {
	if (min_len > max_len) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	std::string future_string{};
	int get;
	while (true)
	{
		get = _getch();
		if (isalpha(get))
		{
			if ((future_string.length() == 0) && (!isupper(get))) {
				future_string.push_back(toupper(char(get)));
				std::cout << toupper(char(get));
				continue;
			}
			if (future_string.length() >= max_len) continue;
			future_string.push_back(char(get));
			std::cout << char(get);
		}
		if (get == 8) back(future_string);
		if (get == 27) return "\n";
		if (get == 13)
		{
			if (future_string.length() >= min_len) {
				std::cout << std::endl;
				return future_string;
			}
		}
	}
}

int Input::int_rand(int min, int max) {
	std::random_device RandomDevice;
	unsigned seed = RandomDevice();
	std::default_random_engine RandomEngine(seed);
	std::uniform_int_distribution<int> Border(min, max);
	return Border(RandomEngine);
}

double Input::double_rand(double min, double max) {
	std::random_device RandomDevice;
	unsigned seed = RandomDevice();
	std::default_random_engine RandomEngine(seed);
	std::uniform_real_distribution<double> Border(min, max);
	return Border(RandomEngine);
}

std::string Input::date(unsigned min_year, unsigned max_year)
{
	if (min_year > max_year) {
		std::cout << "\nERROR: min > max" << std::endl;
		abort();
	}
	std::string future_string{};
	int get;
	std::string date[3];
	while (true)
	{
		get = _getch();
		if (isdigit(get))
		{
			if ((future_string.length() == 2) or (future_string.length() == 5) or (future_string.length() == 10))
			{
				continue;
			}
			future_string.push_back(char(get));
			std::cout << char(get);
		}
		if ((future_string.length() == 2) or (future_string.length() == 5))
		{
			std::cout << '.';
			future_string.push_back('.');
		}
		if (get == 8)
		{
			if ((future_string.length() == 3) or (future_string.length() == 6)) back(future_string);
			back(future_string);
		}
		if (get == 27) return "\n";
		if (get == 13)
		{
			if (future_string.length() != 10) continue; //Если длина не 10, то в начало
			//
			date[0].push_back(future_string[0]);
			date[0].push_back(future_string[1]);
			date[1].push_back(future_string[3]);
			date[1].push_back(future_string[4]);
			date[2].push_back(future_string[6]);
			date[2].push_back(future_string[7]);
			date[2].push_back(future_string[8]);
			date[2].push_back(future_string[9]);

			if (!isValidDate(std::stoi(date[0]), std::stoi(date[1]), std::stoi(date[2]), min_year, max_year))
			{
				date[0] = "";
				date[1] = "";
				date[2] = "";
				continue; //Если дата не валидна, то в начало
			}

			std::cout << std::endl;
			return future_string;
		}
	}
}