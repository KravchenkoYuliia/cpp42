/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:12:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/12 17:12:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main() {

	Span	span = Span(5);

	try {
		//ADDING NUMBER BY NUMBER
		std::cout << "Adding numbers:" << std::endl;
		span.addNumber(9);
		std::cout << "Succes: 9" << std::endl;
		span.addNumber(2);
		std::cout << "Succes: 2" << std::endl;
		span.addNumber(5);
		std::cout << "Succes: 5" << std::endl;
		span.addNumber(-1);
		std::cout << "Succes: -1" << std::endl;
		span.addNumber(10);
		std::cout << "Succes: 10" << std::endl << std::endl; 
		std::cout << "Longest span is " << span.longestSpan() << std::endl;
		std::cout << "Shortest span is " << span.shortestSpan() << std::endl;
		
		/*CHECK THE EXCEPTION THROWING
		std::cout << "Trying to add an extra number (1): " << std::endl;
		span.addNumber(1);
		std::cout << "Succes: 1" << std::endl;*/

		/*ADDING MULTIPLE NUMBERS
		std::vector<int>	bigVector;
		for (int i = 0; i < 10001; i++) {
			bigVector.push_back(i);
		}
		span.addMultipleNumbers(bigVector);
		std::cout << std::endl;*/
		
	}
	catch (std::out_of_range& e) {  std::cout << e.what() << std::endl;  }
	return 0;
}

