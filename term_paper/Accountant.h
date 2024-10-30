#pragma once
#include "Employee.h"

class Director;
class Secretary;
class Guard;
class Electrician;

class Accountant :
    public Employee
{
//Pointers to employees
    Director** director;
    Secretary** secretary;
    std::vector<Guard>* guards;
    std::vector<Electrician>* electricians;
//Pointers to employees

    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    double salary;
    //Birthday
    std::array<int, 3> birthday;

//Salary rates
    std::vector<double> salary_rates_electricians;
    std::vector<double> salary_rates_guards;
    double salary_rate_director;
    double salary_rate_secretary;
    double salary_rate_accountant;
//Salary rates

    /*Base salaries
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Guards, 4 - Electrician*/
    std::array<int, 5> base_salary;

    /*Prints salary rates
    0 - Director, 1 - Accountant, 2 - Secretary, 3 - Guards, 4 - Electrician*/
    inline void print_salary_rate(int job);

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

    Accountant(std::array<std::string, 3> full_name, std::array<int, 3> input_birthday, std::array<int, 5> base_slry);
    Accountant();
    ~Accountant();
//BASE

    //change base salary
    void ch_base_salary();
    //get base salary
    std::array<int, 5> get_base_salary();
    
    //runs request for changing of salary rates
    void ch_salary_rates();


    //changing or appending of salary_rate of employee (silent)
    //0 - Director, 1 - Accountant, 2 - Secretary, 3 - Guards, 4 - Electrician
    //Also updates current salaries
    void salary_rate_add(int job, double slry_rate, bool update = 1);

    //deleting of salary_rate of employee, if in vector - with index "index" in vector
    //0 - Director, 1 - Accountant, 2 - Secretary, 3 - Guards, 4 - Electrician
    void salary_rate_delete(int job, int index);

    //returns average salary in company
    double average_salary();

    //pointers initialization
    void pnt_initialization(Director* director, Secretary* secretary,
        std::vector<Guard>* guards, std::vector<Electrician>* electricians);

    //Updating salaries
    void update_salaries();
};

