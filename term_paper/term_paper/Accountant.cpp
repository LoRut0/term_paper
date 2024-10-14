#include "Accountant.h"
#include "inputlib.h"

//base

void Accountant::ch_name()
{
	std::cout<<"Enter name: ";
	full_name[0] = Input::name(25);
};

void  Accountant::ch_surname()
{
	std::cout << "Enter surname: ";
	full_name[1] = Input::name(25);
};

void Accountant::ch_patronymic()
{
	std::cout << "Enter patronymic: ";
	full_name[2] = Input::name(25);
};

void Accountant::ch_salary(double slry)
{ 
	salary = slry;
};


std::array<std::string, 3> Accountant::get_fullname() 
{
	return full_name;
};
	
int Accountant::get_salary() 
{
	return salary;
};

void Accountant::ch_birthday()
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

std::array<int, 3> Accountant::get_birthday()
{
	return birthday;
};

Accountant::Accountant(std::string name, std::string surname, std::string patronymic, std::array<int, 3> input_birthday, std::array<int, 5> base_slry, std::array<double, 5> slry_rate,
	std::vector<Electrician>* electricians, std::vector<Guard>* guards, Secretary* secretary, Director* director)
{
	full_name[0] = name;
	full_name[1] = surname;
	full_name[2] = patronymic;
	salary = 1;

	base_salary = base_slry;
	salary_rate = slry_rate;
	birthday = input_birthday;

	this->electricians = electricians;
	this->guards = guards;
	this->secretary = secretary;
	this->director = director;
};

Accountant::Accountant()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;

	base_salary = { 0,0,0,0,0 };
	salary_rate = { 1,1,1,1,1 };
	birthday = { 0,0,0 };
};
//base

std::array<double, 5> Accountant::get_salary_rate() {
	return salary_rate;
}

void Accountant::ch_salary_rate() {
	bool flag(true);
	while (flag)
	{
		system("cls");
		std::cout << "Ставки по должностям: " << std::endl;
		std::cout << "(1) Директор: " << salary_rate[0] << std::endl;
		std::cout << "(2) Бухгалтер: " << salary_rate[1] << std::endl;
		std::cout << "(3) Секретарь: " << salary_rate[2] << std::endl;
		std::cout << "(4) Охранник: " << salary_rate[3] << std::endl;
		std::cout << "(5) Электрик: " << salary_rate[4] << std::endl;

		std::cout << "Для выхода нажмите Esc\nВыберите должность, ставку которой вы хотите изменить" << std::endl;
		switch (Input::choice(1, 5))
		{
		case 1: {
			std::cout << "Введите новую ставку для Директора: ";
			double new_rate = Input::double_(0.1, 100000);
			if (new_rate == DBL_MIN) break;
			salary_rate[0] = new_rate;
			break;
		}
		case 2: {
			std::cout << "Введите новую ставку для Бухгалтера: ";
			double new_rate = Input::double_(0.1, 100000);
			if (new_rate == DBL_MIN) break;
			salary_rate[1] = new_rate;
			break;
		}
		case 3: {
			std::cout << "Введите новую ставку для Секретаря: ";
			double new_rate = Input::double_(0.1, 100000);
			if (new_rate == DBL_MIN) break;
			salary_rate[2] = new_rate;
			break;
		}
		case 4: {
			std::cout << "Введите новую ставку для Охранника: ";
			double new_rate = Input::double_(0.1, 100000);
			if (new_rate == DBL_MIN) break;
			salary_rate[3] = new_rate;
			break;
		}
		case 5: {
			std::cout << "Введите новую ставку для Электрика: ";
			double new_rate = Input::double_(0.1, 100000);
			if (new_rate == DBL_MIN) break;
			salary_rate[4] = new_rate;
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

std::array<int, 5> Accountant::get_base_salary() {
	return base_salary;
}

void Accountant::ch_base_salary() {
	bool flag(true);
	while (flag)
	{
		system("cls");
		std::cout << "Оклады по должностям: " << std::endl;
		std::cout << "(1) Директор: " << salary_rate[0] << std::endl;
		std::cout << "(2) Бухгалтер: " << salary_rate[1] << std::endl;
		std::cout << "(3) Секретарь: " << salary_rate[2] << std::endl;
		std::cout << "(4) Охранник: " << salary_rate[3] << std::endl;
		std::cout << "(5) Электрик: " << salary_rate[4] << std::endl;

		std::cout << "Для выхода нажмите Esc\nВыберите должность, оклад которой вы хотите изменить" << std::endl;
		switch (Input::choice(1, 5))
		{
		case 1: {
			std::cout << "Введите новый оклад для Директора: ";
			int new_base = Input::int_(1, 10000000);
			if (new_base == INT_MIN) break;
			base_salary[0] = new_base;
			break;
		}
		case 2: {
			std::cout << "Введите новый оклад для Бухгалтера: ";
			int new_base = Input::int_(1, 10000000);
			if (new_base == INT_MIN) break;
			base_salary[1] = new_base;
			break;
		}
		case 3: {
			std::cout << "Введите новый оклад для Секретаря: ";
			int new_base = Input::int_(1, 10000000);
			if (new_base == INT_MIN) break;
			base_salary[2] = new_base;
			break;
		}
		case 4: {
			std::cout << "Введите новый оклад для Охранника: ";
			int new_base = Input::int_(1, 10000000);
			if (new_base == INT_MIN) break;
			base_salary[3] = new_base;
			break;
		}
		case 5: {
			std::cout << "Введите новый оклад для Электрика: ";
			int new_base = Input::int_(1, 10000000);
			if (new_base == INT_MIN) break;
			base_salary[4] = new_base;
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

void Accountant::salary_calculation() {
	director->ch_salary(base_salary[0] * salary_rate[0]);
	this->ch_salary(base_salary[1] * salary_rate[1]);
	secretary->ch_salary(base_salary[2] * salary_rate[2]);
	for(Guard guard : *guards) guard.ch_salary(base_salary[3] * salary_rate[3]);
	for(Electrician electrician : *electricians) electrician.ch_salary(base_salary[3] * salary_rate[3]);
	return;
}

double Accountant::average_salary() {
	double sum;
	int num_of_emps(3);
	sum += director->get_salary();
	sum += this->get_salary();
	sum += secretary->get_salary();
	for (Guard guard : *guards) sum += guard.get_salary();
	num_of_emps += (*guards).size();
	for (Electrician electrician : *electricians) sum += electrician.get_salary();
	num_of_emps += (*electricians).size();
	return sum / num_of_emps;
}