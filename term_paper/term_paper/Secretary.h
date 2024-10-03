#pragma once
#include <vector>

#include "Employee.h"
#include "Guard.h"
#include "Electrician.h"

class Secretary :
    public Employee
{
    //Full Name
    std::array<std::string, 3> full_name;
    //Salary
    int salary;
    //Birthday
    tm birthday;

public:
    Secretary(std::string, std::string, std::string, int);

    void print_employers();
    void print_guards(std::vector<Guard>);
    void print_electricians(std::vector<Electrician>);
};

