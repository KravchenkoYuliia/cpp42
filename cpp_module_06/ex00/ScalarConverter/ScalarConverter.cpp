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
#define PSEUDO 7
#define ERROR -1
#define OUT_OF_LIM -2147483649

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {

	if (this != &other) {}
	return *this;
}

ScalarConverter::~ScalarConverter() {}



//methods

void	ScalarConverter::convert(std::string input) {

	std::cout << "Your input is [" << input << "]" << std::endl << std::endl;

	int	type = ScalarConverter::getType(input);

	switch (type) {

		case CHAR:
			convertToChar(input);
			break;
		case INT:
			convertToInt(input);
			break;
		case PSEUDO:
			convertToPseudo(input);
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

	if (ScalarConverter::isChar(input)) { return CHAR; }
	if (ScalarConverter::isPseudoLiteral(input)) { return PSEUDO; }

	if (input[0] == '+' || input[0] == '-' || std::isdigit(input[0])) {

		if ((input[0] == '+' || input[0] == '-') && !std::isdigit(input[1])) { return ERROR; }
		
		if (ScalarConverter::isFloat(input)) { return FLOAT; }
		if (ScalarConverter::isDouble(input)) { return DOUBLE; }
		if (ScalarConverter::isInt(input)) { return INT; }
	}

	return ERROR;
}


//CONVERT TO <TYPE>
//
//

void	ScalarConverter::convertToPseudo(std::string input) {

	if (input == "-inff" || input == "+inff"
	  || input == "inff" || input == "nanf") {

		std::cout << "char: impossible" << std::endl
			 << "int: impossible" << std::endl
			 << "float: " << input << std::endl
			 << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	
	else if (input == "-inf" || input == "+inf"
	  || input == "inf" || input == "nan") {

		std::cout << "char: impossible" << std::endl
			 << "int: impossible" << std::endl
			 << "float: " << input << "f" << std::endl
			 << "double: " << input << std::endl;
	
	}
}

void	ScalarConverter::convertToChar(std::string input) {

	char	c = '\0';
	if (input.length() == 1)
		c = input[0];
	else if (input.length() == 3)
		c = input[1];

	ScalarConverter::printChar(static_cast<int>(c));
	std::cout << "int: " << static_cast<int>(c) << std::endl
		  << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl
	          << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::convertToInt(std::string input) {

	long	l = 0;

	std::istringstream	myStream(input);
	if (myStream.fail())
			return ;
	if (myStream.good())
		myStream >> l;
	
	ScalarConverter::printIntAndChar(l);

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(l) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(l) << std::endl;
}

void	ScalarConverter::convertToFloat(std::string input) {

	double	d = 0;
	
	std::istringstream	myStream(input);
	if (myStream.fail())
		return ;
	
	if (myStream.good())
		myStream >> d;
	
	long l = d;
	
	ScalarConverter::printIntAndChar(l);
	ScalarConverter::printFloat(d, l);
	ScalarConverter::printDouble(d, l);
}

void	ScalarConverter::convertToDouble(std::string input) {

	double			d = 0;
	std::istringstream	myStream(input);
	if (myStream.fail())
		return ;
	if (myStream.good())
		myStream >> d;
	long	l = d;
	
	ScalarConverter::printIntAndChar(l);
	
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) { std::cout << "float: impossible" << std::endl; }
	else { ScalarConverter::printFloat(d, l); }
	
	ScalarConverter::printDouble(d, l);
}

//PRINT <TYPE>
//

void	ScalarConverter::printChar(int c) {

	if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c) || c == ' ')
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " <<  "'" << static_cast<char>(c) << "'" << std::endl;
}

void	ScalarConverter::printIntAndChar(long l) {


	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min()) { std::cout << "char: impossible" << std::endl << "int: impossible" << std::endl; }
	else {
		ScalarConverter::printChar(static_cast<int>(l));
		std::cout << "int: " << static_cast<int>(l) << std::endl;	
	}
}

void	ScalarConverter::printFloat(double d, long l) {

	if (d - l == 0)	
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f";
	else
		std::cout << "float: " << static_cast<float>(d) << "f";

	std::cout << std::endl;
}

void	ScalarConverter::printDouble(double d, long l) {

	if (d - l == 0)
		std::cout << "double: " << std::fixed << std::setprecision(1) << d;
	else
		std::cout << "double: " << d;

	std::cout << std::endl;
}

//BOOL IS<TYPE>
//
bool	ScalarConverter::isChar(std::string input) {

	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	if (input.length() == 3 && input[0] == 39 && input[2] == 39 && !std::isdigit(input[1]))
		return true;
	return false;
}

bool	ScalarConverter::isInt(std::string input) {

	int	start = 0;
	
	if (input[0] == '+' || input[0] == '-')
		start++;
	if (stringIsDigit(input, start))
		return true;
	return false;
}

bool	ScalarConverter::isPseudoLiteral(std::string input) {

	if (input == "-inff" || input == "+inff"
	  || input == "inff" || input == "nanf") { return true; }
	
	if (input == "-inf" || input == "+inf"
	  || input == "inf" || input == "nan") { return true; }
	
	return false;
}

bool	ScalarConverter::isFloat(std::string input) {

	int	dot = 0;
	int	len = input.length();

	if (input[len - 1] != 'f')
		return false;

	int	start = 0;

	if (input[0] == '+' || input[0] == '-')
		start++;
	for (int i = start; i < len; i++) {
	
		if (!std::isdigit(input[i])) {
			if (input[i] == '.')
				dot++;
			if (input[i] == 'f' && input[i + 1])
				return false;
			if (input[i] != '.' && input[i] != 'f')
				return false;
		}
	}
	if (dot != 1) { return false; }

	return true;
}

bool	ScalarConverter::isDouble(std::string input) {

	
	int	dot = 0;
	int	start = 0;

	if (input[0] == '+' || input[0] == '-')
		start++;
	for (size_t i = start; i < input.length(); i++) {
	
		if (!std::isdigit(input[i])) {

			if (input[i] == '.') { dot++; }
			else { return false; }
		}
	}

	if (dot != 1) { return false; }

	return true;
}

bool	ScalarConverter::stringIsDigit(std::string input, int start) {

	for (size_t i = start; i < input.length(); i++) {
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}
