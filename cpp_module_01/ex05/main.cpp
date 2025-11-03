/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:39:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 11:48:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(){

	Harl	Harl;

	std::string	levels[6] = {"DEBUG", "random stuff", "INFO", "WARNING", "do you know this?", "ERROR"};

	for (int i = 0; i < 6; i++) {

		std::cout << "Function input is: [" << levels[i] << "]" << std::endl;
		Harl.complain(levels[i]);
		if (i != 5)
			std::cout << std::endl;
	}
	return 0;
}
