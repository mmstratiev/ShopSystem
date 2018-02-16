#include "stdafx.h"
#include "Name.h"

Name::Name()
{

}

Name::Name(std::string fullName) 
{
	this->setName(fullName);
}

Name::Name(std::string firstName, std::string secondName, std::string thirdName)
{
	this->setName(firstName + " " + secondName + " " + thirdName);
}

Name::~Name()
{
}

void Name::setName(std::string fullName)
{
	if (!validateName(fullName)) {
		throw InvalidNameException(fullName);
	}
	this->fullName = fullName;
}

bool Name::validateName(std::string fullName)
{
	int counter = 0;
	std::regex nameRegex("^([A-Z][a-z]+\ ){2}[A-Z][a-z]+($|\n)");

	return std::regex_search(fullName, nameRegex);
}

std::string Name::getName() const
{
	return this->fullName;
}
