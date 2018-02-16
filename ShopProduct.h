#pragma once
#include "InvalidBarcodeException.h"
class ShopProduct
{
public:
	ShopProduct(std::string productName, std::string barcode, double price);
	~ShopProduct();

	std::string getProductName() const;
	std::string getBarcode() const;
	double getPrice() const;


	void setBarcode(std::string barcode);

	static bool validateBarcode(std::string barcode);

protected:
	std::string productName;
	std::string barcode;
	int quantity;
	double price;
};

