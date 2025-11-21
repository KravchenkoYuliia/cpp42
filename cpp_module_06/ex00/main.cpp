/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:44:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/21 14:44:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char** av) {

	if (ac != 2) {
		std::cout << "./converter yourLitteral" << std::endl;
		return 1; }

	ScalarConverter::convert(av[1]);
	return 0;
}
