/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/22 17:27:48 by yukravch         ###   ########.fr       */
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

void	PmergeMe::sorting( char** av ) {

	PmergeMe::fillContainers(av);
	std::cout << "Before: ";
	PmergeMe::printVector( _nbV );

	PmergeMe::FJalgorithm( _nbV );

	/*std::time_t	t = std::time(0);
	std::cout << t << std::endl;*/
}

std::vector<int>	PmergeMe::FJalgorithm( std::vector<int> v ) {


	if ( v.size() <= 1 ) {  return v;  }

	std::vector<int>	main;
	std::vector<int>	pend;
	int			straggler;

	//
	//Step 1 : get main, pend and straggler
	//
		
	if ( v.size() % 2 != 0 ) {  straggler = v[v.size()-1];  }
	else {  straggler = NOLAST;  }
	
	std::vector<int>::size_type  i = 0; 
	while ( i < v.size() ) {

		int	bigger = 0;
		int	smaller = 0;

		if ( v[i] > v[i+1] ) {
			bigger = i;
			smaller = i + 1;
		}
		else {
			bigger = i + 1;
			smaller = i;
		}

		main.push_back( v[bigger] );
		pend.push_back( v[smaller] );

		if ( i+2 < v.size() ) {  i += 2;  }
		else {  break;  }
	}
	
	//
	//Step 2 : sort main
	//
	main = PmergeMe::FJalgorithm( main );

	//
	//Step3 : inserting pend to main
	//
	
	

	return main;
}

void	PmergeMe::fillContainers( char** av ) {

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

void	PmergeMe::printVector( std::vector<int> v) {
	
	std::cout << VECTORCOLOR;
	for (std::vector<int>::size_type i = 0; i < v.size(); i++) {

		std::cout << " " << v[i];
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
