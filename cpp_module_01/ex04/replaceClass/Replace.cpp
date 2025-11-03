/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:27:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 10:36:04 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string fileName, std::string oldText, std::string newText) {

	Replace::fileName = fileName;
	Replace::oldText = oldText;
	Replace::newText = newText;
}

void	Replace::Process() {

	Replace::checkInput();

	std::string	allText    = Replace::readFile();
	std::string	replacedText = Replace::findAndReplace(allText);

	Replace::writeToNewFile(replacedText);
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

Replace::~Replace() {

}
