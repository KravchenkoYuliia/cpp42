/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:47:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/21 14:47:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <iomanip> 

class ScalarConverter {

public:
	static void	convert(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter&	operator = (const ScalarConverter& other);
	~ScalarConverter();

	static int	getType(std::string input);
	static void	convertToChar(std::string input);
	static void	convertToInt(std::string input);
	static void	convertToFloat(std::string input);
	static void	convertToDouble(std::string input);
	static void	convertToPseudo(std::string input);

	static void	printChar(int c);
	static void	printIntAndChar(long l);
	static void	printFloat(double d, long l);
	static void	printDouble(double d, long l);


	static bool	isChar(std::string input);
	static bool	isInt(std::string input);
	static bool	isFloat(std::string input);
	static bool	isDouble(std::string input);
	static bool	isPseudoLiteral(std::string input);
	static bool	stringIsDigit(std::string input, int start);
};

#endif
