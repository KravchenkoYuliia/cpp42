/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:30:46 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/21 19:25:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

void	Account::_displayTimestamp( void ) {

	std::time_t result = std::time(NULL);
	std::string full_data = std::asctime(std::localtime(&result));	
	int	len = full_data.length();
	
	std::string	year = full_data.substr(len-5, 4);
	std::string	month = "10";
	std::string	day = full_data.substr(8, 2);
	std::string	underscore = "_";
	std::string	time = full_data.substr(len - 14, 8);
	std::string	result_time;


	for (int i = 0; i < 8; i++) {

		if (time[i] != ':')
			result_time += time[i];
	}
	std::string format = year + month + day + underscore + result_time;

	std::cout << "[" << format << "]";
}
