/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:48:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 17:17:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

bool	Replace::isprintableString(std::string lineToCheck) {

	for (int i = 0; i < int(lineToCheck.length()); i++) {
	
		if (!isprint(lineToCheck[i]))
			return false;
	}

	return true;
}

bool	Replace::isspaceString(std::string lineToCheck) {

	for (int i = 0; i < int(lineToCheck.length()); i++) {
	
		if (!isspace(lineToCheck[i]))
			return false;
	}
	return true;
}

void	Replace::checkInput() {

	if (Replace::fileName == "" |
	    Replace::oldText == "" |
	    Replace::newText == "") {
		std::cerr << "Input is empty" << std::endl;
		throw std::runtime_error("Invalid input"); }
	
	if (!Replace::isprintableString(Replace::fileName) |
	    !Replace::isprintableString(Replace::oldText)  |
	    !Replace::isprintableString(Replace::newText)) {
		std::cerr << "Input is empty" << std::endl;
		throw std::runtime_error("Invalid input");  }
	
	if (Replace::isspaceString(Replace::fileName) |
	    Replace::isspaceString(Replace::oldText) |
	    Replace::isspaceString(Replace::newText)) {
		std::cerr << "Input is empty" << std::endl;
		throw std::runtime_error("Invalid input"); }
}

std::string	Replace::readFile() {

	std::ifstream infile(Replace::fileName.c_str());
	if (!infile) {
		std::cerr << "Impossible to open [" << Replace::fileName << "]" << std::endl;
		throw std::runtime_error("Invalid input"); }
	
	std::stringstream buffer;
	buffer << infile.rdbuf();
	infile.close();
	return buffer.str();   
}
