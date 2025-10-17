/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:24:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 17:20:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	PhoneBook::ft_write_horizontal_line() {

	std::cout << ' ' << PIPE_COLOR;

	for (int i = 1; i < 43; i++){

		if (i % 11 == 0)
			std::cout << '|';
		else
			std::cout  << '-';
	}

	std::cout << '-' << RESET_ALL << std::endl;
}

std::string	PhoneBook::ft_format(int type, int index)
{
	std::string	result;

	if (type == FIRST_NAME)
		result = PhoneBook::user[index].ft_get_first_name();
	else if (type == LAST_NAME)
		result = PhoneBook::user[index].ft_get_last_name();
	else if (type == NICKNAME)
		result = PhoneBook::user[index].ft_get_nickname();
	else if (type == PHONE)
		result = PhoneBook::user[index].ft_get_phone();
	else if (type == SECRET)
		result = PhoneBook::user[index].ft_get_secret();
	
	if (result == "")
		result = "          ";
	size_t	len = result.length();

	if (len > 10)
	{
		result.at(9) = '.';
		result = result.substr(0, 10);
	}
	else if (len < 10)
	{
		result = std::string(10 - len, ' ') + result;
	}
	return result;
}
