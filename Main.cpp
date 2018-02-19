// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void drawLine();
void shopMenu(Shop& shop, ShopSystem& ss);
void shopsMenu(ShopSystem& shopSystem);

int main()
{
	int mainMenuChoice = 0;
	std::string inputString, inputString2, inputLine, inputLine2;
	int inputInt;
	ShopSystem ss = ShopSystem();
	ss.initialize();

	while (mainMenuChoice != 4) {
		ss.displayMainMenu();
		std::getline(std::cin, inputLine);
		try {
			mainMenuChoice = std::stoi(inputLine);

			switch (mainMenuChoice) {
			case 1:
				shopsMenu(ss);
				break;
			case 2:
				std::cout << "Enter shop name: ";
				std::getline(std::cin, inputLine);
				std::cout << "Enter shop adress: ";
				std::getline(std::cin, inputLine2);
				drawLine();
				ss.addShop(Shop(inputLine, inputLine2));
				break;
			case 3:
				std::cout << "Enter shop to remove(1, 2, 3..): ";
				std::getline(std::cin, inputLine);
				inputInt = std::stoi(inputLine);
				drawLine();
				ss.removeShop(inputInt);
				break;
			}
		}

		catch (std::invalid_argument &e) {
			drawLine();
			std::cout << "Invalid input!" << std::endl;
		}
		drawLine();
	}
	ss.saveToFile();
	return 0;
}


void shopsMenu(ShopSystem& shopSystem) {
	int shopsMenuChoice = 1;
	std::string inputLine;

	while (shopsMenuChoice != 0) {
		drawLine();
		std::cout << "Choose shop: " << std::endl << "0: Back" << std::endl;
		shopSystem.displayShops();

		try {
			std::getline(std::cin, inputLine);
			shopsMenuChoice = std::stoi(inputLine);

			if (shopsMenuChoice != 0) {
				Shop& it = shopSystem.getShopAt(shopsMenuChoice);
				shopMenu(it, shopSystem);
			}
		}
		catch (std::out_of_range &ex) {
			drawLine();
			std::cout << "Shop not found!" << std::endl;
		}
		catch (std::invalid_argument &e) {
			drawLine();
			std::cout << "Invalid input!" << std::endl;
		}
	}
}

void shopMenu(Shop& shop, ShopSystem& ss) {
	int shopChoice = 1, intInput;
	std::string inputLine, inputLine2, inputLine3;
	double doubleInput;

	while (shopChoice != 0) {
		drawLine();

		std::cout << "0: Back" << std::endl;
		ss.displayShopMenu();
		try {
			std::getline(std::cin, inputLine);
			shopChoice = std::stoi(inputLine);

			switch (shopChoice) {
			case 1:
				drawLine();
				shop.displayEmployees();
				break;
			case 2:
				drawLine();
				shop.displayProducts();
				break;
			case 3:
				std::cout << "Enter name(format: Xxx Xxx Xxx): ";
				std::getline(std::cin, inputLine);
				std::cout << "Enter salary: ";
				std::getline(std::cin, inputLine2);
				doubleInput = std::stod(inputLine2);

				drawLine();
				shop.addEmployee(Employee(inputLine, doubleInput));
				break;
			case 4:
				std::cout << "Enter name: ";
				std::getline(std::cin, inputLine);
				std::cout << "Enter barcode: ";
				std::getline(std::cin, inputLine2);
				std::cout << "Enter price: ";
				std::getline(std::cin, inputLine3);
				doubleInput = std::stod(inputLine3);

				drawLine();
				shop.addProduct(ShopProduct(inputLine, inputLine2, doubleInput));
				break;
			case 5:
				std::cout << "Enter employee number: ";
				std::getline(std::cin, inputLine);
				intInput = std::stoi(inputLine);
				shop.removeEmployee(intInput - 1);
				break;
			case 6:
				std::cout << "Enter product barcode: ";
				std::getline(std::cin, inputLine);
				shop.removeProduct(inputLine);
				break;
			}
		}
		catch (const std::invalid_argument &e) {
			drawLine();
			std::cout << "Invalid input!" << std::endl;
		}
		catch (const InvalidBarcodeException &e) {
			drawLine();
			std::cout << e.what() << std::endl;
		}
		catch (const InvalidNameException &e) {
			drawLine();
			std::cout << e.what() << std::endl;
		}
	}
	shop.saveToFile();
}


void drawLine() {
	for (int i = 0; i < 15; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}
