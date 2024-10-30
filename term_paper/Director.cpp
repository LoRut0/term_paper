#include "Director.h"
#include "Electrician.h"
#include "Guard.h"
#include "Secretary.h"
#include "Accountant.h"
#include "inputlib.h"

//BASE
bool Director::ch_name()
{
	std::cout << "������� ���: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};
bool  Director::ch_surname()
{
	std::cout << "������� �������: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};
bool Director::ch_patronymic()
{
	std::cout << "������� ��������: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 0;
};
std::array<std::string, 3> Director::get_fullname()
{
	return full_name;
};

void Director::ch_salary(double slry)
{
	salary = slry;
};
double Director::get_salary()
{
	return salary;
};

bool Director::ch_birthday()
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year chrono_current_year = std::chrono::year_month_day{ floor<std::chrono::days>(now) }.year();
	int current_year = static_cast<int>(chrono_current_year);

	std::cout << "������� ���� ��������: ";
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

Director::Director(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::string comp_name) : 
	full_name(full_name), salary(1), salary_rate(1), birthday(input_birthday), company_name(comp_name), temp_accountant()
{
	electricians = new std::vector<Electrician>;
	guards = new std::vector<Guard>;
	secretary = NULL;
	accountant = NULL;
};

Director::~Director() 
{
	delete electricians;
	electricians = NULL;
	delete guards;
	guards = NULL;
	delete secretary;
	secretary = NULL;
	delete accountant;
	accountant = NULL;
}
//BASE

double Director::salary_rate_input() {
	std::cout << "������� ������ ����������: ";
	double temp = Input::double_(0.01, 1, 2);
	if (temp == DBL_MIN) return DBL_MIN;
	return temp;
}

void Director::fire_employers() 
{
	bool flag(true);
	while (flag)
	{
		system("cls");
		print_employers();
		std::cout << "(Esc) �����\n";
		if (secretary) std::cout << "(1) ������� ���������\n";
		if (accountant) std::cout << "(2) ������� ����������\n";
		if (guards->size() > 0) std::cout << "(3) ������� ���������\n";
		if (electricians->size() > 0) std::cout << "(4) ������� ���������\n";
		int choice = Input::choice(1, 4);

		switch (choice)
		{
		case 1: {
			if (!secretary) break;
			std::cout << "����������� ���������� ��������� (1) - ��, (0) - ���" << std::endl;
			if (Input::bool_('0', '1')) secretary = NULL;
			break;
		}
		case 2: {
			if (!accountant) break;
			std::cout << "����������� ���������� ���������� (1) - ��, (0) - ���" << std::endl;
			temp_accountant = *accountant;
			if (Input::bool_('0', '1')) accountant = NULL;
			break;
		}
		case 3: {
			if (guards->size() == 0) break;
			std::cout << "������� ����� ���������, �������� ������ �������: ";
			int number = Input::int_(1, guards->size());
			if (number == INT_MIN) break;

			std::cout << "����������� ���������� ��������� " << number-- << " (1) - ��, (0) - ���" << std::endl;
			if (Input::bool_('0', '1')) {
				guards->erase(guards->begin() + number);
				if (!accountant) temp_accountant.salary_rate_delete(3, number);
				else accountant->salary_rate_delete(3, number);
			}
			break;
		}
		case 4: {
			if (electricians->size() == 0) break;
			std::cout << "������� ����� ���������, �������� ������ �������: ";
			int number = Input::int_(1, electricians->size());
			if (number == INT_MIN) break;

			std::cout << "����������� ���������� ��������� " << number-- << " (1) - ��, (0) - ���" << std::endl;
			if (Input::bool_('0', '1')) {
				electricians->erase(electricians->begin() + number);
				if (!accountant) temp_accountant.salary_rate_delete(4, number);
				else accountant->salary_rate_delete(4, number);
			}
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
			std::cout << "(Esc) �����\n(3) ������ ���������\n(4) ������ ���������" << std::endl;
			choice = Input::choice(1, 4);
		}
		else {
			if (secretary) {
				std::cout << "(Esc) �����\n(2) ������ ����������\n" << std::endl;
				choice = Input::choice(2, 2);
			}
			else if (accountant) {
				std::cout << "(Esc) �����\n(1) ������ ���������\n" << std::endl;
				choice = Input::choice(1, 1);
			}
			else {
				std::cout << "(Esc) �����\n(1) ������ ���������\n(2) ������ ����������\n" << std::endl;
				choice = Input::choice(1, 2);
			}
		}

		switch (choice)
		{
		case 1: {
			if (secretary) {
				std::cout << "������ ������ 2 ���������" << std::endl;
				system("pause");
				break;
			}
			Secretary* new_secretary = new Secretary;
			if (new_secretary->ch_name()) break;
			if (new_secretary->ch_surname()) break;
			if (new_secretary->ch_patronymic()) break;
			if (new_secretary->ch_birthday()) break;
			new_secretary->change_languages();
			new_secretary->pnt_initialization(electricians, guards, accountant);

			//��������� ������ ��� ���������
			if (accountant) {
				system("cls");
				std::array<std::string, 3> emp_full_name;
				double temp_slry_rate = salary_rate_input();
				if (temp_slry_rate == DBL_MIN) break;
				accountant->salary_rate_add(2, temp_slry_rate);
			}

			secretary = new_secretary;
			break;
		}
		case 2: {
			if (accountant) {
				std::cout << "������ ������ 2 ����������" << std::endl;
				system("pause");
				break;
			}
			Accountant* new_accountant = new Accountant;
			*new_accountant = temp_accountant;
			if (new_accountant->ch_name()) break;
			if (new_accountant->ch_surname()) break;
			if (new_accountant->ch_patronymic()) break;
			if (new_accountant->ch_birthday()) break;
			new_accountant->pnt_initialization(this, secretary, guards, electricians);
			new_accountant->ch_base_salary();
			new_accountant->ch_salary_rates();

			accountant = new_accountant;
			//if (secretary) secretary->pnt_initialization(electricians, guards, accountant);
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

			double temp_slry_rate = salary_rate_input();
			if (temp_slry_rate == DBL_MIN) break;

			guards->push_back(guard);
			accountant->salary_rate_add(3, temp_slry_rate);
			break;
		}
		case 4: {
			Electrician electrician;
			if (electrician.ch_name()) break;
			if (electrician.ch_surname()) break;
			if (electrician.ch_patronymic()) break;
			if (electrician.ch_birthday()) break;
			if (electrician.ch_category()) break;

			double temp_slry_rate = salary_rate_input();
			if (temp_slry_rate == DBL_MIN) break;

			electricians->push_back(electrician);
			accountant->salary_rate_add(4, temp_slry_rate);
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
	std::cout << "��� ������ ������� esc\n������� ����� �������� ��������: ";
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
		std::cout << "���������: " << secretary_full_name[0] << " " << secretary_full_name[1] << " " << secretary_full_name[2] << std::endl;
	}
	else std::cout << "��������� �����������" << std::endl;

	//Accountant
	if (accountant) {
		std::array<std::string, 3> accountant_full_name = accountant->get_fullname();
		std::cout << "���������: " << accountant_full_name[0] << " " << accountant_full_name[1] << " " << accountant_full_name[2] << std::endl;
	}
	else std::cout << "��������� �����������" << std::endl;

	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "���������:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << '(' << iter++ << ") " << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "��������� �����������" << std::endl;

	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "���������:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << '(' << iter++ << ") " << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "��������� �����������" << std::endl;
}
int Director::print_guards() {
	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "���������:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << '(' << iter++ << ") " << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "��������� �����������" << std::endl;
	return guards->size();
}
int Director::print_electricians() {
	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "���������:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << '(' << iter++ << ") " << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "��������� �����������" << std::endl;
	return electricians->size();
}