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
	//Rate of salary
	double salary_rate;

	//pointer to vector with ellectricians
	std::vector<Electrician>* electricians;
	//pointer to vector with guards
	std::vector<Guard>* guards;
	//pointer to Secretary
	Secretary* secretary;
	//pointer to Accountant
	Accountant* accountant;

	//company name
	std::string company_name;

public:
//BASE
//CHANGERS
	//change name
	bool ch_name() override;
	//change surname
	bool ch_surname() override;
	//change partonymic
	bool ch_patronymic() override;

	//change salary
	void ch_salary(double slry) override;
	//change Rate of salary
	bool ch_salary_rate(double slry_rate) override;

	//Change bitrthday format(dd.mm.yyyy)
	bool ch_birthday() override;
//CHANGERS

//GETTERS
		//get full name in array: 0-name, 1-surname, 2-patronymic
	std::array<std::string, 3> get_fullname() override;

	//get salary
	int get_salary() override;
	//get rate of salary
	double get_salary_rate() override;

	//get birthday (tm struct)
	std::array<int, 3> get_birthday() override;
//GETTERS

	Director(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::string comp_name);
	~Director();

//BASE

	//print employers
	void print_employers();
	//print guards
	int print_guards();
	//print electricians
	int print_electricians();
	//fire employers
	void fire_employers();
	//hire employers
	void hire_employers();

	void hire_employers(Accountant emp);
	void hire_employers(Secretary emp);
	void hire_employers(Guard emp);
	void hire_employers(Electrician emp);

	void get_pnts(Accountant** accountant_, Secretary** secretary_, std::vector<Guard>** guard_vec, std::vector<Electrician>** electrician_vec);

	//get company name
	std::string get_company_name();
	//change company name
	bool change_company_name();
	bool change_company_name(std::string name);
};

