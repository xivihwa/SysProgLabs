#include "../include/Employee.h"

Employee::Employee() : mId(0), mFullName(""), mAge(0), mGender(""), mAddress(""), mPassport(""), mPositionCode(0), mSalary(0.0), isActive(true) {}

Employee::Employee(int id, std::string fullName, int age, std::string gender, std::string address, std::string passport, int positionCode, double salary)
    : mId(id), mFullName(fullName), mAge(age), mGender(gender), mAddress(address), mPassport(passport), mPositionCode(positionCode), mSalary(salary), isActive(true) {}

int Employee::getId() const { return mId; }
void Employee::setId(int id) { mId = id; }

std::string Employee::getFullName() const { return mFullName; }
void Employee::setFullName(std::string fullName) { mFullName = fullName; }

int Employee::getAge() const { return mAge; }
void Employee::setAge(int age) { mAge = age; }

std::string Employee::getGender() const { return mGender; }
void Employee::setGender(std::string gender) { mGender = gender; }

std::string Employee::getAddress() const { return mAddress; }
void Employee::setAddress(std::string address) { mAddress = address; }

std::string Employee::getPassport() const { return mPassport; }
void Employee::setPassport(std::string passport) { mPassport = passport; }

int Employee::getPositionCode() const { return mPositionCode; }
void Employee::setPositionCode(int positionCode) { mPositionCode = positionCode; }

double Employee::getSalary() const { return mSalary; }
void Employee::setSalary(double salary) { mSalary = salary; }

bool Employee::getIsActive() const { return isActive; }
void Employee::setIsActive(bool active) { isActive = active; }

void Employee::display() const {
    std::cout << "Employee code: " << mId
              << "\nFull name: " << mFullName
              << "\nAge: " << mAge
              << "\nGender: " << mGender
              << "\nAddress: " << mAddress
              << "\nPassport: " << mPassport
              << "\nPosition code: " << mPositionCode
              << "\nSalary: " << mSalary
              << "\nStatus: " << (isActive ? "Active" : "Inactive")
              << std::endl;
}
