//director.h

#pragma once

#include "Employee.h"
#include <vector>

class Director : 
	public Employee 
{
	std::vector<Employee> employers;
	std::string company_name;

public:
	Director(std::string, std::string, std::string, int);

	std::vector<Employee> get_employers();
	void fire_employers();
	void hire_employers();
	std::string get_company_name();
	void change_company_name();
};

