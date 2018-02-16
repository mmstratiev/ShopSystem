#include "stdafx.h"
#include "Shop.h"


std::vector<std::string> Shop::split(const std::string & stringToSplit, const std::string & delimiter)
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

Shop::Shop()
{
}

Shop::Shop(std::string name, std::string adress)
{
	this->name = name;
	this->adress = adress;
	//this->initialize();
}


Shop::~Shop()
{
	//this->saveToFile();
	//std::cout << this->name;
}

std::string Shop::getAdress() const
{
	return this->adress;
}

std::string Shop::getName() const
{
	return this->name;
}

const std::vector<Employee>& Shop::getEmployees() const
{
	return this->employees;
}

const std::unordered_map<std::string, ShopProduct>& Shop::getProducts() const
{
	return this->products;
}


void Shop::addProduct(ShopProduct shopProduct)
{
	std::string barcode = shopProduct.getBarcode();
	auto it = this->products.find(barcode);
	bool doesProductExist = (it != this->products.end());
	std::string userChoice;

	if(doesProductExist) {
		std::cout << "Product already exists, do you want to override it? y/n" << std::endl;
		while (userChoice != "y" && userChoice != "n") {
			std::getline(std::cin, userChoice);
		}
		if (userChoice == "y") {
			it->second = shopProduct;
			std::cout << "Product changed!" << std::endl;
		}
		else {
			std::cout << "Adding product canceled!" << std::endl;
		}
	}
	else {
		this->products.insert(std::pair<std::string, ShopProduct>(barcode, shopProduct));
		this->productsList.addOption("Barcode:[" + barcode + "] Name:[" + shopProduct.getProductName()
			+ "] Price:[" + std::to_string(shopProduct.getPrice()) + "]");
		std::cout << "Product \""<< shopProduct.getProductName() << "\" added!" << std::endl;
	}
}

void Shop::removeProduct(ShopProduct const & shopProduct)
{
	std::string barcode = shopProduct.getBarcode();
	auto it = this->products.find(barcode);

	if (it == this->products.end()) {
		std::cout << "Product removal canceled: Product not found!" << std::endl;
		return;
	}
	this->products.erase(barcode);
}

void Shop::removeProduct(std::string barcode)
{
	auto it = this->products.find(barcode);

	if (it == this->products.end()) {
		std::cout << "Product removal canceled: Product not found!" << std::endl;
		return;
	}
	this->products.erase(barcode);
}

bool Shop::removeEmployee(Employee const &employee)
{
	auto it = std::find(this->employees.begin(), this->employees.end(), employee);
	if (it == this->employees.end()) {
		std::cout << "Employee removal canceled: Employee not found!" << std::endl;
		return false;
	}
	employees.erase(it);
	return true;
}

bool Shop::removeEmployee(int employeeIndex)
{
	if (employeeIndex < 0 || employeeIndex > this->employees.size()) {
		std::cout << "Employee removal canceled: Employee not found!" << std::endl;
		return false;
	}
	auto it = this->employees.begin() + employeeIndex;
	this->employees.erase(it);
	this->employeesList.removeOption(employeeIndex + 1);
	return true;
}

void Shop::addEmployee(Employee employee)
{
	auto it = std::find(this->employees.begin(), this->employees.end(), employee);

	if (it != this->employees.end()) {
		std::cout << "Note: Employee with this name already exists, possible duplication." << std::endl;
	}

	this->employees.push_back(employee);
	this->employeesList.addOption("ID:[" + std::to_string(employee.getID()) + "] Name:[" + employee.getName()
		+ "] Salary:[" + std::to_string(employee.getSalary()) + "]");
	std::cout << "Employee \"" << employee.getName() << "\" added!" << std::endl;
}

void Shop::readProductsFile(std::string fileName)
{
	std::ifstream inputFile(fileName);
	std::string line;
	int id = 0;

	if (!inputFile.is_open()) {
//		std::cout << "Products file does not exist!\nCreating..." << std::endl;
		std::ofstream file(fileName);
		return;
	}

	while (std::getline(inputFile, line)) {
		std::regex productsRegex("[0-9]+\|[^\|]+\|([0-9]+\.[0-9]+|[0-9]+)(\n|$)");

		if (std::regex_search(line, productsRegex)) {
			std::vector<std::string> splittedLine = split(line, "|");
			  
			std::string productBarcode = splittedLine.at(0);
			std::string productName = splittedLine.at(1);
			double productPrice = std::stod(splittedLine.at(2));

			ShopProduct shopProduct(productName, productBarcode, productPrice);
			this->productsList.addOption("Barcode:[" + productBarcode + "] Name:[" + productName
				+ "] Price:[" + std::to_string(productPrice) + "]");
			this->products.insert(std::pair<std::string, ShopProduct>(productBarcode, shopProduct));
		}
	}
}

void Shop::readEmployeesFile(std::string fileName)
{
	std::regex employeesRegex("[0-9]+(\ [A-Z][a-z]{1,}){3}(\ [0-9]+\.[0-9]+|\ [0-9]+)(\n|$)");
	std::ifstream inputFile(fileName);
	std::string line;
	int id = 0;

	if(!inputFile.is_open()){
		std::ofstream file(fileName);
		return;
	}

	while (std::getline(inputFile, line)) {
		if (std::regex_search(line, employeesRegex)) {
			std::vector<std::string> splittedLine = split(line, " ");

			id = std::stoi(splittedLine.at(0));
			std::string name = splittedLine.at(1) + " " +
				splittedLine.at(2) + " " +
				splittedLine.at(3);

			double salary = std::stod(splittedLine.at(4));

			Employee employee(name, salary);
			if (!employee.setEmployeeID(id)) {
				employee.setEmployeeRandomID();
			}

			this->employees.push_back(employee);
			this->employeesList.addOption("ID:[" + std::to_string(employee.getID()) + "] Name:[" + name
				+ "] Salary:[" + std::to_string(salary) + "]");
		}
	}
	inputFile.close();
}

void Shop::initialize()
{
	std::string employeesFileName = this->name + "-" + "Employees.txt";
	std::string productsFileName = this->name + "-" + "Products.txt";

	this->readEmployeesFile(employeesFileName);
	this->readProductsFile(productsFileName);
}

void Shop::saveToFile()
{
	std::string employeesFileName = this->name + "-" + "Employees.txt";
	std::string productsFileName = this->name + "-" + "Products.txt";
	std::string backupEmployeesFile = "backup-" + employeesFileName;
	std::string backupProductsFile = "backup-" + productsFileName;

	remove(backupEmployeesFile.c_str());
	remove(backupProductsFile.c_str());

	rename(employeesFileName.c_str(), backupEmployeesFile.c_str());
	rename(productsFileName.c_str(), backupProductsFile.c_str());

	std::ofstream employeesFile(employeesFileName);
	std::ofstream productsFile(productsFileName);

	for (auto &it = this->employees.begin(); it != this->employees.end(); ++it) {
		employeesFile << it->getID() << " " << it->getName() << " " << it->getSalary() << std::endl;
	}

	for (auto &it : this->products) {
		productsFile << it.first << "|" << it.second.getProductName() << "|" << it.second.getPrice() << std::endl;
	}
	employeesFile.close();
	productsFile.close();
}

void Shop::displayEmployees() const
{
	std::cout << "Employees of " << this->getName() << " are:" << std::endl;
	this->employeesList.draw();
}

void Shop::displayProducts() const
{
	std::cout << "Products of " << this->getName() << " are:" << std::endl;
	this->productsList.draw();
}

bool Shop::operator==(const Shop & i)
{
	return (this->getName() == i.getName() && this->getAdress() == i.getAdress());
}

