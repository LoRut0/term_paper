#include "Director.h"

//base

void Director::ch_name()
{
	std::cout << "Enter name: ";
	full_name[0] = Input::name(25);
};

void  Director::ch_surname()
{
	std::cout << "Enter surname: ";
	full_name[1] = Input::name(25);
};

void Director::ch_patronymic()
{
	std::cout << "Enter patronymic: ";
	full_name[2] = Input::name(25);
};

void Director::ch_salary()
{
	std::cout << "Enter salary: ";
	salary = Input::int_(10);
};


std::array<std::string, 3> Director::get_fullname()
{
	return full_name;
};

int Director::get_salary()
{
	return salary;
};

void Director::ch_birthday()
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

std::array<int, 3> Director::get_birthday()
{
	return birthday;
};

Director::Director(std::string name, std::string surname, std::string patronymic, int slry)
{
	full_name[0] = name;
	full_name[1] = surname;
	full_name[2] = patronymic;
	salary = slry;
	
	birthday = { 0,0,0 };

	//initialization of pointers
	electricians = new std::vector<Electrician>;
	guards = new std::vector<Guard>;
	secretary = new Secretary;
	accountant = new Accountant;
};

Director::~Director() 
{
	delete electricians;
	delete guards;
	delete secretary;
	delete accountant;
}

//base

void Director::print_employers() 
{
	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "Электрики:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << iter << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "Электрики отсутствуют" << std::endl;

	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "Охранники:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << iter << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "Охранники отсутствуют" << std::endl;

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
	else std::cout << "Секретарь отсутствует" << std::endl;

}

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
			if (secretary) secretary = NULL;
			break;
		}
		case 2: {
			if (accountant) accountant = NULL;
			break;
		}
		case 3: {
			if ((*guards).size() == 0) break;
			std::cout << "Введите номер охранника, которого хотите уволить: ";
			int number = Input::int_(1, (*guards).size()) - 1;
			(*guards).erase((*guards).begin() + number);
			break;
		}
		case 4: {
			if ((*electricians).size() == 0) break;
			std::cout << "Введите номер электрика, которого хотите уволить: ";
			int number = Input::int_(1, (*electricians).size()) - 1;
			(*electricians).erase((*electricians).begin() + number);
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
		std::cout << "(Esc) Назад\n(1) Нанять секретаря\n(2) Нанять бухгалтера\n(3) Нанять охранника\n(4) Нанять электрика" << std::endl;
		int choice = Input::choice();

		switch (choice)
		{
		case 1: {
			if (secretary) {
				std::cout << "Нельзя нанять 2 секретаря" << std::endl;
				break;
			}
			Secretary new_secretary;
			new_secretary.ch_name();
			new_secretary.ch_surname();
			new_secretary.ch_patronymic();
			new_secretary.ch_birthday();

			*secretary = new_secretary;
			break;
		}
		case 2: {
			if (accountant) {
				std::cout << "Нельзя нанять 2 бухгалтера" << std::endl;
				break;
			}
			Accountant new_accountant;
			new_accountant.ch_name();
			new_accountant.ch_surname();
			new_accountant.ch_patronymic();
			new_accountant.ch_birthday();

			*accountant = new_accountant;
			break;
		}
		case 3: {
			if ((*guards).size() == 0) break;
			std::cout << "Введите номер охранника, которого хотите уволить: ";
			int number = Input::int_(1, (*guards).size()) - 1;
			(*guards).erase((*guards).begin() + number);
			break;
		}
		case 4: {
			if ((*electricians).size() == 0) break;
			std::cout << "Введите номер электрика, которого хотите уволить: ";
			int number = Input::int_(1, (*electricians).size()) - 1;
			(*electricians).erase((*electricians).begin() + number);
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


std::string Director::get_company_name() {
	return company_name;
}

void Director::change_company_name() {
	std::cout << "Для отмены нажмите esc\nВведите новое название компании: ";
	std::string new_name = Input::str(100, 1);
	if (new_name == "\n") return;
	company_name = new_name;
}