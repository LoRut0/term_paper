#include "Electrician.h"

//base

bool Electrician::ch_name()
{
	std::cout << "¬ведите им€: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};
bool  Electrician::ch_surname()
{
	std::cout << "¬ведите фамилию: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};
bool Electrician::ch_patronymic()
{
	std::cout << "¬ведите отчество: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 0;
};
std::array<std::string, 3> Electrician::get_fullname()
{
	return full_name;
};

void Electrician::ch_salary(double slry)
{
	salary = slry;
};
double Electrician::get_salary()
{
	return salary;
};

bool Electrician::ch_birthday()
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

std::array<int, 3> Electrician::get_birthday()
{
	return birthday;
};

Electrician::Electrician(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, int cat) : 
	full_name(full_name), salary(1), salary_rate(1), birthday(input_birthday), category(cat) 
{
};

Electrician::Electrician()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;
	salary_rate = -1;

	birthday = { 0,0,0 };
	category = 0;
};
//base

int Electrician::get_category() {
	return category;
}

bool Electrician::ch_category() {
	std::cout << "¬ведите разр€д электрика (1-6): ";
	int new_cat = Input::int_(1, 6);
	if (new_cat == INT_MIN) return 1;
	category = new_cat;
	return 0;
}

//int Electrician::get_height_cat() {
//	return height_cat;
//}
//
//void Electrician::ch_height_cat() {
//	std::cout << "ƒл€ отмены нажмите esc\n¬ведите группу допуска электрика на высотные работы (1-3): ";
//	int new_height_cat = Input::int_(1, 3);
//	if (new_height_cat == INT_MIN) return;
//	height_cat = new_height_cat;
//}