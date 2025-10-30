/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:27:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 13:49:36 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string fileName, std::string oldText, std::string newText) {

	std::cout << "Called constructor of Replace Class" << std::endl;
	Replace::fileName = fileName;
	Replace::oldText = oldText;
	Replace::newText = newText;
}

void	Replace::Process() {

	std::cout << "Replace: doing stuff" << std::endl;

}


Replace::~Replace() {

	std::cout << "Called  destructor of Replace Class" << std::endl;
}
