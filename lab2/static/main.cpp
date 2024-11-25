#include "../static/include/Database.h"
#include <memory>
#include <iostream>

void addEmployeeFromConsole(Database& db) {
    int id, age, positionCode;
    double salary;
    std::string fullName, gender, address, passport;

    std::cout << "Enter the employee code: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter the full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Enter the age: ";
    std::cin >> age;
    std::cin.ignore();

    std::cout << "Enter the gender: ";
    std::getline(std::cin, gender);

    std::cout << "Enter the address: ";
    std::getline(std::cin, address);

    std::cout << "Enter the passport information: ";
    std::getline(std::cin, passport);

    std::cout << "Enter the position code: ";
    std::cin >> positionCode;

    std::cout << "Enter the salary: ";
    std::cin >> salary;

    Employee employee(id, fullName, age, gender, address, passport, positionCode, salary);
    db.addEmployee(employee);

    std::cout << "Employee added successfully!" << std::endl;
}

int main() {
    Database db;
    db.loadFromFile("employees.txt");

    char choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Add new employee\n"
                  << "2. Display all employees\n"
                  << "3. Remove an employee (mark as inactive)\n"
                  << "4. Update employee salary\n"
                  << "5. Save and exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case '1':
                addEmployeeFromConsole(db);
                break;
            case '2':
                db.displayEmployees();
                break;
            case '3': {
                int id;
                std::cout << "Enter the ID of the employee to remove: ";
                std::cin >> id;
                db.removeEmployee(id);
                break;
            }
            case '4': {
                int id;
                double percent;
                std::cout << "Enter the ID of the employee: ";
                std::cin >> id;
                std::cout << "Enter the percentage to update salary in % (positive to increase, negative to decrease): ";
                std::cin >> percent;
                db.updateSalary(id, percent);
                break;
            }
            case '5':
                db.saveToFile("employees.txt");
                std::cout << "Data saved. Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '5');

    return 0;
}
