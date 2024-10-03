//director.h

#pragma once

#include "Employee.h"
#include "Includes.h"
#include <vector>

class Director : 
	public Employee 
{
	//Full Name
	std::array<std::string, 3> full_name;
	//Salary
	int salary;
	//Birthday
	tm birthday;

	std::vector<Electrician> electricians;
	std::vector<Guard> guards;
	Secretary secretary;
	Accountant accountant;
	std::string company_name;

public:
	Director(std::string, std::string, std::string, int);

	void get_employers();
	void fire_employers();
	void hire_employers();

	std::string get_company_name();
	void change_company_name();
};

