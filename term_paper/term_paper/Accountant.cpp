#include "Accountant.h"

void Accountant::ch_name()
{
	std::cout<<"Enter name: ";
	full_name[0] = name_input(25);
};

void  Accountant::ch_surname()
{
	std::cout << "Enter surname: ";
	full_name[1] = name_input(25);
};

void Accountant::ch_patronymic()
{
	std::cout << "Enter patronymic: ";
	full_name[2] = name_input(25);
};

void Accountant::ch_salary()
{
	std::cout << "Enter salary: "; 
	salary = int_input(1);
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
	// �������� ������� �����
	std::time_t t = std::time(nullptr);
	// ����������� ��� � ��������� tm
	std::tm* now = std::localtime(&t);
	// �������� ��� � �������� ��� � �������, ������� � 1900
	int current_year = now->tm_year + 1900;

	std::string temp = date_input(1900, current_year);
	std::string date[3];

	date[0].push_back(temp[0]);
	date[0].push_back(temp[1]);
	date[1].push_back(temp[3]);
	date[1].push_back(temp[4]);
	date[2].push_back(temp[6]);
	date[2].push_back(temp[7]);
	date[2].push_back(temp[8]);
	date[2].push_back(temp[9]);

	birthday.tm_year = std::stoi(date[2]);
	birthday.tm_mon = std::stoi(date[1]);
	birthday.tm_mday = std::stoi(date[0]);
};

tm Accountant::get_birthday()
{
	return birthday;
};

Accountant::Accountant() 
{
	full_name[0] = name;
	full_name[1] = surname;
	full_name[2] = patronymic;
	salary = slry;
};