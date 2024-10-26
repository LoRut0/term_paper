#include "Guard.h"

//base

bool Guard::ch_name()
{
	std::cout << "¬ведите им€: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};

bool  Guard::ch_surname()
{
	std::cout << "¬ведите фамилию: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};

bool Guard::ch_patronymic()
{
	std::cout << "¬ведите отчество: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 0;
};

void Guard::ch_salary(double slry)
{
	salary = slry;
};


std::array<std::string, 3> Guard::get_fullname()
{
	return full_name;
};

int Guard::get_salary()
{
	return salary;
};

bool Guard::ch_birthday()
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year chrono_current_year = std::chrono::year_month_day{ floor<std::chrono::days>(now) }.year();
	int current_year = static_cast<int>(chrono_current_year);

	std::cout << "¬ведите день рождени€: ";
	std::string temp = Input::date(1900, current_year - 14, 1);
	if (temp == "\n") return 1;
	std::string date[3];

	date[0].push_back(temp[0]);
	date[0].push_back(temp[1]);
	date[1].push_back(temp[3]);
	date[1].push_back(temp[4]);
	date[2].push_back(temp[6]);
	date[2].push_back(temp[7]);
	date[2].push_back(temp[8]);
	date[2].push_back(temp[9]);

	birthday[0] = std::stoi(date[0]);
	birthday[1] = std::stoi(date[1]);
	birthday[2] = std::stoi(date[2]);
	return 0;
};

std::array<int, 3> Guard::get_birthday()
{
	return birthday;
};

Guard::Guard(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::string weapon, int input_shift)
{
	this->full_name = full_name;
	salary = 1;
	birthday = input_birthday;
	this->weapon = weapon;
	shift = input_shift;
};

Guard::Guard()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;
	shift = 0;

	birthday = { 0,0,0 };
};

//base


std::string Guard::get_weapon() {
	return weapon;
}

bool Guard::ch_weapon() {
	std::cout << "¬ведите спец. средство охранника: ";
	std::string new_weapon = Input::str(25);
	if (new_weapon == "\n") return 1;
	weapon = new_weapon;
	return 0;
}

int Guard::get_shift() {
	return shift;
}

bool Guard::ch_shift() {
	std::cout << "(1) 22:00-06:00, (2) 06:00-14:00 (3) 14:00-22:00\n¬ведите смену охранника: ";
	int new_shift = Input::int_(1, 3);
	if (new_shift == INT_MIN) return 1;
	shift = new_shift;
	return 0;
}