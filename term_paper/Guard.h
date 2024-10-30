#pragma once
#include "Employee.h"
#include "inputlib.h"

class Guard:
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

    //Weapon
	std::string weapon;
    //Working shift (1) 22:00-06:00, (2) 06:00-14:00 (3) 14:00-22:00
    int shift;
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

    Guard(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::string weapon, int input_shift);
    Guard();
//BASE

    //get weapon
    std::string get_weapon();
    //change weapon
	bool ch_weapon();

    //get working shift (1) 22:00-06:00, (2) 06:00-14:00 (3) 14:00-22:00
    int get_shift();
    //change working shift (1) 22:00-06:00, (2) 06:00-14:00 (3) 14:00-22:00
    bool ch_shift();
};

