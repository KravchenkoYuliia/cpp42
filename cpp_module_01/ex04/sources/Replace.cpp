/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:27:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 17:20:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string fileName, std::string oldText, std::string newText) {

	Replace::fileName = fileName;
	Replace::oldText = oldText;
	Replace::newText = newText;
}

void	Replace::Process() {

	try {
		Replace::checkInput();

		std::string	allText    = Replace::readFile();
		std::string	replacedText = Replace::findAndReplace(allText);

		Replace::writeToNewFile(replacedText);
	}
	catch (...) {
		throw; }
}

std::string	Replace::findAndReplace(std::string allText) {

	

	int	startOfCopy = 0;
	size_t	positionOfMatch = 0;
	std::string	finalText = "";
	int	lenToCopy;
	char*	buffer;
       
	while (positionOfMatch != std::string::npos) {
		
		positionOfMatch = allText.find(Replace::oldText, startOfCopy);
		if (positionOfMatch == std::string::npos)
			break ;

		lenToCopy = positionOfMatch - startOfCopy;
		buffer = new char[lenToCopy + 1];

		allText.copy(buffer, lenToCopy, startOfCopy);
		buffer[lenToCopy] = '\0';
		startOfCopy = positionOfMatch + Replace::oldText.length();
		
		std::string AddBufferToResult = buffer;
		delete[] buffer;
		
		finalText += AddBufferToResult + Replace::newText;

	}
	lenToCopy = allText.length() - startOfCopy;
	buffer = new char[lenToCopy + 1];

	allText.copy(buffer, lenToCopy, startOfCopy);
	buffer[lenToCopy] = '\0';
	
	std::string AddBufferToResult = buffer;
	delete[] buffer;
	
	finalText += AddBufferToResult;
	return finalText;
}

void	Replace::writeToNewFile(std::string replacedText) {
	
	std::string	endingFile = ".replace";
	std::string	outfileName = Replace::fileName + endingFile;

	std::ofstream outfile(outfileName.c_str());
	outfile << replacedText;
	outfile.close();
}

Replace::~Replace() {

}
