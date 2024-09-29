//Employee.h

#pragma once
#include <string>
#include <iostream>
#include <array>

class Employee {
	std::array<std::string, 3> full_name;
	int salary;

protected:
	Employee(std::string, std::string, std::string, int);

	//change name
	void ch_name(std::string);
	//change surname
	void ch_surname(std::string);
	//change partonymic
	void ch_patronymic(std::string);
	//change salary
	void ch_salary(int);

	//get full name in array: 0-name, 1-surname, 2-patronymic
	std::array<std::string, 3> get_fullname();
	//get salary
	int get_salary();
};

