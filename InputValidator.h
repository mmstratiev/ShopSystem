#pragma once
class InputValidator
{
private:
	std::regex regexPattern;
	int minIntInput;
	int maxIntInput;

	bool isRegexSet;
	bool isIntSet;
public:
	
	InputValidator(std::regex regexPattern);
	InputValidator(int minInput, int maxInput);
	InputValidator(std::regex regexPattern, int minInput, int maxInput);

	~InputValidator();

	void setValidator(std::regex regexPattern);
	void setValidator(int minInput, int maxInput);

	bool validate(std::string input);
};

