//Employee.h

#pragma once
#include <string>
#include <array>
#include <chrono>
#include "inputlib.h"


class Employee {
public:
//CHANGERS
	//change name
	virtual bool ch_name() = 0;
	//change surname
	virtual bool ch_surname() = 0;
	//change partonymic
	virtual bool ch_patronymic() = 0;

	//change salary
	virtual void ch_salary(double slry) = 0;

	//Change bitrthday format(dd.mm.yyyy)
	virtual bool ch_birthday() = 0;
//CHANGERS

//GETTERS
	//get full name in array: 0-name, 1-surname, 2-patronymic
	virtual std::array<std::string, 3> get_fullname() = 0;

	//get salary
	virtual double get_salary() = 0;

	//get birthday (tm struct)
	virtual std::array<int, 3> get_birthday() = 0;
//GETTERS 
};
