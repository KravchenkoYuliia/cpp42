/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:47:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/21 14:47:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6
#define ERROR 1

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {

	if (this != &other) {}
	return *this;
}

ScalarConverter::~ScalarConverter() {}



//methods

void	ScalarConverter::convert(std::string input) {

	std::cout << "Your input is [" << input << "]" << std::endl;

	int	type = ScalarConverter::getType(input);

	switch (type) {

		case CHAR:
			convertToChar(input);
			break;
		case INT:
			convertToInt(input);
			break;
		case FLOAT:
			convertToFloat(input);
			break;
		case DOUBLE:
			convertToDouble(input);
			break;
		default:
			std::cout << "Error: Unknown data type" << std::endl << "Put [int]/[char]/[float]/[double]" << std::endl;
	}

}

int	ScalarConverter::getType(std::string input) {

	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (input[0] == '+' || input[0] == '-' || std::isdigit(input[0])) {

		if ((input[0] == '+' || input[0] == '-') && !std::isdigit(input[1]))
			return ERROR;
		if (ScalarConverter::isInt(input))
			return INT;
		if (ScalarConverter::isFloat(input))
			return FLOAT;
		if (ScalarConverter::isDouble(input))
			return DOUBLE;
	}

	return ERROR;
}

void	ScalarConverter::convertToChar(std::string input) {

	(void)input;
	std::cout << "Convert input to char and other types" << std::endl;
}

void	ScalarConverter::convertToInt(std::string input) {

	(void)input;
	std::cout << "Convert input to int and other types" << std::endl;
}

void	ScalarConverter::convertToFloat(std::string input) {

	(void)input;
	std::cout << "Convert input to float and other types" << std::endl;
}

void	ScalarConverter::convertToDouble(std::string input) {

	(void)input;
	std::cout << "Convert input to double and other types" << std::endl;
}

//bool methods
//
bool	ScalarConverter::isInt(std::string input) {

	int	start = 0;
	
	if (input[0] == '+' || input[0] == '-')
		start++;
	if (stringIsDigit(input, start))
		return true;
	return false;
}

bool	ScalarConverter::stringIsDigit(std::string input, int start) {

	for (size_t i = start; i < input.length(); i++) {
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloat(std::string input) {

	int	dot = 0;
	int	len = input.length();

	if (input[len - 1] != 'f')
		return false;

	for (int i = 0; i < len; i++) {
	
		if (!std::isdigit(input[i])) {
			if (input[i] == '.')
				dot++;
			if (input[i] == 'f' && input[i + 1])
				return false;
			if (input[i] != '.' && input[i] != 'f')
				return false;
		}
	}
	if (dot != 1)
		return false;
	return true;
}

bool	ScalarConverter::isDouble(std::string input) {

	int dot = 0;

	for (size_t i = 0; i < input.length(); i++) {
	
		if (!std::isdigit(input[i])) {

			if (input[i] == '.')
				dot++;
			else
				return false;
		}
	}

	if (dot != 1)
		return false;

	return true;
}
