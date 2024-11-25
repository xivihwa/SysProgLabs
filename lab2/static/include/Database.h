#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"
#include <vector>
#include <string>

class Database {
public:
    void addEmployee(const Employee& employee);

    void displayEmployees() const;

    void saveToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    void updateSalary(int id, double percent);

    void removeEmployee(int id);

private:
    std::vector<Employee> employees;
};

#endif
