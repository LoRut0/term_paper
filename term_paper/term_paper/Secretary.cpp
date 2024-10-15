#include "Secretary.h"

//base

void Secretary::ch_name()
{
	std::cout << "¬ведите им€: ";
	full_name[0] = Input::name(25);
};

void  Secretary::ch_surname()
{
	std::cout << "¬ведите фамилию: ";
	full_name[1] = Input::name(25);
};

void Secretary::ch_patronymic()
{
	std::cout << "¬ведите отчество: ";
	full_name[2] = Input::name(25);
};

void Secretary::ch_salary(double slry)
{
	salary = slry;
};


std::array<std::string, 3> Secretary::get_fullname()
{
	return full_name;
};

int Secretary::get_salary()
{
	return salary;
};

void Secretary::ch_birthday()
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year chrono_current_year = std::chrono::year_month_day{ floor<std::chrono::days>(now) }.year();
	int current_year = static_cast<int>(chrono_current_year);

	std::cout << "¬ведите день рождени€: ";
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

std::array<int, 3> Secretary::get_birthday()
{
	return birthday;
};

Secretary::Secretary(std::array<std::string, 3> full_name, std::array<int, 3> birthday, std::vector<std::string> langs)
{
	this->full_name = full_name;
	salary = 1;
	
	languages = langs;
	this->birthday = birthday;
};

Secretary::Secretary()
{
	full_name[0] = "name";
	full_name[1] = "surname";
	full_name[2] = "patronymic";
	salary = -1;

	birthday = { 0,0,0 };
};

//base

void Secretary::print_languages() {
	int iter = 1;
	for (std::string& language : languages) {
		std::cout << iter++ << " " << language << std::endl;
	}
}

void Secretary::change_languages() {
	bool flag = true;
	while (flag)
	{
		int choice{};
		system("cls");
		std::cout << "языки, которыми владеет секретарь " << full_name[0] << " " << full_name[1] << " " << full_name[2] << std::endl;
		print_languages();
		std::cout << "(Esc) ¬ыйти\n(1) ƒобавить\n";
		if (languages.size() != 0) {
			std::cout << "(2) ”далить\n";
			choice = Input::choice(1, 1);
		}
		else choice = Input::choice(1, 2);

		switch (choice)
		{
		case 1: {
			std::cout << "¬ведите €зык: ";
			languages.push_back(Input::name(60));
			break;
		}
		case 2: {
			std::cout << "”дал€емый €зык: ";
			int lang_to_del = Input::int_(1, languages.size()) - 1;
			languages.erase(languages.begin() + lang_to_del);
			break;
		}
		case -1: {
			if (languages.size() == 0) {
				std::cout << "—екретарь не может быть немым..." << std::endl;
				system("pause");
				break;
			}
			flag = false;
			break;
		}
		default:
			break;
		}
	}
}


//PRINT NEED TO ADD TABLE!!!!!!!!!!!!!!!!!!
void Secretary::print_employers() {
	//Accountant
	if (accountant) {
		std::array<std::string, 3> accountant_full_name = accountant->get_fullname();
		std::cout << "Ѕухгалтер: " << accountant_full_name[0] << " " << accountant_full_name[1] << " " << accountant_full_name[2] << std::endl;
	}
	else std::cout << "Ѕухгалтер отсутствует" << std::endl;

	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "Ёлектрики:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << '(' << iter++ << ") " << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "Ёлектрики отсутствуют" << std::endl;

	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "ќхранники:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << '(' << iter++ << ") " << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "ќхранники отсутствуют" << std::endl;
}

void Secretary::print_guards() {
	//Guards
	if ((*guards).size() > 0) {
		int iter = 1;
		std::cout << "ќхранники:" << std::endl;
		for (Guard& guard : *guards) {
			std::array<std::string, 3> guard_full_name = guard.get_fullname();
			std::cout << iter << guard_full_name[0] << " " << guard_full_name[1] << " " << guard_full_name[2] << std::endl;
		}
	}
	else std::cout << "ќхранники отсутствуют" << std::endl;
}

void Secretary::print_electricians() {
	//Electricians
	if ((*electricians).size() > 0) {
		int iter = 1;
		std::cout << "Ёлектрики:" << std::endl;
		for (Electrician& electrician : *electricians) {
			std::array<std::string, 3> electrician_full_name = electrician.get_fullname();
			std::cout << iter << electrician_full_name[0] << " " << electrician_full_name[1] << " " << electrician_full_name[2] << std::endl;
		}
	}
	else std::cout << "Ёлектрики отсутствуют" << std::endl;
}

//need to give pointers to classes from director
void Secretary::pnt_initialization(std::vector<Electrician>* electricians, std::vector<Guard>* guards, Accountant* accountant) {
	this->electricians = electricians;
	this->guards = guards;
	this->accountant = accountant;
	return;
}