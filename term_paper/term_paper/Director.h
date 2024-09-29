//director.h

#pragma once

#include "Employee.h"
#include <vector>

class Director : 
	public Employee 
{
	std::vector<Employee> employers;

public:
	Director(std::string, std::string, std::string, int);

	std::vector<Employee> get_employers();
	void fire_employers();
	void hire_employers();
};

