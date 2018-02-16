#pragma once
#include <exception>
class ShopSystem
{
private:
	std::vector<Shop> shops;
	UI mainMenu;
	UI shopsList;
	UI shopMenu;

	void readShopsFile(std::string fileName);
	std::vector<std::string> split(const std::string & stringToSplit, const std::string & delimiter);
public:
	ShopSystem();
	~ShopSystem();

	Shop& getShopAt(int pos);

	void initialize();
	void saveToFile();

	void addShop(Shop shop);
	void removeShop(int shopIndex);

	void displayMainMenu();
	void displayShops();
	void displayShopMenu();
};

