/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:53:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/15 17:53:59 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//constructeurs

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {  *this = other;  }
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator = (const BitcoinExchange& other) {  if (this != &other) {} return *this;  }



//methods	
void	BitcoinExchange::convertValue(char* fileName) {
	
	std::ifstream file(fileName);
	if (!file.is_open()) {  throw std::runtime_error("Error: can't open a file");  }
	
	std::string	buffer;

	if (std::getline(file, buffer)) {
		if (buffer != "date | value") {  throw std::runtime_error("Error: wrong format of the header \ndate | value");  }
	}

	while (std::getline(file, buffer)) {

		if (BitcoinExchange::lineIsValid(buffer)) {
			std::cout << "value is valid --->> " << buffer << std::endl;
		}
	}
	file.close();
}

bool	BitcoinExchange::lineIsValid(std::string buffer) {

	std::string	data = copyBeforePipe(buffer);
	std::string	value = copyAfterPipe(buffer);

	if (!dataIsValid(data)) {  return false;  }
	if (!valueIsValid(value)) {  return false;  }

	return true;
}

bool	BitcoinExchange::dataIsValid(std::string data) {  (void)data; return true;  }

bool	BitcoinExchange::valueIsValid(std::string value) {

	if (value == "") {  return false;  }

	std::istringstream	myStream(value);
	if (myStream.fail()) {  return false;  }

	if (value.find(".") != std::string::npos) {
		double	d = 0.0;
		myStream >> d;
		if (BitcoinExchange::outOfLimits(d)) {  return false;  }
	}
	else {
		long	l = 0;
		myStream >> l;
		if (BitcoinExchange::outOfLimits(l)) {  return false;  }
	}
	return true;
}

std::string	BitcoinExchange::copyBeforePipe(std::string s) {

	std::string		copied;
	const unsigned long	position = s.find(" | ");
	
	if (position != std::string::npos) {  copied = s.substr(0, position);  }

	return copied;
}

std::string	BitcoinExchange::copyAfterPipe(std::string s) {


	std::string		copied;
	const unsigned long	position = s.find(" | ");

	if (position != std::string::npos) {  copied = s.substr(position+3, s.length()-position);  }
	
	return copied;
}

template <typename T>
bool	BitcoinExchange::outOfLimits(T number) {

	if (number < 0) {  std::cerr << "Error: value can't be negative" << std::endl; return true;  }
	else if (number > 1000) {  std::cerr << "Error: too large value. Can't be more than 1000" << std::endl; return true;  }

	return false;
};
