#include "stdafx.h"
#include "ShopSystem.h"

std::vector<std::string> ShopSystem::split(const std::string & stringToSplit, const std::string & delimiter)
{
	size_t  start = 0, end = 0;
	std::vector<std::string> splitString;
	while (end != std::string::npos) {
		end = stringToSplit.find(delimiter, start);

		splitString.push_back(stringToSplit.substr(start,
			(end == std::string::npos) ? std::string::npos : end - start));

		start = ((end > (std::string::npos - delimiter.size()))
			? std::string::npos : end + delimiter.size());
	}

	return splitString;
}


void ShopSystem::readShopsFile(std::string fileName)
{
	std::regex shopsRegex("(.{2,}\|.{2,})(\n|$)");
	std::ifstream inputFile(fileName);
	std::string line;
	int id = 0;

	if (!inputFile.is_open()) {
//		std::cout << "Shops file does not exist!\nCreating..." << std::endl;
		std::ofstream file(fileName);
		return;
	}

	while (std::getline(inputFile, line)) {
		if (std::regex_search(line, shopsRegex)) {
			std::vector<std::string> splittedLine = split(line, "|");

			std::string name = splittedLine.at(0);
			std::string adress = splittedLine.at(1);

			Shop shop = Shop(name, adress);
			
			this->shops.push_back(shop);
		}
	}
	inputFile.close();
}

ShopSystem::ShopSystem()
{
}


ShopSystem::~ShopSystem()
{
}

Shop & ShopSystem::getShopAt(int pos)
{
	return this->shops.at(pos - 1);
}

void ShopSystem::initialize()
{
	std::string shopsFilename = "Shops.txt";

	this->readShopsFile(shopsFilename);

	for (auto &it : this->shops) {
		it.initialize();
		this->shopsList.addOption("Name:[" + it.getName() + "] Adress:[" + it.getAdress()
			+ "] Employees:[" + std::to_string(it.getEmployees().size()) + "]");
	}

	this->mainMenu.addOption("See shops");
	this->mainMenu.addOption("Add shop");
	this->mainMenu.addOption("Remove shop");
	this->mainMenu.addOption("Save and exit");

	this->shopMenu.addOption("See employees");
	this->shopMenu.addOption("See products");
	this->shopMenu.addOption("Add employee");
	this->shopMenu.addOption("Add product");
	this->shopMenu.addOption("Remove employee");
	this->shopMenu.addOption("Remove product");

}

void ShopSystem::saveToFile()
{
	std::string shopsFileName = "Shops.txt";
	std::string backupShopsFile = "backup-" + shopsFileName;

	remove(backupShopsFile.c_str());

	rename(shopsFileName.c_str(), backupShopsFile.c_str());

	std::ofstream shopsFile(shopsFileName);

	for (auto &it : shops) {
		shopsFile << it.getName() << "|" << it.getAdress() << std::endl;
	}

	shopsFile.close();
}

void ShopSystem::addShop(Shop shop)
{
	auto it = std::find(this->shops.begin(), this->shops.end(), shop);
	if (it != this->shops.end()) {
		std::cout << "Shop already exists!" << std::endl;
		return;
	}
	
	shop.initialize();
	this->shops.push_back(shop);
	this->shopsList.addOption("Name:[" + shop.getName() + "] Adress:[" + shop.getAdress()
		+ "] Employees:[" + std::to_string(shop.getEmployees().size()) + "]");

	std::cout << "Shop \"" << shop.getName() << "\" added!" << std::endl;
}

void ShopSystem::removeShop(int shopIndex)
{
	try {
		this->shops.at(shopIndex - 1);
		auto it = this->shops.begin() + shopIndex - 1;
		std::string shopName = it->getName();

		this->shops.erase(it);
		this->shopsList.removeOption(shopIndex);
		
		std::cout << "Shop \"" << shopName << "\" removed!" << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << "Shop not found!" << std::endl;
	}
}

void ShopSystem::displayMainMenu()
{
	this->mainMenu.draw();
}

void ShopSystem::displayShops()
{
	this->shopsList.draw();
}

void ShopSystem::displayShopMenu()
{
	this->shopMenu.draw();
}
