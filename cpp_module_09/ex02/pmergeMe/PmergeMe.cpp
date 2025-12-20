/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/19 18:16:19 by yukravch         ###   ########.fr       */
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

	for (std::vector<int>::size_type i = 0; i < _nbV.size(); i += 2) {
		if (_nbV[i+1] && _nbV[i+1] < _nbV[i]) {  std::swap(_nbV[i], _nbV[i+1]);  }
	}
	PmergeMe::printVector();
}

void	PmergeMe::fillContainers(char** av) {

	for (int i = 1; av[i]; i++) { 
		
		PmergeMe::avIsValid(av[i]);

		long			l = 0;
		std::stringstream	ss(av[i]);
		while (ss >> l) {
			if (ss.fail()) {  throw std::runtime_error("Error: only digit are allowed");  }
			if (l > INT_MAX || l < INT_MIN) {  throw std::runtime_error("Error: nb is out of int limits");  }
			
			_nbV.push_back(l);
			_nbL.push_back(l);
		}
	}
}

void	PmergeMe::avIsValid(std::string str) {

	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]) && str[i] != ' ') {
			if (str[i] == '-' || str[i] == '+') {

				if (!str[i+1] || !std::isdigit(str[i+1]))
					throw std::runtime_error("Error: invalid input");
				if (str[i-1] && str[i-1] != ' ') 
					throw std::runtime_error("Error: invalid input");
			}
			else
				throw std::runtime_error("Error: invalid input");
		}
	}
}

void	PmergeMe::printVector() {
	
	std::cout << VECTORCOLOR << std::endl;
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
