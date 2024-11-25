#include "Database.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

void Database::addEmployee(const Employee& employee) {
    if (!isUniqueID(employee.getId())) {
        throw std::invalid_argument("Employee ID must be unique.");
    }
    employees.push_back(employee);
}

void Database::removeEmployee(int id) {
    for (auto& emp : employees) {
        if (emp.getId() == id) {
            emp.setIsActive(false); // Помечаем сотрудника как "неактивного"
            return;
        }
    }
    throw std::runtime_error("Employee with the given ID not found.");
}

void Database::updateSalary(int id, double percent) {
    for (auto& emp : employees) {
        if (emp.getId() == id) {
            double newSalary = emp.getSalary() * (1.0 + percent / 100.0);
            emp.setSalary(newSalary);
            return;
        }
    }
    throw std::runtime_error("Employee with the given ID not found.");
}

const std::vector<Employee>& Database::getEmployees() const {
    return employees;
}

void Database::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    employees.clear();

    int id, age, positionCode;
    double salary;
    std::string fullName, gender, address, passport;
    bool isActive;

    while (file >> id >> fullName >> age >> gender >> address >> passport >> positionCode >> salary >> isActive) {
        employees.emplace_back(id, fullName, age, gender, address, passport, positionCode, salary, isActive);
    }
}

void Database::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& emp : employees) {
        file << emp.getId() << " "
             << emp.getFullName() << " "
             << emp.getAge() << " "
             << emp.getGender() << " "
             << emp.getAddress() << " "
             << emp.getPassport() << " "
             << emp.getPositionCode() << " "
             << emp.getSalary() << " "
             << emp.getIsActive() << "\n";
    }
}

bool Database::isUniqueID(int id) const {
    for (const auto& emp : employees) {
        if (emp.getId() == id) {
            return false;
        }
    }
    return true;
}
