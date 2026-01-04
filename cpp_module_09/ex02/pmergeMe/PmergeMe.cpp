/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/04 16:21:39 by yukravch         ###   ########.fr       */
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
	std::cout << std::endl;
	
	this->temp = 0;
	std::vector<int> result = PmergeMe::FJalgorithm( _nbV );
	std::cout << "After: ";
	PmergeMe::printVector( result );
	

	/*std::time_t	t = std::time(0);
	std::cout << t << std::endl;*/
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
	main.insert( main.begin(), pend[0] );
	
	//insert index 1 of pend
	
	int	index = 1;
	int	pendSize = pend.size();
	while ( index < pendSize ) {

		main = PmergeMe::insertNumber( pend[index], main, pairs );
		index++;
	}

	if ( straggler != NOSTRAGGLER )
			main = PmergeMe::insertStraggler( straggler, main );
	
	return main;
}

std::vector<int>	PmergeMe::insertStraggler( int straggler, std::vector<int> main ) {

	int mainSize = main.size();

	if ( straggler > main[ mainSize/2 ]) {
		for ( int i = mainSize/2 ; i < mainSize; i++) {
			
			if ( straggler < main[i] || i+1 == mainSize ) {

				main.insert( main.begin() + i, straggler);
				return main;
			}
		}
	}
	else {
		for ( int i = mainSize/2 ; i >= 0; i--) {

			if ( straggler > main[i] || i == 0) {

				if (i == 0)
					main.insert( main.begin() + i, straggler);
				else
					main.insert( main.begin() + i + 1, straggler);
				return main;
			}
		}
	}

	return main;
}

std::vector<int>	PmergeMe::insertNumber( int insertIt, std::vector<int> here, std::vector< std::pair<int, int> > pairs) {

	int	pairOfPend = PmergeMe::findPair( insertIt, pairs );
	if ( pairOfPend == -1) {  throw std::runtime_error("Error: no number you're looking for");  }


	int	maxPositionInMain = PmergeMe::findMainPositionForPair( pairOfPend, here );
	if ( maxPositionInMain == -1) {  throw std::runtime_error("Error: no position you're looking for");  }
		

	for ( int i = maxPositionInMain-1; i >= 0; i--) {
		if ( insertIt > here[i] || i == 0 ) {
		
			if ( i == 0 ) {  i = -1; }
			here.insert( here.begin() + i + 1, insertIt );
			break ;
		}
	}


	return here;
}

int	PmergeMe::findPair( int findIt, std::vector< std::pair<int, int> > inHere) {

	for ( std::vector< std::pair<int, int> >::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i].second == findIt ) {  return inHere[i].first;  }
	}

	return -1;
}

int	PmergeMe::findMainPositionForPair( int findIt, std::vector<int> inHere ) {

	int count = 0;
	for ( std::vector<int>::size_type i = 0; i < inHere.size(); i++ ) {
		if ( inHere[i] == findIt ) {  return count;  }
		count += 1;
	}

	return -1;
}

void	PmergeMe::makePairs( void ) {
	
	std::vector<int>::size_type i = 0;
	while ( i+1 < _nbV.size() ) {

		if ( _nbV[i] > _nbV[i+1])
			_pairsV.push_back(  std::make_pair( _nbV[i+1], _nbV[i] )  );
		else
			_pairsV.push_back(  std::make_pair( _nbV[i], _nbV[i+1] )  );

		if ( i+2 < _nbV.size() ) {  i += 2;  }
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
	
	if ( v.empty() ) {  std::cout << "empty" << std::endl;  }
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

void	PmergeMe::printPairs( std::vector< std::pair<int, int> > p) {


	if ( p.empty() ) {  std::cout << "pairs are empty" << std::endl;  }
	for ( std::vector< std::pair<int, int> >::size_type i = 0; i < p.size(); i++) {
		std::cout << "Pair : " << p[i].first << " + " << p[i].second << std::endl;
	}
}
