#include "stdafx.h"
#include "ShopProduct.h"

ShopProduct::ShopProduct(std::string productName, std::string barcode, double price)
{
	this->setBarcode(barcode);

	this->productName = productName;
	this->price = price;
}

ShopProduct::~ShopProduct()
{
}

std::string ShopProduct::getProductName() const
{
	return this->productName;
}

std::string ShopProduct::getBarcode() const
{
	return this->barcode;
}

double ShopProduct::getPrice() const
{
	return this->price;
}

void ShopProduct::setBarcode(std::string barcode)
{
	if (!validateBarcode(barcode)) {
		throw InvalidBarcodeException(barcode);
	}
	this->barcode = barcode;
}

bool ShopProduct::validateBarcode(std::string barcode)
{
	std::regex barcodeRegex("^[1-9]+($|\n)");
	
	return std::regex_search(barcode, barcodeRegex);
}
