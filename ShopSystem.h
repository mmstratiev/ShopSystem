#pragma once
#include <exception>
class ShopSystem
{
private:
	std::vector<Shop> shops;
	UI mainMenu;
	UI shopsList;
	//TODO: change shopMenu UI component to a static member of Shop class
	UI shopMenu;

	//reads the file and populates shops
	void readShopsFile(std::string fileName);

	//splits a string
	std::vector<std::string> split(const std::string & stringToSplit, const std::string & delimiter);
public:
	ShopSystem();
	~ShopSystem();

	//get shop by reference
	Shop& getShopAt(int pos);

	//initializes the ShopSystem instance - calls readShopsFile and the initialize function for every shop in shops vector
	void initialize();

	//saves shops to file
	void saveToFile();

	void addShop(Shop shop);
	void removeShop(int shopIndex);

	//calls the UI members' draw() function
	void displayMainMenu();
	void displayShops();
	void displayShopMenu();
};

