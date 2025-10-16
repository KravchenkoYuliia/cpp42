/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:20:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:53:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int	main (void)
{
	PhoneBook	book;

	book.ft_start_prompt();
	while (1)
	{
		if (book.ft_get_cmd() == EXIT)
			break ;
	}
	return 0;
}
