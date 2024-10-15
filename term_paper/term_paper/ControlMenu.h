#pragma once
#include "Includes.h"

class ControlMenu
{
	//string dd.mm.yyyy to array of ints
	std::array<int, 3> str_to_date(std::string str_date);
	//vector with directors of companies
	std::vector<Director*> directors_n_companies;
	//read flag (1)-if file was readed, (0)-file was not readed/reading was unsuccessful
	bool read_flag;

	//run reading from file
	void read_from_file();

	/*print all companies and their directors
	returns amount of companies*/
	int print_companies();

	//print name from array(fio)
	inline void print_name(std::array<std::string, 3> name);
	//print birthday from array
	inline void print_birthday(std::array<int, 3> birthday);

	//Выводит директора и название компании под номером num
	inline void print_comp(int num);

	//salary update from accountant to all employers
	void salary_update(std::vector<Electrician>** electricians, std::vector<Guard>** guards, Secretary** secretary, Director** director, Accountant** accountant);
public:
	ControlMenu();

	void start();
};

