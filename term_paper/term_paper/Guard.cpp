#include "Guard.h"

//base

void Guard::ch_name()
{
	std::cout << "Enter name: ";
	full_name[0] = Input::name(25);
};

void  Guard::ch_surname()
{
	std::cout << "Enter surname: ";
	full_name[1] = Input::name(25);
};

void Guard::ch_patronymic()
{
	std::cout << "Enter patronymic: ";
	full_name[2] = Input::name(25);
};

void Guard::ch_salary()
{
	std::cout << "Enter salary: ";
	salary = Input::int_(10);
};


std::array<std::string, 3> Guard::get_fullname()
{
	return full_name;
};

int Guard::get_salary()
{
	return salary;
};

void Guard::ch_birthday()
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year chrono_current_year = std::chrono::year_month_day{ floor<std::chrono::days>(now) }.year();
	int current_year = static_cast<int>(chrono_current_year);

	std::string temp = Input::date(1900, current_year);
	std::string date[3];

	date[0].push_back(temp[0]);
	date[0].push_back(temp[1]);
	date[1].push_back(temp[3]);
	date[1].push_back(temp[4]);
	date[2].push_back(temp[6]);
	date[2].push_back(temp[7]);
	date[2].push_back(temp[8]);
	date[2].push_back(temp[9]);

	birthday[0] = std::stoi(date[2]);
	birthday[1] = std::stoi(date[1]);
	birthday[2] = std::stoi(date[0]);
};

std::array<int, 3> Guard::get_birthday()
{
	return birthday;
};

Guard::Guard(std::string name, std::string surname, std::string patronymic, int slry)
{
	full_name[0] = name;
	full_name[1] = surname;
	full_name[2] = patronymic;
	salary = slry;

	birthday = { 0,0,0 };
};

Guard::Guard()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;

	birthday = { 0,0,0 };
};

//base


std::string Guard::get_weapon() {
	return weapon;
}

void Guard::ch_weapon() {
	std::cout << "Для отмены нажмите esc\nВведите спец. средство охранника: ";
	std::string new_weapon = Input::str(100);
	if (new_weapon == "\n") return;
	weapon = new_weapon;
}