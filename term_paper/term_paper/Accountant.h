#pragma once


#include "Employee.h"


class Accountant :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    std::array<int, 3> birthday;

    /*Base salaries
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    std::array<int, 5> base_salary;
    /*Salary rates
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    std::array<double, 5> salary_rate;

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
    void ch_salary() override;

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

    Accountant(std::string name, std::string surname, std::string patronymic, int slry, std::array<int, 5> base_slry, std::array<double, 5> slry_rate);
    Accountant();
//BASE

    //get salary rate
    std::array<double, 5> get_salary_rate();
    //change salary rate
    void ch_salary_rate();

    //change base salary
    void ch_base_salary();
    //get base salary
    std::array<int, 5> get_base_salary();

    //fuction that multiplicates returns salary_rate * base_salary
    double salary_calculation(int rate, int base);
};

