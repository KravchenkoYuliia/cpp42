/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:50:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/09 17:50:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {

	Array<int>		defaultInt;
	
	Array<int>		intWithSize(2);
	intWithSize[0] = 0;
	intWithSize[1] = 0;
	
	Array<int>		copyInt(intWithSize);
	Array< int>	assignInt;
		assignInt = copyInt;

	try {
		std::cout << "Setting intWithSize array[0] to 100 and array[1] to 200" << std::endl << std::endl;
		intWithSize[0] = 100;
		intWithSize[1] = 200;


		std::cout << "Try to set smth out of range" << std::endl;
		intWithSize[-1] = 200;
		intWithSize[2] = 200;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	int*	array = intWithSize.getArray();
	std::cout << "intWithSize:" << std::endl;
	
	for (unsigned int i = 0; i < intWithSize.size(); i++) {
		std::cout << i << ": " << array[i] << std::endl;
	}
	std::cout << std::endl;
	
	array = copyInt.getArray();
	std::cout << "copyInt:" << std::endl;
	for (unsigned int i = 0; i < copyInt.size(); i++) {
		std::cout << i << ": " << array[i] << std::endl << std::endl;
	}

	Array<std::string>	stringArray(1);
	stringArray[0] = "Template works with strings";
	std::cout << "Create an array of strings:" << std::endl << "index 0: " << "\"" << stringArray[0] << "\"" << std::endl;
	
	return 0;
}
