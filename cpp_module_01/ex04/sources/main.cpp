/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:37:23 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 13:48:00 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char** av) {

	if (ac != 4) {
		std::cerr << "./replace <filename> string1 string2" << std::endl;
		return 1; }

	Replace	Process = Replace(av[1], av[2], av[3]);
	try {
		Process.Process(); }
	catch (...) {
		return 1;
	}

	return 0;
}
