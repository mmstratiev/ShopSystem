#include <map>
#pragma once

class UI
{
private:
	int numberOfOptions;
	std::vector <std::string> options;
public:
	UI();
	~UI();

	std::string getOption(int optionIndex) const;
	const std::vector<std::string> & getOptions() const;

	void addOption(std::string optionDescription);
	void addOption(std::string optionDescription, int optionNumber);
	void removeOption(int optionNumber);

	//displays all options on the console
	void draw() const;
};

