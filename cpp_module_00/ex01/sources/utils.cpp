/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:24:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 15:35:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	PhoneBook::ft_horizontal_line() {

	std::cout << ' ' << PIPE_COLOR;

	for (int i = 1; i < 43; i++){

		if (i % 11 == 0)
			std::cout << '|';
		else
			std::cout  << '-';
	}

	std::cout << '-' << RESET_ALL << std::endl;
}
