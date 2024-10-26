#include "Secretary.h"
#include <iomanip>

//base
bool Secretary::ch_name()
{
	std::cout << "������� ���: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[0] = temp;
	return 0;
};

bool  Secretary::ch_surname()
{
	std::cout << "������� �������: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[1] = temp;
	return 0;
};

bool Secretary::ch_patronymic()
{
	std::cout << "������� ��������: ";
	std::string temp = Input::name(25);
	if (temp == "\n") return 1;
	full_name[2] = temp;
	return 0;
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

bool Secretary::ch_salary_rate(double slry_rate) {
	std::cout << "������� ������: ";
	double temp = Input::double_(0.01, 1, 2);
	if (temp == DBL_MIN) return 1;
	salary_rate = temp;
	return 0;
}

bool Secretary::ch_birthday()
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
		std::cout << "�����, �������� ������� ��������� " << full_name[0] << " " << full_name[1] << " " << full_name[2] << std::endl;
		print_languages();
		std::cout << "(Esc) �����\n(1) ��������\n";
		if (languages.size() != 0) {
			std::cout << "(2) �������\n";
			choice = Input::choice(1, 2);
		}
		else choice = Input::choice(1, 1);

		switch (choice)
		{
		case 1: {
			std::cout << "������� ����: ";
			std::string temp = Input::str(25);
			if (temp == "\n") {
				break;
			}
			languages.push_back(temp);
			break;
		}
		case 2: {
			std::cout << "��������� ����: ";
			int lang_to_del = Input::int_(1, languages.size());
			if (lang_to_del == INT_MIN) break;
			lang_to_del--;
			languages.erase(languages.begin() + lang_to_del);
			break;
		}
		case -1: {
			if (languages.size() == 0) {
				std::cout << "��������� �� ����� ���� �����..." << std::endl;
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

void Secretary::print_employers() {
	//Accountant
	if (accountant) {
		std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------+--------------+" << std::endl;
		std::cout << "|                                                          ���������                                                       |" << std::endl;
		std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------+--------------+" << std::endl;
		std::cout << std::setfill(' ') << std::left << std::setw(30) << "| ��� " << std::setw(30) << "| ������� " << std::setw(30) << "| ��������" <<
			std::setw(16) << "| ���� �������� " << std::setw(17) << "| �������� (���)" << std::setw(1) << '|' << std::endl;
		std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------+--------------+" << std::endl;
		std::array<std::string, 3> full_name = accountant->get_fullname();
		std::array<int, 3> birthday = accountant->get_birthday();
		int salary = accountant->get_salary();
		std::cout << "| " << std::setw(28) << full_name[0] << "| " << std::setw(28) << full_name[1] << "| " << std::setw(28) << full_name[2] << "| " <<
			std::right << std::setfill('0') << std::setw(2) << birthday[0] << '.' << std::setw(2) << birthday[1] << '.' << std::setw(2) << birthday[2] <<
			std::left << std::setfill(' ') << "    | " << std::setw(15) << salary << '|' << std::endl;
		std::cout << "+-----------------------------+-----------------------------+-----------------------------+-----------------+--------------+" << std::endl;
		std::cout << std::endl;
	}

	//Secretary
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+" << std::endl;
	std::cout << "|                                                                         ���������                                                                      |" << std::endl;
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+" << std::endl;
	std::cout << std::setfill(' ') << std::left << std::setw(30) << "| ��� " << std::setw(30) << "| ������� " << std::setw(30) << "| ��������" <<
		std::setw(16) << "| ���� �������� " << std::setw(17) << "| �������� (���)" << std::setw(30) << "| ����� " << std::setw(1) << '|' << std::endl;
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+" << std::endl;
	std::array<std::string, 3> full_name = this->get_fullname();
	std::array<int, 3> birthday = this->get_birthday();
	int salary = this->get_salary();
	std::cout << "| " << std::setw(28) << full_name[0] << "| " << std::setw(28) << full_name[1] << "| " << std::setw(28) << full_name[2] << "| " <<
		std::right << std::setfill('0') << std::setw(2) << birthday[0] << '.' << std::setw(2) << birthday[1] << '.' << std::setw(2) << birthday[2] <<
		std::left << std::setfill(' ') <<  "    | " << std::setw(15) << salary << "| ";
	std::cout << std::setw(28) << languages[0] << '|' << std::endl;
	if (languages.size() > 1) for (int i = 1; i < languages.size(); i++) {
		std::cout << "|                             |                             |                             |               |                | " << std::setw(28) << languages[i] << '|' << std::endl;
	}
	std::cout << "+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+" << std::endl;
	std::cout << std::endl;

	//Guards
	print_guards();
	std::cout << std::endl;

	//Electricians
	print_electricians();
}

void Secretary::print_guards() {
	//Guards
	if (guards->size() == 0) {
		std::cout << "��������� �����������" << std::endl;
		return;
	}
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+------------------------+" << std::endl;
	std::cout << "|                                                                                       ���������                                                                                         |" << std::endl;
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+------------------------+" << std::endl;
	std::cout << std::setfill(' ') << std::left << std::setw(8) << "| ����� " << std::setw(30) << "| ��� " << std::setw(30) << "| ������� " << std::setw(30) << "| ��������" <<
		std::setw(16) << "| ���� �������� " << std::setw(17) << "| �������� (���)" << std::setw(30) << "| ����. ����������� " << std::setw(25) << "| ����� " << std::setw(1) << '|' << std::endl;
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+------------------------+" << std::endl;

	int iter = 1;
	for (Guard& guard : *guards) {
		std::array<std::string, 3> full_name = guard.get_fullname();
		std::array<int, 3> birthday = guard.get_birthday();
		std::string shift;
		int salary = guard.get_salary();
		switch (guard.get_shift())
		{
		case 1:
			shift = "22:00-06:00";
			break;
		case 2:
			shift = "06:00-14:00";
			break;
		case 3:
			shift = "14:00-22:00";
			break;
		default:
			break;
		}
		std::cout << "| " << std::setw(6) << iter++ << "| " << std::setw(28) << full_name[0] << "| " << std::setw(28) << full_name[1] << "| " << std::setw(28) << full_name[2] << "| " <<
			std::right << std::setfill('0') << std::setw(2) << birthday[0] << '.' << std::setw(2) << birthday[1] << '.' << std::setw(2) << birthday[2] <<
			std::left << std::setfill(' ') << "    | " << std::setw(15) << salary << "| " << std::setw(28) << guard.get_weapon() << "| " << std::setw(23) << shift << '|' << std::endl;
		std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+-----------------------------+------------------------+" << std::endl;
	}
	return;
}

void Secretary::print_electricians() {
	//Electricians
	if (electricians->size() == 0) {
		std::cout << "��������� �����������" << std::endl;
		return;
	}
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+--------+" << std::endl;
	std::cout << "|                                                                 ���������                                                                 |" << std::endl;
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+--------+" << std::endl;
	std::cout << std::setfill(' ') << std::left << std::setw(8) << "| ����� " << std::setw(30) << "| ��� " << std::setw(30) << "| ������� " << std::setw(30) << "| ��������" <<
		std::setw(16) << "| ���� �������� " << std::setw(17) << "| �������� (���)" << std::setw(9) << "| ������ " << std::setw(1) << '|' << std::endl;
	std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+--------+" << std::endl;

	int iter = 1;
	for (Electrician& electrician : *electricians) {
		std::array<std::string, 3> full_name = electrician.get_fullname();
		std::array<int, 3> birthday = electrician.get_birthday();
		int salary = electrician.get_salary();
		std::cout << "| " << std::setw(6) << iter++ << "| " << std::setw(28) << full_name[0] << "| " << std::setw(28) << full_name[1] << "| " << std::setw(28) << full_name[2] << "| " <<
			std::right << std::setfill('0') << std::setw(2) << birthday[0] << '.' << std::setw(2) << birthday[1] << '.' << std::setw(2) << birthday[2] <<
			std::left << std::setfill(' ') << "    | " << std::setw(15) << salary << "| " << std::setw(7) << electrician.get_category() << '|' << std::endl;
		std::cout << "+-------+-----------------------------+-----------------------------+-----------------------------+---------------+----------------+--------+" << std::endl;
	}
	return;
}

//need to give pointers to classes from director
void Secretary::pnt_initialization(std::vector<Electrician>* electricians, std::vector<Guard>* guards, Accountant* accountant) {
	this->electricians = electricians;
	this->guards = guards;
	this->accountant = accountant;
	return;
}