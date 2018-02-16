#include "stdafx.h"
#include "InvalidNameException.h"

InvalidNameException::InvalidNameException()
{
	this->msg = "You have entered an invalid name. Name should be \"Firstname Secondname Thirdname\"";
}

InvalidNameException::InvalidNameException(std::string name)
{
	this->msg = "\"" + name + "\"" + " is not a valid name. Name should be \"Firstname Secondname Thirdname\".";
}

const char * InvalidNameException::what() const throw()
{
	return this->msg.c_str();
}
