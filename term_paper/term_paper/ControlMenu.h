#pragma once
#include "Includes.h"

class ControlMenu
{
	//read flag (1)-if file was readed, (0)-file was not readed/reading was unsuccessful
	bool read_flag;

	//pointers to current all employers
//pointers
	Director* director;
	Accountant* accountant;
	Secretary* secretary;
	std::vector<Guard>* guards;
	std::vector<Electrician>* electricians;

	//vector with directors of companies
	std::vector<Director*> directors_n_companies;
//pointers
	//choice of director in vector director_n_companies
	int choice;

	//string dd.mm.yyyy to array of ints
	std::array<int, 3> str_to_date(std::string str_date);

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
	inline void print_company(int num);

	//salary update from accountant to all employers
	void salary_update(std::vector<Electrician>** electricians, std::vector<Guard>** guards, Secretary** secretary, Director** director, Accountant** accountant);

	void print_salary(Director*);
	void print_salary(Accountant*);
	void print_salary(Secretary*);
	void print_salary(Guard);
	void print_salary(Electrician);

	//Create new director and company
	bool create_new_cmpny();

//Menu
	bool director_menu();
	bool secretary_menu();
	bool accountant_menu();
	bool guards_menu();
	bool electricians_menu();
//Menu
public:
	ControlMenu();
	~ControlMenu();

	void start();
};

