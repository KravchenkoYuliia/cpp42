/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:53:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/15 17:53:59 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP 
#define BITCOINEXCHANGE_HPP 

#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector>
#include <string>


class BitcoinExchange {

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange&	operator = (const BitcoinExchange& other);
	
	void	convertValue(char* fileName);

private:
	bool		lineIsValid(std::string buffer);
	bool		dataIsValid(std::string data);
	bool		valueIsValid(std::string value);

	template <typename T> bool outOfLimits(T number);

	std::string	copyBeforePipe(std::string s);
	std::string	copyAfterPipe(std::string s);


};


#endif
