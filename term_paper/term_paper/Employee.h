//Employee.h

#pragma once
#include <string>
#include <iostream>
#include <array>
#include <ctime>
#include <getch_input.h>


class Employee {
public:
	//change name
	virtual void ch_name(std::string) = 0;
	//change surname
	virtual void ch_surname(std::string) = 0;
	//change partonymic
	virtual void ch_patronymic(std::string) = 0;
	//change salary
	virtual void ch_salary(int) = 0;

	//get full name in array: 0-name, 1-surname, 2-patronymic
	virtual std::array<std::string, 3> get_fullname() = 0;
	//get salary
	virtual int get_salary() = 0;

	//Change bitrthday format(dd.mm.yyyy)
	virtual void ch_birthday() = 0;
	//get birthday (tm struct)
	virtual tm get_birthday() = 0;
};
