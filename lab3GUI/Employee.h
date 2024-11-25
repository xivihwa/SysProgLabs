#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    int id;
    std::string fullName;
    int age;
    std::string gender;
    std::string address;
    std::string passport;
    int positionCode;
    double salary;
    bool isActive;

public:
    Employee(int id, const std::string& fullName, int age, const std::string& gender,
             const std::string& address, const std::string& passport,
             int positionCode, double salary, bool isActive = true);

    // Геттеры
    int getId() const;
    const std::string& getFullName() const;
    int getAge() const;
    const std::string& getGender() const;
    const std::string& getAddress() const;
    const std::string& getPassport() const;
    int getPositionCode() const;
    double getSalary() const;
    bool getIsActive() const;

    // Сеттеры с проверками
    void setFullName(const std::string& fullName);
    void setAge(int age);
    void setGender(const std::string& gender);
    void setAddress(const std::string& address);
    void setPassport(const std::string& passport);
    void setPositionCode(int positionCode);
    void setSalary(double salary);
    void setIsActive(bool isActive);
};

#endif // EMPLOYEE_H
