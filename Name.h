#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>

#pragma once

class Name
{
public:
	Name();
	Name(std::string fullName);
	Name(std::string firstName, std::string secondName, std::string thirdName);
	~Name();

	void setName(std::string fullName);
	static bool validateName(std::string fullName);
	std::string getName() const;
protected:
	std::string firstName;
	std::string secondName;
	std::string thirdName;
	std::string fullName;
};

