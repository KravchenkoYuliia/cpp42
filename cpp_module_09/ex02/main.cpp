/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/19 18:16:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int ac, char** av ) {

	if (ac < 2) {  std::cerr << "./PmergeMe integers..." << std::endl;  }

	try {  PmergeMe	merge(av);  }
	catch ( std::runtime_error& e ) {  std::cerr << e.what() << std::endl; return EXIT_FAILURE;  }

	return EXIT_SUCCESS;
}
