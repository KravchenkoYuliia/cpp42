/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/20 18:58:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {  std::cerr << "Sorting is not possible without any numbers" << std::endl;  }

PmergeMe::PmergeMe(char** av) {  PmergeMe::sorting(av);  }

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {

	if (this != &other) {
		this->_nbV = other._nbV;
		this->_nbL = other._nbL;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

//
//methods
//

void	PmergeMe::sorting(char** av) {

	PmergeMe::fillContainers(av);
	std::cout << "Before: ";
	PmergeMe::printVector();

	PmergeMe::sortVector();
	/*std::time_t	t = std::time(0);
	std::cout << t << std::endl;*/
}

void	PmergeMe::sortVector() {

}

bool	PmergeMe::maxValueAreSorted() {

	
	for (std::vector<int>::size_type i = 1; i + 2 < _nbV.size(); i += 2) {
		
		if (_nbV[i] > _nbV[i+2]) {  return false;  }
	}

	return true;
}

void	PmergeMe::fillContainers(char** av) {

	for (int i = 1; av[i]; i++) { 
		
		PmergeMe::avIsValid(av[i]);

		size_t			l = 0;
		std::stringstream	ss(av[i]);
		while (ss >> l) {
			if (ss.fail()) {  throw std::runtime_error("Error: only digit are allowed");  }
			if (l > INT_MAX) {  throw std::runtime_error("Error: nb is out of int limits");  }
			
			if (std::find(_nbV.begin(), _nbV.end(), l) != _nbV.end()) {  throw std::runtime_error("Error: doubles are not allowed");  }
			_nbV.push_back(l);
			_nbL.push_back(l);
		}
	}
}

void	PmergeMe::avIsValid(std::string str) {

	if (str.length() > 10) {  throw std::runtime_error("Error: nb is out of INT limits");  }

	for (int i = 0; str[i]; i++) {
		
		if (!std::isdigit(str[i]) && str[i] != ' ') {
			if (str[i] == '+') {

				if (!str[i+1] || !std::isdigit(str[i+1])) {
					std::cerr << "[" << str[i];
					
					if (!str[i+1]) { std::cerr << "?"; }
					else { std::cerr << str[i+1]; }
					
					std::cerr << "]" << std::endl; 
					throw std::runtime_error("Error: invalid input");
				}
				if (str[i-1] && str[i-1] != ' ') {
					std::cerr << "[" << str[i-1] << str[i] << "]" << std::endl;
					throw std::runtime_error("Error: invalid input"); }
			}
			else {
				std::cerr << "[" << str[i] << "]" << std::endl;
				throw std::runtime_error("Error: invalid input");
			}
		}
	}
}

void	PmergeMe::printVector() {
	
	std::cout << VECTORCOLOR;
	for (std::vector<int>::size_type i = 0; i < _nbV.size(); i++) {

		std::cout << " " <<_nbV[i];
	}
	std::cout << RESET << std::endl;
}

void	PmergeMe::printList() {

	int i = 0;
	std::list<int>::iterator	it = _nbL.begin();
	
	std::cout << LISTCOLOR << std::endl;
	while (it != _nbL.end()) {

		std::cout << i << ": " << *it << std::endl;
		i++;
		it++;
	}
	std::cout << RESET << std::endl;
}
