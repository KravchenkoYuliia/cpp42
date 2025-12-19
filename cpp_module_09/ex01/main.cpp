/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:07:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/18 18:07:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char** av) {

	if (ac != 2) {  std::cerr << "Error" << std::endl << "./RPN \"integers less than 10 and operators +-/*\"" << std::endl; return EXIT_FAILURE;  }


	try {  RPN	calculate(av[1]);  }
	catch (std::runtime_error& e) {  
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}
