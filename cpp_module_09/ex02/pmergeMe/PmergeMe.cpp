/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/12 13:35:28 by yukravch         ###   ########.fr       */
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
	PmergeMe::printVector( _v );
	std::cout << std::endl;
	

	::printTimeCallAlgo < std::vector<int> > ( _v, "vector no Ford-Johnson" );
	std::cout << std::endl;
	::printTimeCallAlgo < std::vector<int> > ( _v, "vector" );
	std::cout << std::endl;
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::FJalgorithm( std::vector<int> v ) {

	if ( v.size() <= 1 ) {  return v;  }

	int						straggler = -1;
	std::vector<int>			main;
	std::vector<int>			pend;
	std::vector< std::pair<int, int> >	pairs;
	//
	//Step 1 : get main, pend and straggler
	//
	
	if ( v.size() % 2 != 0 ) {  straggler = v[v.size()-1];  }
	else {  straggler = NOSTRAGGLER;  }
	
	std::vector<int>::size_type  i = 0;
	while ( i+1 < v.size() ) {

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
		pairs.push_back(  std::make_pair( v[bigger], v[smaller] )  );
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
	//insert index 0 of pend
	

	main = PmergeMe::insertNumber( pend[0], main, pairs );
	if ( pend.size() == 1 && straggler == NOSTRAGGLER ) {  return main;  }
	

	int	index = 1;
	int	previousIndex = 1;
	int	previousOfThePreviousIndex = 1;

	int	pendSize = pend.size();


	if ( pend.size() > 1 ) {
		main = PmergeMe::insertNumber( pend[index], main, pairs );
		PmergeMe::getNextIndexWithJacobsthalSequence( index, previousIndex, previousOfThePreviousIndex );

	}
	while ( index < pendSize ) {

		for ( int i = index; i > previousOfThePreviousIndex; i -= 1 ) {

			main = PmergeMe::insertNumber( pend[i], main, pairs );
		}
		PmergeMe::getNextIndexWithJacobsthalSequence( index, previousIndex, previousOfThePreviousIndex );
	}


	for ( int i = pendSize-1; i > previousOfThePreviousIndex; i -= 1 ) {

		main = PmergeMe::insertNumber( pend[i], main, pairs );
	}

	if ( straggler != NOSTRAGGLER ) {
			main = PmergeMe::insertStraggler( straggler, main );
	}
	
	return main;
}

std::vector<int>	PmergeMe::insertNumber( int insertIt, std::vector<int> here, std::vector< std::pair<int, int> > pairs) {

	int	pairOfPend = PmergeMe::findPair( insertIt, pairs );
	if ( pairOfPend == -1) {  std::cerr << "find pair for " << insertIt << std::endl; throw std::runtime_error("Error: no number you're looking for");  }


	int	maxPositionInMain = PmergeMe::findMainPositionForPair( pairOfPend, here );
	if ( maxPositionInMain == -1) {  throw std::runtime_error("Error: no position you're looking for");  }

	if ( maxPositionInMain == 0 ) {
		
		here.insert( here.begin(), insertIt );
		return here;
	}
	for ( int i = maxPositionInMain-1; i >= 0; i--) {
		if ( insertIt > here[i]) {
		
			here.insert( here.begin() + i + 1, insertIt );
			break ;
		}
		else if ( i == 0 ) {
			here.insert( here.begin(), insertIt );
			break ;
		}
	}

	return here;
}

void	PmergeMe::getNextIndexWithJacobsthalSequence( int& index, int& previousIndex, int& previousOfThePreviousIndex ) {

	index = previousIndex + 2 * previousOfThePreviousIndex;

	previousOfThePreviousIndex = previousIndex;
	previousIndex = index;
}

std::vector<int>	PmergeMe::insertStraggler( int straggler, std::vector<int> main ) {

	int mainSize = main.size();

	if ( straggler > main[ mainSize/2 ]) {
		for ( int i = mainSize/2 ; i < mainSize; i++) {
			
			if ( straggler < main[i]) {

				main.insert( main.begin() + i, straggler);
				return main;
			}
			else if ( i+1 == mainSize ) {

				main.insert( main.begin() + i+1, straggler);
				return main;
			}
		}
	}
	else {
		for ( int i = mainSize/2 ; i >= 0; i--) {

			if ( straggler > main[i]) {

				main.insert( main.begin() + i + 1, straggler);
				return main;
			}
			if ( i == 0 && straggler < main[i] ) {

				main.insert( main.begin(), straggler);
				return main;
			}

		}
	}

	return main;
}


int	PmergeMe::findPair( int findIt, std::vector< std::pair<int, int> >& inHere) {

	for ( std::vector< std::pair<int, int> >::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i].second == findIt ) {  return inHere[i].first;  }
	}

	return -1;
}

int	PmergeMe::findMainPositionForPair( int findIt, std::vector<int>&  inHere ) {

	int count = 0;
	for ( std::vector<int>::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i] == findIt ) {  return count;  }
		count += 1;
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

void	PmergeMe::printVector( std::vector<int>& v) {
	
	if ( v.empty() ) {  std::cout << "empty" << std::endl;  }
	std::cout << VECTORCOLOR;
	for (std::vector<int>::size_type i = 0; i < v.size(); i++) {

		std::cout << " " << v[i];
	}
	std::cout << RESET << std::endl;
}


void	PmergeMe::printDeque( std::deque<int>& d ) {

	if ( d.empty() ) {  std::cout << "empty" << std::endl;  }
	std::cout << DEQUECOLOR;
	for (std::deque<int>::size_type i = 0; i < d.size(); i++) {

		std::cout << " " << d[i];
	}
	std::cout << RESET << std::endl;
}

void	PmergeMe::printPairsV( std::vector< std::pair<int, int> > p) {


	if ( p.empty() ) {  std::cout << "pairs are empty" << std::endl;  }
	for ( std::vector< std::pair<int, int> >::size_type i = 0; i < p.size(); i++) {
		std::cout << "Pair : " << p[i].first << " + " << p[i].second << std::endl;
	}
}


std::vector<int>	PmergeMe::sortWithoutAlgo( std::vector<int> v ) {


	std::vector<int> sorted = v;
	while ( !PmergeMe::vectorIsSorted( sorted ) ) {
	
		for ( std::vector<int>::size_type i = 0; i < sorted.size(); i++ ) {
			if ( i+1 < sorted.size() && sorted[i] > sorted[i+1] ) {  std::swap( sorted[i], sorted[i+1] );  }
		}
	}
	
	return sorted;
}

bool	PmergeMe::vectorIsSorted( std::vector<int> v ) {

	for ( std::vector<int>::size_type i = 0; i < v.size(); i++ ) {

		if ( i+1 < v.size() && v[i] > v[i+1] ) {  return false;  }
	}
	
	return true;
}
