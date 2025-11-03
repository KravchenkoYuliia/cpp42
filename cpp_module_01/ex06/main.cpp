/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:44:50 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 17:04:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av) {

	if (ac != 2) {
		std::cerr << "./harlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return 1;
	}

	Harl		Harl;
	std::string	level = av[1];

	Harl.complain(level);
	return 0;
}
