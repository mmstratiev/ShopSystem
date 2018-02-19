#pragma once
#include "InvalidBarcodeException.h"
class ShopProduct
{
public:
	ShopProduct(std::string productName, std::string barcode, double price);
	~ShopProduct();

	//getters
	std::string getProductName() const;
	std::string getBarcode() const;
	double getPrice() const;

    //setter
	void setBarcode(std::string barcode);

	//checks if given barcode(string) contains only numbers
	static bool validateBarcode(std::string barcode);

protected:
	std::string productName;
	std::string barcode;
	int quantity;
	double price;
};

