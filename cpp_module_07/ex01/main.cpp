/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:24:51 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/09 15:24:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp" 

void	incrementation(int& i) {  i += 1;  }
void	stringToUpper(std::string& s) {  for (int i = 0; s[i]; i++) {  s[i] = std::toupper(s[i]);  }  }


int	main() {

	int	arrayInt[5] = {1, 2, 3, 4, 5};
	std::cout << "INT ARRAY BEFORE: {";
	for (int i = 0; i < 5; i++) {  std::cout << arrayInt[i];  }
	std::cout << "}" << std::endl;
	
	::iter(arrayInt, 5, incrementation);
	std::cout << "INT ARRAY AFTER: {";
	for (int i = 0; i < 5; i++) {  std::cout << arrayInt[i];  }
	std::cout << "}" << std::endl << std::endl;



	std::string	arrayString[3] = {"Bonjour", "Hello", "Yo"};
	std::cout << "STRING ARRAY BEFORE: {";
	for (int i = 0; i < 3; i++) {  std::cout << arrayString[i]; if (i != 2) { std::cout << ", "; }  }
	std::cout << "}" << std::endl;
	
	::iter(arrayString, 3, stringToUpper);
	std::cout << "STRING ARRAY AFTER: {";
	for (int i = 0; i < 3; i++) {  std::cout << arrayString[i]; if (i != 2) { std::cout << ", "; }  }
	std::cout << "}" << std::endl;


	return 0;
}
