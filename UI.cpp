#include "stdafx.h"
#include "UI.h"


UI::UI()
{
	//this->addOption("Exit");
}


UI::~UI()
{
}

std::string UI::getOption(int optionIndex) const
{
	return this->options.at(optionIndex-1);
}

const std::vector<std::string> & UI::getOptions() const
{
	return this->options;
}

void UI::addOption(std::string optionDescription)
{
	this->options.push_back(optionDescription);
}

void UI::addOption(std::string optionDescription, int optionNumber)
{
	if (optionNumber > this->options.size() || optionNumber <= 0) {
		return;
	}
	auto it = this->options.begin();
	it += optionNumber-1;
	this->options.insert(it, optionDescription);
}

void UI::removeOption(int optionNumber)
{
	if (optionNumber > this->options.size() || optionNumber <= 0) {
		return;
	}

	auto it = this->options.begin();
	it += optionNumber - 1;
	
	this->options.erase(it);
}

void UI::draw() const
{
	for (int i = 0; i < this->options.size(); i++) {
		std::cout << i+1 << ": " << this->options.at(i) << std::endl;
	}
}
