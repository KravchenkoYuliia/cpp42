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
