#pragma once
#include "Employee.h"

class Electrician :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    tm birthday;

    int category;
    std::vector<std::string> tools;

public:
    Electrician(std::string, std::string, std::string, int);

    int get_category();
    void ch_category(int);

    std::vector<std::string> get_tools();
    void ch_tools();
};

