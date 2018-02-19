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

	//setter
	void setName(std::string fullName);

	//checks if a name is in format of Xxx Xxx Xxx
	static bool validateName(std::string fullName);

	//getter
	std::string getName() const;
protected:
    //protected for possible future use in inherited classes, could change to private
	std::string firstName;
	std::string secondName;
	std::string thirdName;
	std::string fullName;
};

