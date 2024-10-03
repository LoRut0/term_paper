#pragma once
#include "Employee.h"

class Guard:
	public Employee
{
	//Full Name
	std::array<std::string, 3> full_name;
	//Salary
	int salary;
	//Birthday
	tm birthday;

	std::string weapon;

public:
	Guard(std::string, std::string, std::string, int);

	void ch_weapon(std::string);
	std::string get_weapon();
};

