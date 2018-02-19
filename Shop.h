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
    //splits a sting base on the delimiter. Returns vector of substrings
	std::vector<std::string> split(const std::string &stringToSplit, const std::string &delimiter);

	//reads files and populates products/employees
	void readProductsFile(std::string fileName);
	void readEmployeesFile(std::string fileName);

	UI employeesList;
	UI productsList;
public:
	Shop();
	Shop(std::string name, std::string adress);
	~Shop();

	//getters
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

	//initializes the Shop object instance(AKA calls readProductsFile and readEmployeesFile)
	void initialize();

	//saves employees and products to respective files.
	void saveToFile();

	void displayEmployees() const;
	void displayProducts() const;

	//overloaded == operator. compares by Shop->name
	bool operator==(const Shop &i);
protected:
	std::string adress;
	std::string name;

	std::vector<Employee> employees;
	std::unordered_map<std::string, ShopProduct> products;

	int numberOfEmployees;
};

