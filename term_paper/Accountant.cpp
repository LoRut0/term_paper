#include "Accountant.h"
#include "inputlib.h"

#include "Director.h"
#include "Secretary.h"
#include "Electrician.h"
#include "Guard.h"

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
	return 0;
};
std::array<std::string, 3> Accountant::get_fullname() 
{
	return full_name;
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

Accountant::Accountant(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::array<int, 5> base_slry) :
	full_name(full_name), salary(1), birthday(input_birthday), base_salary(base_slry), salary_rate_accountant(1), salary_rate_secretary(1), salary_rate_director(1)
{
	electricians = NULL;
	guards = NULL;
	director = NULL;
	secretary = NULL;
};

Accountant::Accountant() : full_name({"name", "surname", "patronymic"}), salary(1), base_salary({ 100, 100, 100, 100, 100 }), birthday({0,0,0}), 
	salary_rate_accountant(1), salary_rate_secretary(1), salary_rate_director(1)
{
	electricians = NULL;
	guards = NULL;
	director = NULL;
	secretary = NULL;
};

Accountant::~Accountant() {
	delete director;
	director = NULL;
	delete secretary;
	secretary = NULL;
}

//BASE

//std::array<double, 5> Accountant::get_salary_rate() {
//	return salary_rate;
//}

void Accountant::ch_salary_rates() {
	bool flag = true;
	while (flag) {
		system("cls");
		std::cout << "Чью ставку вы хотите изменить: " << std::endl;
		std::cout << "(1) Директор (Текущая:" << salary_rate_director << ")\n(2) Бухгалтер (Текущая: " << salary_rate_accountant << ")\n";
		if (*secretary) std::cout << "(3) Секретарь (Текущая:" << salary_rate_secretary << ")\n";
		if ((*guards).size() != 0) std::cout << "(4) Охранники\n";
		if ((*electricians).size() != 0) std::cout << "(5) Электрики\n";

		int choice = Input::choice(1, 5);
		switch (choice)
		{
		case 1: {
			while (true)
			{
				print_salary_rate(0);
				std::cout << "Новая ставка: ";
				double temp_slry_rate = Input::double_(0.01, 1, 2);
				if (temp_slry_rate == DBL_MIN) break;
				salary_rate_director = temp_slry_rate;
				break;
			}
			break;
		}
		case 2: {
			while (true) {
				print_salary_rate(1);
				std::cout << "Новая ставка: ";
				double temp_slry_rate = Input::double_(0.01, 1, 2);
				if (temp_slry_rate == DBL_MIN) break;
				salary_rate_accountant = temp_slry_rate;
				break;
			}
			break;
		}
		case 3: {
			while (true) {
				if (!(*secretary)) break;
				print_salary_rate(2);
				std::cout << "Новая ставка: ";
				double temp_slry_rate = Input::double_(0.01, 1, 2);
				if (temp_slry_rate == DBL_MIN) break;
				salary_rate_secretary = temp_slry_rate;
				break;
			}
			break;
		}
		case 4: {
			if ((*guards).size() == 0) break;
			while (true) {
				print_salary_rate(3);
				std::cout << "Введите номер сотрудника, чью ставку вы желаете изменить: ";
				int emp_choice = Input::int_(1, guards->size());
				if (emp_choice == INT_MIN) break;

				while (true)
				{
					system("cls");
					std::array<std::string, 3> emp_full_name = (*guards)[emp_choice].get_fullname();
					std::cout << "Ставка охранника " << emp_full_name[1] << " " << emp_full_name[0]
						<< " " << emp_full_name[2] << ": " << salary_rates_guards[emp_choice - 1] << std::endl;

					std::cout << "Новая ставка: ";
					double temp_slry_rate = Input::double_(0.01, 1, 2);
					if (temp_slry_rate == DBL_MIN) break;
					salary_rates_guards[emp_choice - 1] = temp_slry_rate;
					break;
				}
			}
			break;
		}
		case 5: {
			if ((*electricians).size() == 0) break;
			while (true) {
				print_salary_rate(4);
				std::cout << "Введите номер сотрудника, чью ставку вы желаете изменить: ";
				int emp_choice = Input::int_(1, electricians->size());
				if (emp_choice == INT_MIN) break;

				while (true)
				{
					system("cls");
					std::array<std::string, 3> emp_full_name = (*electricians)[emp_choice].get_fullname();
					std::cout << "Ставка охранника " << emp_full_name[1] << " " << emp_full_name[0]
						<< " " << emp_full_name[2] << ": " << salary_rates_electricians[emp_choice - 1] << std::endl;

					std::cout << "Новая ставка: ";
					double temp_slry_rate = Input::double_(0.01, 1, 2);
					if (temp_slry_rate == DBL_MIN) break;
					salary_rates_electricians[emp_choice - 1] = temp_slry_rate;
					break;
				}
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
	update_salaries();
	return;
}

void Accountant::ch_salary(double slry)
{
	salary = slry;
	return;
};
double Accountant::get_salary()
{
	return salary;
};

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
	update_salaries();
}
std::array<int, 5> Accountant::get_base_salary() {
	return base_salary;
}

//0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician
//inline std::array<double, 5> Accountant::salary_calculation() {
//	Secretary Secretary;
//	return {salary_rate[0] * base_salary[0], salary_rate[1] * base_salary[1], 
//	salary_rate[2] * base_salary[2], salary_rate[3] * base_salary[3], salary_rate[4] * base_salary[4], };
//}

double Accountant::average_salary() {
	double sum(0);
	bool secret = *secretary;
	int num_of_workers = 2 + secret + guards->size() + electricians->size();
	if (*secretary) sum += (*secretary)->get_salary();
	sum += (*director)->get_salary();
	sum += this->get_salary();
	for (Electrician& emp : *electricians) sum += emp.get_salary();
	for (Guard& emp : *guards) sum += emp.get_salary();
	return sum / num_of_workers;
}

void Accountant::update_salaries() {
	//director
	(*director)->ch_salary(salary_rate_director * base_salary[0]);
	//accountant
	this->ch_salary(salary_rate_accountant * base_salary[1]);
	//secretary
	if (*secretary) (*secretary)->ch_salary(salary_rate_secretary * base_salary[2]);
	//guards
	if (guards->size() != salary_rates_guards.size()) 
		std::cerr << "Lengths of guards vector and salary_rates_guards does not match" << std::endl;

	for (int i = 0; i < guards->size(); i++) {
		(*guards)[i].ch_salary(salary_rates_guards[i] * base_salary[3]);
	}
	//electricians
	if (electricians->size() != salary_rates_electricians.size()) 
		std::cerr << "Lengths of electricians vector and salary_rates_electricians does not match" << std::endl;

	for (int i = 0; i < electricians->size(); i++) {
		(*electricians)[i].ch_salary(salary_rates_electricians[i] * base_salary[4]);
	}
}

inline void Accountant::print_salary_rate(int job) {
	switch (job)
	{
	case 0: {
		std::array<std::string, 3> emp_full_name = (*director)->get_fullname();
		std::cout << "Ставка директора " << emp_full_name[1] << " " << emp_full_name[0]
			<< " " << emp_full_name[2] << ": " << salary_rate_director << std::endl;
		break;
	}
	case 1: {
		std::cout << "Ставка бухгалтера " << full_name[1] << " " << full_name[0]
			<< " " << full_name[2] << ": " << salary_rate_accountant << std::endl;
		break;
	}
	case 2: {
		std::array<std::string, 3> emp_full_name = (*secretary)->get_fullname();
		std::cout << "Ставка секретаря " << emp_full_name[1] << " " << emp_full_name[0]
			<< " " << emp_full_name[2] << ": " << salary_rate_secretary << std::endl;
		break;
	}
	case 3: {
		std::cout << "Ставки охранников" << std::endl;
		for (int i = 0; i < guards->size(); i++) {
			std::array<std::string, 3> emp_full_name = (*guards)[i].get_fullname();
			std::cout << '(' << i+1  << ") " 
				<< emp_full_name[1] << " " << emp_full_name[0] << " " << emp_full_name[2] << ": " 
				<< salary_rates_guards[i] << std::endl;
		}
		break;
	}
	case 4: {
		std::cout << "Ставки электриков" << std::endl;
		for (int i = 0; i < electricians->size(); i++) {
			std::array<std::string, 3> emp_full_name = (*electricians)[i].get_fullname();
			std::cout << '(' << i+1 << ") "
				<< emp_full_name[1] << " " << emp_full_name[0] << " " << emp_full_name[2] << ": "
				<< salary_rates_electricians[i] << std::endl;
		}
		break;
	}
	}
}

void Accountant::pnt_initialization(Director* director, Secretary* secretary, 
	std::vector<Guard>* guards, std::vector<Electrician>* electricians) 
{
	this->director = new Director*;
	this->secretary = new Secretary*;
	*(this->director) = director;
	*(this->secretary) = secretary;
	this->guards = guards;
	this->electricians = electricians;
	return;
}


void Accountant::salary_rate_add(int job, double slry_rate, bool update) {
	switch (job)
	{
	case 0:
		salary_rate_director = slry_rate;
		break;
	case 1:
		salary_rate_accountant = slry_rate;
		break;
	case 2:
		salary_rate_secretary = slry_rate;
		break;
	case 3:
		salary_rates_guards.push_back(slry_rate);
		break;
	case 4:
		salary_rates_electricians.push_back(slry_rate);
		break;
	default:
		std::cerr << "invalid job" << std::endl;
		break;
	}
	if (update) update_salaries();
	return;
}

void Accountant::salary_rate_delete(int job, int index) {
	switch (job)
	{
	case 0:
		salary_rate_add(0, 1);
		break;
	case 1:
		salary_rate_add(1, 1);
		break;
	case 2:
		salary_rate_add(2, 1);
		break;
	case 3:
		salary_rates_guards.erase(salary_rates_guards.begin() + index);
		break;
	case 4:
		salary_rates_electricians.erase(salary_rates_electricians.begin() + index);
		break;
	default:
		std::cerr << "invalid job" << std::endl;
		break;
	}
}