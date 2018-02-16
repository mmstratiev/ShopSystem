#include <unordered_set>
#include <random>
#include "Name.h"
#pragma once

class Employee
{
private:
	static std::unordered_set<int> ids;
public:

	static const double MINIMUM_SALARY;

	//Note: Constructors with strings can throw InvalidNameException!
	Employee(Name name, double salary);
	Employee(std::string fullName, double salary);
	Employee(std::string firstName, std::string secondName, std::string thirdName, double salary);
	~Employee();

	//getters
	double getSalary() const;
	int getID() const;
	std::string getName() const;

	//setters
	void setSalary(double salary);
	bool setEmployeeID(int employeeID);
	void setEmployeeRandomID();
	//operator overloads
	bool operator==(const Employee &i);

	//validator
	static bool validateSalary(double salary);

	int generateID();

protected:
	int employeeID;
	Name name;
	double salary;
};

