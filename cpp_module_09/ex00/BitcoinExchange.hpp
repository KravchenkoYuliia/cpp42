/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:53:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/18 16:59:03 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP 
#define BITCOINEXCHANGE_HPP 

#include <iostream>
#include <fstream> 
#include <sstream> 
#include <map>
#include <string>

#define YEAR 2025
#define MONTH 12
#define DAY 31


class BitcoinExchange {

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange&	operator = (const BitcoinExchange& other);
	
	void	convertValue(char* fileName);

private:
	void	insertRateToMap(std::map<std::string, double>& rateMap);

	bool		lineIsValid(std::string buffer);
	bool		dataIsValid(std::string data);
	bool		dataNumberIsValid(std::string data, int type, std::string month);
	bool		valueIsValid(std::string value);

	
	void	convertValueInLine(std::map<std::string, double>& rateMap, std::string lineToConvert);

	template <typename T> bool	outOfLimits(T number);
	template <typename T> void	stringToNumber(std::string str, T& number);
	bool				valueIsDigit(std::string str);
	bool				stringIsDigit(std::string str);

	std::string	copyBeforePipe(std::string s);
	std::string	copyAfterPipe(std::string s);


	void	printMap(std::map<std::string, double>& m);
};


#endif
