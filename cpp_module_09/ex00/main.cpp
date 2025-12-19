/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:53:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/16 14:21:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
int	main( int ac, char** av ) {

	if (ac != 2) {  std::cout << "Error: put an input file." << std::endl << "./btc file" << std::endl; return 1;  }

	try {  BitcoinExchange	btc(av[1]);  }
	catch (std::runtime_error& e) {  std::cout << e.what() << std::endl; return 1;  }
	
	return 0;
}
