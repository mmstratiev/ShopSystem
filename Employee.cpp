#include "stdafx.h"
#include "Employee.h"

const double Employee::MINIMUM_SALARY = 510;
std::unordered_set<int> Employee::ids = { 0 };

Employee::Employee(Name name, double salary)
{
	this->name = name;
	this->setSalary(salary);
	this->setEmployeeRandomID();
}

Employee::Employee(std::string fullName, double salary)
{
	this->name = Name(fullName);
	this->setSalary(salary);
	this->setEmployeeRandomID();
}

Employee::Employee(std::string firstName, std::string secondName, std::string thirdName, double salary)
{
	this->name = Name(firstName, secondName, thirdName);
	this->setSalary(salary);
	this->setEmployeeRandomID();
}


Employee::~Employee()
{

}

double Employee::getSalary() const
{ 
	return this->salary;
}

int Employee::getID() const
{
	return this->employeeID;
}

std::string Employee::getName() const
{
	return this->name.getName();
}

void Employee::setSalary(double salary)
{
	if (validateSalary(salary)) {
		this->salary = salary;
	}
	else {
		this->salary = MINIMUM_SALARY;
	}
}

bool Employee::setEmployeeID(int employeeID)
{
	auto it = Employee::ids.find(employeeID);
	if (it != Employee::ids.end()) {
		return false;
	}

	this->employeeID = employeeID;
	Employee::ids.insert(employeeID);
	return true;
}

void Employee::setEmployeeRandomID()
{
	int id = this->generateID();
	this->employeeID = id;
	Employee::ids.insert(id);
}

bool Employee::operator==(const Employee &i)
{
	if (&i == this) {
		return true;
	}
	if (&i == nullptr) {
		return false;
	}
	if (this->getName().compare(i.getName())) {
		return false;
	}
	return true;
}

bool Employee::validateSalary(double salary)
{
	return salary >= Employee::MINIMUM_SALARY;
}

int Employee::generateID()
{
	int id;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(100000, 999999);

	do {
		id = uni(rng);
	} while ((Employee::ids.find(id)) != Employee::ids.end());

	return id;
}

