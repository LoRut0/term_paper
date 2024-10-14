#pragma once
#include "Employee.h"
#include "Electrician.h"
#include "Director.h"
#include "Secretary.h"
#include "Guard.h"

class Accountant :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    double salary;
    //Birthday
    std::array<int, 3> birthday;

    /*Base salaries
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    std::array<int, 5> base_salary;
    /*Salary rates
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Security, 4 - Electrician*/
    std::array<double, 5> salary_rate;

    //pointer to vector with ellectricians
    std::vector<Electrician>* electricians;
    //pointer to vector with guards
    std::vector<Guard>* guards;
    //pointer to Secretary
    Secretary* secretary;
    //pointer to Director
    Director* director;

    //fuction that changes salaries of employees
    void salary_calculation();
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

    double average_salary();
//CHANGERS
    
//GETTERS
    //get full name in array: 0-name, 1-surname, 2-patronymic
    std::array<std::string, 3> get_fullname() override;

    //get salary
    int get_salary() override;

    //get birthday (tm struct)
    std::array<int, 3> get_birthday() override;
//GETTERS

    Accountant(std::string name, std::string surname, std::string patronymic, std::array<int, 3> input_birthday, std::array<int, 5> base_slry, std::array<double, 5> slry_rate, 
        std::vector<Electrician>* electricians, std::vector<Guard>* guards, Secretary* secretary, Director* director);
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
};

