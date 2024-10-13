//Employee.h

#pragma once
#include <string>
#include <iostream>
#include <array>
#include <chrono>
#include "inputlib.h"


class Employee {
public:
//CHANGERS
	//change name
	virtual void ch_name() = 0;
	//change surname
	virtual void ch_surname() = 0;
	//change partonymic
	virtual void ch_patronymic() = 0;

	//change salary
	virtual void ch_salary() = 0;

	//Change bitrthday format(dd.mm.yyyy)
	virtual void ch_birthday() = 0;
//CHANGERS

//GETTERS
	//get full name in array: 0-name, 1-surname, 2-patronymic
	virtual std::array<std::string, 3> get_fullname() = 0;

	//get salary
	virtual int get_salary() = 0;

	//get birthday (tm struct)
	virtual std::array<int, 3> get_birthday() = 0;
//GETTERS 
};
