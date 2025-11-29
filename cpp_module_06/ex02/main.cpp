/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:03:49 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/29 16:03:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "classes.hpp" 

Base*	generate( void ) {

	Base*	base = NULL;

	std::srand(time(0));
	int i = std::rand();
	if (i % 2 == 0 && i % 4 != 0)
		base = new A;
	else if (i % 3 == 0)
		base = new B;
	else
		base = new C;
	
	return base;
}

void	identify( Base* p ) {

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error: unknown type" << std::endl;
}

void	identify( Base& p ) {


	try {
	 
		A&	refA = dynamic_cast<A&>(p);
		(void)refA;
		std::cout << "A" << std::endl;
	}
	catch (...) { 

		try {
			B&	refB = dynamic_cast<B&>(p);
			(void)refB;
			std::cout << "B" << std::endl;
		}
		catch (...) {
			
			try {
				C&	refC = dynamic_cast<C&>(p);
				(void)refC;
				std::cout << "C" << std::endl;
			}
			catch (...) { std::cout << "Error: unknown type" << std::endl; }
		} 
	}
}


int	main() {

	Base*	ptrBase = generate();
	Base&	refBase = *ptrBase;

	std::cout << "Identified by pointer: " << std::endl;
	identify(ptrBase);

	std::cout << "Identified by reference: " << std::endl;
	identify(refBase);

	return 0;
}
