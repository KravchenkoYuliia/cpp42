/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:09:20 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/24 16:48:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print( std::string string, std::string* stringPTR, std::string& stringREF ) {

	std::cout << "Memory:" << std::endl
		<< "Memory adress of the initial string:      [" << &string << ']' << std::endl
		<< "Memory adress held by string's pointer:   [" << stringPTR << ']' << std::endl
		<< "Memory adress held by string's reference: [" << &stringREF << ']' << std::endl
		<< std::endl
		<< "Value: " << std::endl
		<< "Value of the initial string:            [" << string << ']' << std::endl
		<< "Value pointed to by string's pointer:   [" << *stringPTR << ']' << std::endl
		<< "Value pointed to by string's reference: [" << stringREF << ']' << std::endl
		<< std::endl;
}

int	main( void ) {

	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = new std::string;
	*stringPTR = string;
	std::string&	stringREF = string;
	print(string, stringPTR, stringREF);


	stringREF = "Change the value of the string by reference";
	print(string, stringPTR, stringREF);


	*stringPTR = "Change the value of the string by pointer";
	print(string, stringPTR, stringREF);
	
	delete stringPTR;
	return 0;
}
