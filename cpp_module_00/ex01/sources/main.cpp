/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:20:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 15:31:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int	main (void)
{
	PhoneBook	book;

	book.ft_start_prompt();
	book.ft_get_cmd();

//	std::getline(std::cin, book.line);
//	std::cout << book.line << std::endl;
	
	return 0;
}
