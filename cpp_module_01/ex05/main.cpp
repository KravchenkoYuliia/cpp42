/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:39:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 16:41:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av) {

	if (ac != 2) {
		std::cout << "./harl [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return 1;
	}
		
	Harl	Harl;
	
	std::cout << "Function input is: [" << av[1] << "]" << std::endl;
	Harl.complain(av[1]);
	return 0;
}
