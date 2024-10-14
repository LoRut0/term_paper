#pragma once
#include "Includes.h"

class ControlMenu
{
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

public:
	ControlMenu();

	void start();
};

