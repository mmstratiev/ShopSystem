#pragma once
#include <exception>
#include <iostream>
class InvalidNameException : public std::exception
{
private:
	std::string msg;
public:
	InvalidNameException();
	InvalidNameException(std::string name);
	
	virtual const char* what() const throw();
};

