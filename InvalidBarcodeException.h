#pragma once
#include <exception>


class InvalidBarcodeException
{
private:
	std::string msg;
public:
	InvalidBarcodeException();
	InvalidBarcodeException(std::string barcode);
	~InvalidBarcodeException();

	virtual const char* what() const throw();

};

