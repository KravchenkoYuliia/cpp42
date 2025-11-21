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

class ScalarConverter {

public:
	static void	convert(std::string input);
	static int	getType(std::string input);
	static void	convertToChar(std::string input);
	static void	convertToInt(std::string input);
	static void	convertToFloat(std::string input);
	static void	convertToDouble(std::string input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter&	operator = (const ScalarConverter& other);
	~ScalarConverter();

};

#endif
