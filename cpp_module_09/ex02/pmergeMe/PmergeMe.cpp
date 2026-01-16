/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/16 12:11:55 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {  std::cerr << "Sorting is not possible without any numbers" << std::endl;  }

PmergeMe::PmergeMe(char** av) {  PmergeMe::sorting(av);  }

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {

	if (this != &other) {
		this->_v = other._v;
		this->_d = other._d;
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
	//::printContainer( _v, "vector" );
	std::cout << std::endl;
	

	::printTimeCallAlgo < std::vector<int> > ( _v, "vector no Ford-Johnson" );
	std::cout << std::endl;
	::printTimeCallAlgo < std::vector<int> > ( _v, "vector" );
	std::cout << std::endl;
	::printTimeCallAlgo < std::deque<int> > ( _d, "deque" );
	std::cout << std::endl;
}

void	PmergeMe::getNextIndexWithJacobsthalSequence( int& index, int& previousIndex, int& previousOfThePreviousIndex ) {

	index = previousIndex + 2 * previousOfThePreviousIndex;

	previousOfThePreviousIndex = previousIndex;
	previousIndex = index;
}


int	PmergeMe::findPair( int findIt, std::vector< std::pair<int, int> >& inHere) {

	for ( std::vector< std::pair< int, int > >::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i].second == findIt ) {  return inHere[i].first;  }
	}

	return -1;
}


void	PmergeMe::makePairs( void ) {
	
	std::vector<int>::size_type i = 0;
	while ( i+1 < _v.size() ) {

		if ( _v[i] > _v[i+1])
			_pairsV.push_back(  std::make_pair( _v[i+1], _v[i] )  );
		else
			_pairsV.push_back(  std::make_pair( _v[i], _v[i+1] )  );

		if ( i+2 < _v.size() ) {  i += 2;  }
		else {  break;  }
	}
}

void	PmergeMe::fillContainers( char** av ) {

	for (int i = 1; av[i]; i++) { 
	
		PmergeMe::avIsValid(av[i]);

		size_t			l = 0;
		std::stringstream	ss(av[i]);
		while (ss >> l) {
			if (ss.fail()) {  throw std::runtime_error("Error: only digit are allowed");  }
			if (l > INT_MAX) {  throw std::runtime_error("Error: nb is out of int limits");  }
			
			if (std::find(_v.begin(), _v.end(), l) != _v.end()) {  std::cerr << "[" << l << "]"<< std::endl;  throw std::runtime_error("Error: doubles are not allowed");  }
			_v.push_back( l );
			_d.push_back( l );
		}
	}
}

void	PmergeMe::avIsValid(std::string str) {

	
	if ( str.length() > 10 && str[0] == '-' ) {  throw std::runtime_error("Error: only positive integers are allowed");  }
	if ( str.length() > 10 ) {  throw std::runtime_error("Error: nb is out of INT limits");  }

	for ( int i = 0; str[i]; i++ ) {
		
		if ( !std::isdigit(str[i]) && str[i] != ' ' ) {
			if ( str[i] == '+' ) {

				if ( !str[i+1] || !std::isdigit(str[i+1]) ) {
					std::cerr << "[" << str[i];
					
					if ( !str[i+1] ) { std::cerr << "?"; }
					else { std::cerr << str[i+1]; }
					
					std::cerr << "]" << std::endl; 
					throw std::runtime_error("Error: invalid input");
				}
				if ( str[i-1] && str[i-1] != ' ' ) {
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

void	PmergeMe::countTime( std::string container, int containerSize,  int beforeTime, int afterTime ) {

	std::cout << "Time to process a range of " << containerSize << " elements with std::" << container << " : " << std::fixed << std::setprecision(2) << 1000.0 * ( afterTime - beforeTime ) / CLOCKS_PER_SEC << "ms" << std::endl;

}

void	PmergeMe::printPairsV( std::vector< std::pair<int, int> > p) {


	if ( p.empty() ) {  std::cout << "pairs are empty" << std::endl;  }
	for ( std::vector< std::pair<int, int> >::size_type i = 0; i < p.size(); i++) {
		std::cout << "Pair : " << p[i].first << " + " << p[i].second << std::endl;
	}
}

