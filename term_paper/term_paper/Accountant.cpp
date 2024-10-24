#include "Accountant.h"
#include "inputlib.h"
#include "Secretary.h"

//BASE
bool Accountant::ch_name()
{
	std::cout<<"Введите имя: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};

bool  Accountant::ch_surname()
{
	std::cout << "Введите фамилию: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};

bool Accountant::ch_patronymic()
{
	std::cout << "Введите отчество: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 1;
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

bool Accountant::ch_birthday()
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

std::array<int, 3> Accountant::get_birthday()
{
	return birthday;
};

Accountant::Accountant(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::array<int, 5> base_slry, std::array<double, 5> slry_rate)
{
	this->full_name = full_name;
	salary = 1;

	base_salary = base_slry;
	salary_rate = slry_rate;
	birthday = input_birthday;
};

Accountant::Accountant()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;

	base_salary = { 100,100,100,100,100 };
	salary_rate = { 1,1,1,1,1 };
	birthday = { 0,0,0 };
};
//BASE

//std::array<double, 5> Accountant::get_salary_rate() {
//	return salary_rate;
//}

bool Accountant::ch_salary_rate(double slry_rate) {
	std::cout << "Введите ставку: ";
	double temp = Input::double_(0.01, 1, 2);
	if (temp == DBL_MIN) return 1;
	salary_rate = temp;
	return 0;
}

double Accountant::get_salary_rate() {
	return salary_rate;
}

//void Accountant::ch_salary_rate() {
//	bool flag(true);
//	while (flag)
//	{
//		system("cls");
//		std::cout << "Ставки по должностям: " << std::endl;
//		std::cout << "(1) Директор: " << salary_rate[0] << std::endl;
//		std::cout << "(2) Бухгалтер: " << salary_rate[1] << std::endl;
//		std::cout << "(3) Секретарь: " << salary_rate[2] << std::endl;
//		std::cout << "(4) Охранник: " << salary_rate[3] << std::endl;
//		std::cout << "(5) Электрик: " << salary_rate[4] << std::endl;
//
//		std::cout << "Для выхода нажмите Esc\nВыберите должность, ставку которой вы хотите изменить" << std::endl;
//		switch (Input::choice(1, 5))
//		{
//		case 1: {
//			std::cout << "Введите новую ставку для Директора: ";
//			double new_rate = Input::double_(0.1, 1);
//			if (new_rate == DBL_MIN) break;
//			salary_rate[0] = new_rate;
//			break;
//		}
//		case 2: {
//			std::cout << "Введите новую ставку для Бухгалтера: ";
//			double new_rate = Input::double_(0.1, 1);
//			if (new_rate == DBL_MIN) break;
//			salary_rate[1] = new_rate;
//			break;
//		}
//		case 3: {
//			std::cout << "Введите новую ставку для Секретаря: ";
//			double new_rate = Input::double_(0.1, 1);
//			if (new_rate == DBL_MIN) break;
//			salary_rate[2] = new_rate;
//			break;
//		}
//		case 4: {
//			std::cout << "Введите новую ставку для Охранника: ";
//			double new_rate = Input::double_(0.1, 1);
//			if (new_rate == DBL_MIN) break;
//			salary_rate[3] = new_rate;
//			break;
//		}
//		case 5: {
//			std::cout << "Введите новую ставку для Электрика: ";
//			double new_rate = Input::double_(0.1, 1);
//			if (new_rate == DBL_MIN) break;
//			salary_rate[4] = new_rate;
//			break;
//		}
//		case -1:
//			flag = false;
//			break;
//		default:
//			break;
//		}
//	}
//}

std::array<int, 5> Accountant::get_base_salary() {
	return base_salary;
}

void Accountant::ch_base_salary() {
	bool flag(true);
	while (flag)
	{
		system("cls");
		std::cout << "Оклады по должностям: " << std::endl;
		std::cout << "(1) Директор: " << base_salary[0] << std::endl;
		std::cout << "(2) Бухгалтер: " << base_salary[1] << std::endl;
		std::cout << "(3) Секретарь: " << base_salary[2] << std::endl;
		std::cout << "(4) Охранник: " << base_salary[3] << std::endl;
		std::cout << "(5) Электрик: " << base_salary[4] << std::endl;

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

//0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician
//inline std::array<double, 5> Accountant::salary_calculation() {
//	Secretary Secretary;
//	return {salary_rate[0] * base_salary[0], salary_rate[1] * base_salary[1], 
//	salary_rate[2] * base_salary[2], salary_rate[3] * base_salary[3], salary_rate[4] * base_salary[4], };
//}

double Accountant::average_salary(int guards, int electricians, int secretary) {
	std::array<double, 5> salaries = salary_calculation();
	double sum = salaries[0] + salaries[1] + salaries[2] * secretary + salaries[3] * guards + salaries[4] * electricians;
	int num_of_workers = 3 + guards + electricians;
	return sum / num_of_workers;
}
