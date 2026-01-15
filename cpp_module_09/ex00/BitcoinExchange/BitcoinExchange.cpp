/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:53:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/18 16:59:03 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//constructeurs

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange( char* toConvert  ) {  BitcoinExchange::convertValue(toConvert);  }
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {  *this = other;  }
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator = (const BitcoinExchange& other) {  if (this != &other) {} return *this;  }



//methods	
void	BitcoinExchange::convertValue( char* fileName ) {
	
	std::map<std::string, double>	rateMap;
	BitcoinExchange::insertRateToMap(rateMap);


	std::ifstream file(fileName);
	if (!file.is_open()) {  throw std::runtime_error("Error: can't open a file from arguments");  }
	
	std::string	buffer;

	if (std::getline(file, buffer)) {
		if (buffer != "date | value") {  throw std::runtime_error("Error: wrong format of the header \ndate | value");  }
	}

	while (std::getline(file, buffer)) {

		if (BitcoinExchange::lineIsValid(buffer)) {
			BitcoinExchange::convertValueInLine(rateMap, buffer);
		}
	}
	file.close();
}

void	BitcoinExchange::convertValueInLine(std::map<std::string, double>& rateMap, std::string lineToConvert) {

	std::string	data = copyBeforePipe(lineToConvert);
	std::string	valueStr = copyAfterPipe(lineToConvert);
	
	double	valueDouble = 0.0;
	BitcoinExchange::stringToNumber(valueStr, valueDouble);
	
	std::map<std::string, double>::const_iterator	it = rateMap.begin();

	it = rateMap.lower_bound(data);

	if ( it != rateMap.end() ) {

		if ( data != it->first ) {

			if ( it != rateMap.begin() ) 
				--it;
		}
	}
	else { 
		it = rateMap.end();
		if ( !rateMap.empty() )
			--it;
	}

	std::cout << data << " => " << valueStr << " = " << it->second*valueDouble << std::endl;

}

void	BitcoinExchange::insertRateToMap(std::map<std::string, double>& rateMap) {

	std::ifstream file("data/data.csv");
	if (!file.is_open()) {  throw std::runtime_error("Error: can't open data.csv");  }

	std::string	buffer;
	if (std::getline(file, buffer)) {
		if (buffer != "date,exchange_rate") {  throw std::runtime_error("Error: wrong format of the header \ndate,exchange_rate");  }
	}
	bool	firstData = true; 
	while (std::getline(file, buffer)) {

		std::string	data = buffer.substr(0, 10);
		std::string	rate = buffer.substr(11);
		
		double	d = 0.0;
		BitcoinExchange::stringToNumber(rate, d);
		rateMap.insert( std::pair<std::string, double>(data, d));
		if ( firstData == true ) {

			BitcoinExchange::stringToNumber(data.substr(0, 4), d);
			_firstYear = d;
			BitcoinExchange::stringToNumber(data.substr(5, 2), d);
			_firstMonth = d;
			BitcoinExchange::stringToNumber(data.substr(8, 2), d);
			_firstDay = d;

			firstData = false;
		}
	}
	file.close();
}

bool	BitcoinExchange::lineIsValid(std::string buffer) {

	std::string	data = copyBeforePipe(buffer);
	std::string	value = copyAfterPipe(buffer);
	
	if (data == "" || value == "") {  std::cerr << "Error: bad input => " << buffer << std::endl; return false;  }

	if (!dataIsValid(data)) {  return false;  }
	if (!valueIsValid(value)) {  return false;  }

	return true;
}

bool	BitcoinExchange::dataIsValid(std::string data) {

	if (data[4] != '-' || data[7] != '-' || data[10]) {  std::cerr << "Error: bad data format => " << data << ", YYYY-MM-DD" << std::endl; return false;  }

	std::string	year = data.substr(0, 4);
	if (year == "" || !BitcoinExchange::dataNumberIsValid(year, YEAR, "")) {  return false;  }
	std::string	month = data.substr(5, 2);
	if (month == "" || !BitcoinExchange::dataNumberIsValid(month, MONTH, "")) {  return false;  }
	std::string	day = data.substr(8, 2);
	
	int	yearN = 0;
	int	monthN = 0;
	int	dayN = 0;
	BitcoinExchange::stringToNumber( year, yearN );
	BitcoinExchange::stringToNumber( month, monthN );
	BitcoinExchange::stringToNumber( day, dayN );
	if ( yearN == _firstYear && monthN == _firstMonth && dayN  < _firstDay ) {

		std::cerr << "Error: invalid data => from " << _firstYear << "-" << _firstMonth << "-" << _firstDay << " only" << std::endl;
		return false;
	}
	if (day == "" || !BitcoinExchange::dataNumberIsValid(day, DAY, month)) {  return false;  }
	

	return true;
}

bool	BitcoinExchange::valueIsValid(std::string value) {

	if (!BitcoinExchange::valueIsDigit(value)) {  std::cerr << "Error: value must be an integer => " << value << std::endl; return false;  }

	if (value.find(".") != std::string::npos) {
		double	d = 0.0;
		BitcoinExchange::stringToNumber(value, d);
		if (BitcoinExchange::outOfLimits(d)) {  return false;  }
	}
	else {
		long	l = 0;
		BitcoinExchange::stringToNumber(value, l);
		if (BitcoinExchange::outOfLimits(l)) {  return false;  }
	}
	return true;
}

bool	BitcoinExchange::dataNumberIsValid(std::string data, int type, std::string month) {

	if (!BitcoinExchange::stringIsDigit(data)) {  std::cerr << "Error: bad data => " << data << std::endl; return false;  }
	
	long	l = 0;
	BitcoinExchange::stringToNumber(data, l);

	if (type == YEAR && (l < _firstYear)) {  std::cerr << "Error: invalid year => " << l << ", from " << _firstYear << " only" << std::endl; return false;  }
	else if (type == MONTH && (l < 01 || l > 12)) {  std::cerr << "Error: invalid month => " << l << ", only 01-12"  << std::endl; return false;  }
	else if (type == DAY) {

		if (l < 01 || l > 31) {  std::cerr << "Error: invalid day => " << l << ", only 01-31"  << std::endl; return false;  }
		if ((month == "04" || month == "06" || month == "09" || month == "11") && l == 31) {  std::cerr << "Error: month " << month << " only has 30 days" << std::endl; return false;  }
		if (month == "02" && l > 28) {  std::cerr << "Error: month " << month << " only has 28 days" << std::endl; return false;  }
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

	if (number < 0) {  std::cerr << "Error: value can't be negative => " << number << std::endl; return true;  }
	else if (number > 1000) {  std::cerr << "Error: too large value, can't be more than 1000 => " << number << std::endl; return true;  }

	return false;
};

template <typename T>
void	BitcoinExchange::stringToNumber(std::string str, T& number) {

	std::istringstream	myStream(str);

	myStream >> number;
	if (myStream.fail()) {  throw std::runtime_error("Error: istringstream failed");  myStream.clear();  }
	
	myStream.clear();
};

bool	BitcoinExchange::valueIsDigit(std::string str) {
	
	int i = 0;
	if (str[i] == '+' || str[i] == '-') {  i++;  }

	for (int j = i; str[j]; j++) {
		if (!std::isdigit(str[j]) && str[j] != '.')
			return false;
	}
	return true;
}

bool	BitcoinExchange::stringIsDigit(std::string str) {

	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	BitcoinExchange::printMap(std::map<std::string, double>& m) {

	std::map<std::string, double>::const_iterator it = m.begin();
	while (it != m.end()) {
		std::cout << "key: " << it->first << ", value: " << it->second << std::endl;
			it++;
	}
}

