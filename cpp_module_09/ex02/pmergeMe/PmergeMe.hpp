/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/29 19:00:50 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip> 
#include <algorithm> 
#include <vector>
#include <list> 
#include <cstdlib>
#include <sstream>
#include <climits>
#include <ctime> 
#include "colors.hpp"

#define	NOSTRAGGLER -1

class PmergeMe {

public:
	PmergeMe();
	PmergeMe(char** av);
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator = (const PmergeMe& other);

	~PmergeMe();

private:
	void	sorting( char** av );
	void	fillContainers( char** av );
	void	avIsValid( std::string str );
	void	countTime( std::string container, int containerSize, int beforeTime, int afterTime );

	void			sortVector( void );
	void			makePairs( void );
	int			findPair( int findIt, std::vector< std::pair<int, int> > inHere );
	int			findMainPositionForPair( int findIt, std::vector<int> inHere );
	std::vector<int>	insertNumber( int insertIt, std::vector<int> here, std::vector< std::pair<int, int> >	pairs );
	std::vector<int>	insertStraggler( int straggler, std::vector<int> main );
	std::vector<int>	FJalgorithm( std::vector<int> v );
	
	void	printVector( std::vector<int> v );
	void	printPairs( std::vector< std::pair<int, int> > p );

	std::vector<int>			_nbV;
	std::vector< std::pair<int, int> >	_pairsV;










	void	printList();
	std::list<int>		_nbL;
	
};

#endif
