/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:37:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/30 17:15:12 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream> 

class Replace { 

public:
	Replace(std::string fileName, std::string oldText, std::string newText);
	~Replace();

	void		Process();
	void		checkInput();
	bool		isprintableString(std::string lineToCheck);
	bool		isspaceString(std::string lineToCheck);
	std::string	readFile();
	std::string	findAndReplace(std::string allText);
	void		writeToNewFile(std::string replacedText);


private:
	std::string	fileName;
	std::string	oldText;
	std::string	newText;


};
