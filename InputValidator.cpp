#include "stdafx.h"
#include "InputValidator.h"



InputValidator::InputValidator(std::regex regexPattern)
{
	this->setValidator(regexPattern);
}

InputValidator::InputValidator(int minInput, int maxInput)
{
	this->setValidator(minInput, maxInput);
}

InputValidator::InputValidator(std::regex regexPattern, int minInput, int maxInput)
{
	this->setValidator(regexPattern);
	this->setValidator(minInput, maxInput);
}

InputValidator::~InputValidator()
{
}

void InputValidator::setValidator(std::regex regexPattern)
{
	this->regexPattern = regexPattern;
	this->isRegexSet = true;
}

void InputValidator::setValidator(int minIntInput, int maxIntInput)
{
	this->minIntInput = minIntInput;
	this->maxIntInput = maxIntInput;
	this->isIntSet = true;
}

bool InputValidator::validate(std::string input)
{
	if (this->isIntSet) {
		int inputToInt;
		try {
			inputToInt = std::stoi(input);

			if (inputToInt >= this->minIntInput && inputToInt <= this->maxIntInput) {
				return true;
			}
		}
		catch (const std::invalid_argument& e) {

		}
		catch (const std::out_of_range& e) {

		}
	}
	if (this->isRegexSet) {
		if (std::regex_search(input, this->regexPattern)) {
			return true;
		}
	}
	return false;
}
