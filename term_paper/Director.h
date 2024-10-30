//Director.h

#pragma once
#include "Includes.h"
#include "Employee.h"
#include "Accountant.h"

//class Accountant;
class Secretary;
class Guard;
class Electrician;

class Director : 
	public Employee 
{
	//Full Name
	std::array<std::string, 3> full_name;
	//Salary
	double salary;
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

	//temporary accountant
	//needed when accountant is fired, so salary_rates and base_salaries wont delete
	Accountant temp_accountant;

	//company name
	std::string company_name;
	
	//request for salary_rate input
	double salary_rate_input();

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

	//Change bitrthday format(dd.mm.yyyy)
	bool ch_birthday() override;
//CHANGERS

//GETTERS
		//get full name in array: 0-name, 1-surname, 2-patronymic
	std::array<std::string, 3> get_fullname() override;

	//get salary
	double get_salary() override;

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

	//getting pointers from director to control_menu
	void get_pnts(Accountant** accountant_, Secretary** secretary_, std::vector<Guard>** guard_vec, std::vector<Electrician>** electrician_vec);

	//get company name
	std::string get_company_name();
	//change company name
	bool change_company_name();
	bool change_company_name(std::string name);
};

