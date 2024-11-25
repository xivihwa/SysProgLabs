#include "../include/Database.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Database::addEmployee(const Employee& employee) {
    employees.push_back(employee);
}

void Database::displayEmployees() const {
    for (const auto& employee : employees) {
        employee.display();
        std::cout << "--------------------" << std::endl;
    }
}

void Database::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& employee : employees) {
            outFile << employee.getId() << ','
                    << employee.getFullName() << ','
                    << employee.getAge() << ','
                    << employee.getGender() << ','
                    << employee.getAddress() << ','
                    << employee.getPassport() << ','
                    << employee.getPositionCode() << ','
                    << employee.getSalary() << ','
                    << employee.getIsActive() << '\n';
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

void Database::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);

            int id, age, positionCode;
            double salary;
            std::string fullName, gender, address, passport;
            bool isActive;

            ss >> id;
            ss.ignore();
            std::getline(ss, fullName, ',');
            ss >> age;
            ss.ignore();
            std::getline(ss, gender, ',');
            std::getline(ss, address, ',');
            std::getline(ss, passport, ',');
            ss >> positionCode;
            ss.ignore();
            ss >> salary;
            ss.ignore();
            ss >> isActive;

            Employee employee(id, fullName, age, gender, address, passport, positionCode, salary);
            employee.setIsActive(isActive);
            addEmployee(employee);
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
}

void Database::updateSalary(int id, double percent) {
    for (auto& employee : employees) {
        if (employee.getId() == id) {
            double oldSalary = employee.getSalary();
            double newSalary = oldSalary + (oldSalary * percent / 100.0);
            employee.setSalary(newSalary);
            std::cout << "Updated salary for employee " << employee.getFullName()
                      << ": Old salary: " << oldSalary
                      << ", New salary: " << newSalary << std::endl;
            return;
        }
    }
    std::cerr << "Employee with ID " << id << " not found." << std::endl;
}

void Database::removeEmployee(int id) {
    for (auto& employee : employees) {
        if (employee.getId() == id) {
            employee.setIsActive(false);
            std::cout << "Employee " << employee.getFullName() << " marked as inactive." << std::endl;
            return;
        }
    }
    std::cerr << "Employee with ID " << id << " not found." << std::endl;
}
