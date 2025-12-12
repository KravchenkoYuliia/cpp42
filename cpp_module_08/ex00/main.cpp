/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:47:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/11 14:47:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main() {

	std::vector<int>	v;
	for (int i = 2; i < 10; i++) {
		v.push_back(i);
	}
	
	std::cout << "Printing the values of vector<int> container:" << std::endl;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	try {
		int value_to_find = 5;
		std::cout << "Trying to find " << value_to_find << " in the container" <<std::endl;
		std::vector<int>::iterator it = easyfind(v, value_to_find);
		std::cout << "Succes: the value is found -> " << *it << " at the position " << distance(v.begin(), it) << std::endl;
	}

	catch (std::out_of_range& e) {  std::cout << e.what() << std::endl;  }

	return 0;
}
