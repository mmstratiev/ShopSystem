#include "stdafx.h"
#include "InvalidBarcodeException.h"


InvalidBarcodeException::InvalidBarcodeException()
{
}

InvalidBarcodeException::InvalidBarcodeException(std::string barcode)
{
	this->msg = "\"" + barcode + "\" " + "is not a valid barcode! Barcode should contain only numbers!";
}


InvalidBarcodeException::~InvalidBarcodeException()
{
	this->msg = "Invalid barcode! Barcode should contain only numbers!";
}

const char * InvalidBarcodeException::what() const throw()
{
	return this->msg.c_str();
}
