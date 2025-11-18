/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:23:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 11:23:06 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

bool	stringIsDigit(std::string line) {

	for (int i = 0; i < (int)line.length(); i++) {
		if (i == 0 && line[i] == '-')
			i++;
		if (!isdigit(line[i]))
			return false;
	}
	return true;
}

void	checkArguments(std::string name, std::string grade) {

	if (name == "" || grade == "")
		throw std::runtime_error("arguments can't be empty");
	
	if (!stringIsDigit(grade))
		throw std::runtime_error("hisGrade must be an integer");
}

void	bureaucratTest(std::string name, int grade) {

	std::cout << "******************Create a first bureaucrat***********" <<  std::endl;
	Bureaucrat	newBureaucrat(name, grade);
	std::cout << newBureaucrat << std::endl;
	std::cout << std::endl;

	std::cout << "******************Create a second bureaucrat by coping from the first one***********" <<  std::endl;
	Bureaucrat	copyBureaucrat(newBureaucrat);
	std::cout << copyBureaucrat << std::endl;
	std::cout << "******************Upgrade the grade of second bureaucrat by 4***********" <<  std::endl;
	copyBureaucrat.upgradeGrade(4);
	std::cout << copyBureaucrat << std::endl;
	std::cout << std::endl;

	std::cout << "******************Create a third bureaucrat and use a assignment operator to assign the firstBureaucrat to this new one***********" <<  std::endl;
	Bureaucrat	assignBureaucrat;
	assignBureaucrat = newBureaucrat;
	std::cout << assignBureaucrat << std::endl;
	std::cout << "******************Downgrade the grade of second bureaucrat by 100***********" <<  std::endl;
	assignBureaucrat.downgradeGrade(100);
	std::cout << assignBureaucrat << std::endl;
	std::cout << std::endl;
}

int	main(int ac, char** av) {

	try {

		if (ac != 3)
			throw std::runtime_error("./newBureaucrat hisName hisGrade");
		
		std::string	name = av[1];
		std::string	gradeString = av[2];

		checkArguments(name, gradeString);

		std::istringstream	myStream(gradeString);
		int	grade = 0;
		if (myStream)
			myStream >> grade;

		bureaucratTest(name, grade);



	}
	catch (std::runtime_error e) {

		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
