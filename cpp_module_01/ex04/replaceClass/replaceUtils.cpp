/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:48:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 10:31:04 by yukravch         ###   ########.fr       */
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
		throw std::runtime_error("Input is empty"); }
	
	if (!Replace::isprintableString(Replace::fileName) |
	    !Replace::isprintableString(Replace::oldText)  |
	    !Replace::isprintableString(Replace::newText)) {
		throw std::runtime_error("Input is empty");  }
	
	if (Replace::isspaceString(Replace::fileName) |
	    Replace::isspaceString(Replace::oldText) |
	    Replace::isspaceString(Replace::newText)) {
		throw std::runtime_error("Input is empty"); }
}

std::string	Replace::readFile() {

	std::ifstream infile(Replace::fileName.c_str());
	if (!infile) {
		std::cerr << "[" << Replace::fileName << "]" << std::endl;
		throw std::runtime_error("Impossible to open the file"); }
	
	std::stringstream buffer;
	buffer << infile.rdbuf();
	infile.close();
	return buffer.str();   
}
