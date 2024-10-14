//director.h

#pragma once

#include "Includes.h"
#include "Electrician.h"
#include "Guard.h"
#include "Secretary.h"
#include "Accountant.h"
#include "inputlib.h"

class Director : 
	public Employee 
{
	//Full Name
	std::array<std::string, 3> full_name;
	//Salary
	int salary;
	//Birthday
	std::array<int, 3> birthday;

	//pointer to vector with ellectricians
	std::vector<Electrician>* electricians;
	//pointer to vector with guards
	std::vector<Guard>* guards;
	//pointer to Secretary
	Secretary* secretary;
	//pointer to Accountant
	Accountant* accountant;
	//pointer to self
	Director* self;

	//company name
	std::string company_name;

public:
//BASE
//CHANGERS
	//change name
	void ch_name() override;
	//change surname
	void ch_surname() override;
	//change partonymic
	void ch_patronymic() override;

	//change salary
	void ch_salary(double slry) override;

	//Change bitrthday format(dd.mm.yyyy)
	void ch_birthday() override;
//CHANGERS

//GETTERS
		//get full name in array: 0-name, 1-surname, 2-patronymic
	std::array<std::string, 3> get_fullname() override;

	//get salary
	int get_salary() override;

	//get birthday (tm struct)
	std::array<int, 3> get_birthday() override;
//GETTERS

	Director(std::string name, std::string surname, std::string patronymic, std::array<int, 3> birthday, std::string comp_name);
	~Director();

//BASE

	//print employers
	void print_employers();
	//fire employers
	void fire_employers();
	//hire employers
	void hire_employers();

	//get company name
	std::string get_company_name();
	//change company name
	void change_company_name();
};

