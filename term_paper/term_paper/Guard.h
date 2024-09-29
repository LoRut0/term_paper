#pragma once
#include "Employee.h"

class Guard:
	public Employee
{
	std::string weapon;

public:
	Guard(std::string, std::string, std::string, int);

	void ch_weapon(std::string);
	std::string get_weapon();
};

