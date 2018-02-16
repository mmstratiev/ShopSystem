#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <unordered_map>
#include "ShopProduct.h"
#include "UI.h"
class Shop
{
private:
	std::vector<std::string> split(const std::string &stringToSplit, const std::string &delimiter);

	void readProductsFile(std::string fileName);
	void readEmployeesFile(std::string fileName);

	UI employeesList;
	UI productsList;
public:
	Shop();
	Shop(std::string name, std::string adress);
	~Shop();

	std::string getAdress() const;
	std::string getName() const;
	const std::vector<Employee>& getEmployees() const;
	const std::unordered_map<std::string, ShopProduct>& getProducts() const;
	void addProduct(ShopProduct shopProduct);
	void removeProduct(ShopProduct const &shopProduct);
	void removeProduct(std::string barcode);

	bool removeEmployee(Employee const &employee);
	bool removeEmployee(int employeeIndex);
	void addEmployee(Employee employee);

	void initialize();
	void saveToFile();

	void displayEmployees() const;
	void displayProducts() const;

	bool operator==(const Shop &i);
protected:
	std::string adress;
	std::string name;

	std::vector<Employee> employees;
	std::unordered_map<std::string, ShopProduct> products;

	int numberOfEmployees;
};

