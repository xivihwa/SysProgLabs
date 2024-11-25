#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"
#include <vector>
#include <string>

class Database {
private:
    std::vector<Employee> employees;

public:
    // Методы управления сотрудниками
    void addEmployee(const Employee& employee);
    void removeEmployee(int id);
    void updateSalary(int id, double percent);
    const std::vector<Employee>& getEmployees() const;

    // Методы работы с файлами
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

private:
    bool isUniqueID(int id) const;
};

#endif // DATABASE_H
