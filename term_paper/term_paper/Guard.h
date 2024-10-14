#pragma once
#include "Employee.h"
#include "inputlib.h"

class Guard:
	public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    std::array<int, 3> birthday;
    //Weapon
	std::string weapon;

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

    Guard(std::string name, std::string surname, std::string patronymic, std::array<int, 3> input_birthday);
    Guard();
//BASE

    //get weapon
    std::string get_weapon();
    //change weapon
	void ch_weapon();
};

