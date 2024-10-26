#pragma once
#include "Employee.h"

class Accountant :
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

    /*Base salaries
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    std::array<int, 5> base_salary;
    /*Salary rates
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    //std::array<double, 5> salary_rate;

    //fuction that changes salaries of employees
    std::array<double, 5> salary_calculation();
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

    Accountant(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::array<int, 5> base_slry, std::array<double, 5> slry_rate);
    Accountant();
//BASE

    //change base salary
    void ch_base_salary();
    //get base salary
    std::array<int, 5> get_base_salary();
    
    //returns average salary in company
    double average_salary(int guards, int electricians, int secretary);
};

