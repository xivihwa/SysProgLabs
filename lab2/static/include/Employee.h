#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
public:
    Employee();
    Employee(int id, std::string fullName, int age, std::string gender, std::string address, std::string passport, int positionCode, double salary);

    int getId() const;
    void setId(int id);

    std::string getFullName() const;
    void setFullName(std::string fullName);

    int getAge() const;
    void setAge(int age);

    std::string getGender() const;
    void setGender(std::string gender);

    std::string getAddress() const;
    void setAddress(std::string address);

    std::string getPassport() const;
    void setPassport(std::string passport);

    int getPositionCode() const;
    void setPositionCode(int positionCode);

    double getSalary() const;
    void setSalary(double salary);

    bool getIsActive() const;
    void setIsActive(bool active);

    void display() const;

private:
    int mId;
    std::string mFullName;
    int mAge;
    std::string mGender;
    std::string mAddress;
    std::string mPassport;
    int mPositionCode;
    double mSalary; 
    bool isActive;  
};

#endif
