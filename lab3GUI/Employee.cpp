#include "Employee.h"
#include <stdexcept>

Employee::Employee(int id, const std::string& fullName, int age, const std::string& gender,
                   const std::string& address, const std::string& passport,
                   int positionCode, double salary, bool isActive)
    : id(id), fullName(fullName), age(age), gender(gender),
    address(address), passport(passport), positionCode(positionCode),
    salary(salary), isActive(isActive) {
    if (age < 0) throw std::invalid_argument("Age cannot be negative.");
    if (salary < 0) throw std::invalid_argument("Salary cannot be negative.");
}

int Employee::getId() const {
    return id;
}

const std::string& Employee::getFullName() const {
    return fullName;
}

int Employee::getAge() const {
    return age;
}

const std::string& Employee::getGender() const {
    return gender;
}

const std::string& Employee::getAddress() const {
    return address;
}

const std::string& Employee::getPassport() const {
    return passport;
}

int Employee::getPositionCode() const {
    return positionCode;
}

double Employee::getSalary() const {
    return salary;
}

bool Employee::getIsActive() const {
    return isActive;
}

void Employee::setFullName(const std::string& fullName) {
    if (fullName.empty()) throw std::invalid_argument("Full name cannot be empty.");
    this->fullName = fullName;
}

void Employee::setAge(int age) {
    if (age < 0) throw std::invalid_argument("Age cannot be negative.");
    this->age = age;
}

void Employee::setGender(const std::string& gender) {
    if (gender != "Male" && gender != "Female") throw std::invalid_argument("Invalid gender.");
    this->gender = gender;
}

void Employee::setAddress(const std::string& address) {
    if (address.empty()) throw std::invalid_argument("Address cannot be empty.");
    this->address = address;
}

void Employee::setPassport(const std::string& passport) {
    if (passport.empty()) throw std::invalid_argument("Passport cannot be empty.");
    this->passport = passport;
}

void Employee::setPositionCode(int positionCode) {
    if (positionCode < 0) throw std::invalid_argument("Position code cannot be negative.");
    this->positionCode = positionCode;
}

void Employee::setSalary(double salary) {
    if (salary < 0) throw std::invalid_argument("Salary cannot be negative.");
    this->salary = salary;
}

void Employee::setIsActive(bool isActive) {
    this->isActive = isActive;
}
