/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:44:50 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 12:08:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av) {

	if (ac != 2) {
		std::cerr << "./harlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return 1;
	}

	Harl	Harl;
	int	index;
	std::string	level = av[1];
	if (level == "DEBUG")
		index = 0;
	else if (level == "INFO")
		index = 1;
	else if (level == "WARNING")
		index = 2;
	else if (level == "ERROR")
		index = 3;
	else
		index = 4;
	
 	switch (index) {
	
	case 0:
		Harl.complain("DEBUG");
		break ;
	case 1:
		Harl.complain("INFO");
		break;
	case 2:
		Harl.complain("WARNING");
		break ;
	case 3:
		Harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break ;
	}


	return 0;
}
