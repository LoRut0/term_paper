#include "Director.h"

//BASE
bool Director::ch_name()
{
	std::cout << "Введите имя: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};
bool  Director::ch_surname()
{
	std::cout << "Введите фамилию: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};
bool Director::ch_patronymic()
{
	std::cout << "Введите отчество: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 0;
};

bool Director::ch_salary_rate(double slry_rate) {
	std::cout << "Введите ставку: ";
	double temp = Input::double_(0.01, 1, 2);
	if (temp == DBL_MIN) return 1;
	salary_rate = temp;
	return 0;
}
double Director::get_salary_rate() {
	return salary_rate;
}

std::array<std::string, 3> Director::get_fullname()
{
	return full_name;
};

void Director::ch_salary(double slry)
{
	salary = slry;
};
int Director::get_salary()
{
	return salary;
};

bool Director::ch_birthday()
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year chrono_current_year = std::chrono::year_month_day{ floor<std::chrono::days>(now) }.year();
	int current_year = static_cast<int>(chrono_current_year);

	std::cout << "Введите день рождения: ";
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
std::array<int, 3> Director::get_birthday()
{
	return birthday;
};

Director::Director(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::string comp_name)
{
	this->full_name = full_name;
	salary = 1;
	
	birthday = input_birthday;
	company_name = comp_name;

	electricians = new std::vector<Electrician>;
	guards = new std::vector<Guard>;
	secretary = NULL;
	accountant = NULL;
};

Director::~Director() 
{
	delete electricians;
	delete guards;
	delete secretary;
	delete accountant;
}
//BASE

void Director::fire_employers() 
{
	bool flag(true);
	while (flag)
	{
		system("cls");
		print_employers();
		std::cout << "(Esc) Назад\n(1) Уволить секретаря\n(2) Уволить бухгалтера\n(3) Уволить охранника\n(4) Уволить электрика" << std::endl;
		int choice = Input::choice();

		switch (choice)
		{
		case 1: {
			if (!secretary) break;
			std::cout << "Подтвердите увольнение секретаря (1) - Да, (0) - Нет" << std::endl;
			if (Input::bool_('0', '1') and secretary) secretary = NULL;
			break;
		}
		case 2: {
			if (!accountant) break;
			std::cout << "Подтвердите увольнение бухгалтера (1) - Да, (0) - Нет" << std::endl;
			if (Input::bool_('0', '1') and accountant) {
				accountant = NULL;
				if (secretary) secretary->pnt_initialization(electricians, guards, accountant);
			}
			break;
		}
		case 3: {
			if ((*guards).size() == 0) break;
			std::cout << "Введите номер охранника, которого хотите уволить: ";
			int number = Input::int_(1, (*guards).size());
			if (number == INT_MIN) break;

			std::cout << "Подтвердите увольнение охранника " << number-- << " (1) - Да, (0) - Нет" << std::endl;
			if (Input::bool_('0', '1')) (*guards).erase((*guards).begin() + number);
			break;
		}
		case 4: {
			if ((*electricians).size() == 0) break;
			std::cout << "Введите номер электрика, которого хотите уволить: ";
			int number = Input::int_(1, (*electricians).size());
			if (number == INT_MIN) break;

			std::cout << "Подтвердите увольнение электрика " << number-- << " (1) - Да, (0) - Нет" << std::endl;
			if (Input::bool_('0', '1')) (*electricians).erase((*electricians).begin() + number);
			break;
		}
		case -1:
			flag = false;
			break;
		default:
			break;
		}
	}
}
void Director::hire_employers()
{
	bool flag(true);
	while (flag)
	{
		system("cls");
		print_employers();
		int choice;
		if (secretary and accountant) {
			std::cout << "(Esc) Назад\n(1) Нанять секретаря\n(2) Нанять бухгалтера\n(3) Нанять охранника\n(4) Нанять электрика" << std::endl;
			choice = Input::choice(1, 4);
		}
		else {
			std::cout << "(Esc) Назад\n(1) Нанять секретаря\n(2) Нанять бухгалтера\n" << std::endl;
			choice = Input::choice(1, 2);
		}

		switch (choice)
		{
		case 1: {
			if (secretary) {
				std::cout << "Нельзя нанять 2 секретаря" << std::endl;
				system("pause");
				break;
			}
			Secretary* new_secretary = new Secretary;
			if (new_secretary->ch_name()) break;
			if (new_secretary->ch_surname()) break;
			if (new_secretary->ch_patronymic()) break;
			if (new_secretary->ch_birthday()) break;
			new_secretary->change_languages();

			secretary = new_secretary;
			secretary->pnt_initialization(electricians, guards, accountant);
			break;
		}
		case 2: {
			if (accountant) {
				std::cout << "Нельзя нанять 2 бухгалтера" << std::endl;
				system("pause");
				break;
			}
			Accountant* new_accountant = new Accountant;
			if (new_accountant->ch_name()) break;
			if (new_accountant->ch_surname()) break;
			if (new_accountant->ch_patronymic()) break;
			if (new_accountant->ch_birthday()) break;
			new_accountant->ch_base_salary();
			new_accountant->ch_salary_rate();

			accountant = new_accountant;
			if (secretary) secretary->pnt_initialization(electricians, guards, accountant);
			break; 
		}
		case 3: {
			Guard guard;
			if (guard.ch_name()) break;
			if (guard.ch_surname()) break;
			if (guard.ch_patronymic()) break;
			if (guard.ch_birthday()) break;
			if (guard.ch_weapon()) break;
			if (guard.ch_shift()) break;

			guards->push_back(guard);
			break;
		}
		case 4: {
			Electrician electrician;
			if (electrician.ch_name()) break;
			if (electrician.ch_surname()) break;
			if (electrician.ch_patronymic()) break;
			if (electrician.ch_birthday()) break;
			if (electrician.ch_category()) break;

			electricians->push_back(electrician);
			break;
		}
		case -1:
			flag = false;
			break;
		default:
			break;
		}
	}
}

void Director::hire_employers(Accountant emp) {
	accountant = new Accountant;
	*accountant = emp;
}
void Director::hire_employers(Secretary emp) {
	emp.pnt_initialization(electricians, guards, accountant);
	secretary = new Secretary;
	*secretary = emp;
}
void Director::hire_employers(Guard emp) {
	guards->push_back(emp);
}
void Director::hire_employers(Electrician emp) {
	electricians->push_back(emp);
}

void Director::get_pnts(Accountant** accountant_, Secretary** secretary_, std::vector<Guard>** guard_vec, std::vector<Electrician>** electrician_vec) {
	*accountant_ = accountant;
	*secretary_ = secretary;
	*guard_vec = guards;
	*electrician_vec = electricians;
}

std::string Director::get_company_name() {
	return company_name;
}
bool Director::change_company_name(std::string name) {
	company_name = name;
	return 0;
}
bool Director::change_company_name() {
	std::cout << "Для отмены нажмите esc\nВведите новое название компании: ";
	std::string new_name = Input::str(100, 1);
	if (new_name == "\n") return 1;
	company_name = new_name;
	return 0;
}

void Director::print_employers()
{
	//Secretary
	if (secretary) {
		std::array<std::string, 3> secretary_full_name = secretary->get_fullname();
		std::cout << "Секретарь: " << secretary_full_name[0] << " " << secretary_full_name[1] << " " << secretary_full_name[2] << std::endl;
	}
	else std::cout << "Секретарь отсутствует" << std::endl;

	//Accountant
	if (accountant) {
		std::array<std::string, 3> accountant_full_name = accountant->get_fullname();
		std::cout << "Бухгалтер: " << accountant_full_name[0] << " " << accountant_full_name[1] << " " << accountant_full_name[2] << std::endl;
	}
	else std::cout << "Бухгалтер отсутствует" << std::endl;

	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "Охранники:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << '(' << iter++ << ") " << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "Охранники отсутствуют" << std::endl;

	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "Электрики:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << '(' << iter++ << ") " << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "Электрики отсутствуют" << std::endl;
}
int Director::print_guards() {
	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "Охранники:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << '(' << iter++ << ") " << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "Охранники отсутствуют" << std::endl;
	return guards->size();
}
int Director::print_electricians() {
	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "Электрики:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << '(' << iter++ << ") " << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "Электрики отсутствуют" << std::endl;
	return electricians->size();
}