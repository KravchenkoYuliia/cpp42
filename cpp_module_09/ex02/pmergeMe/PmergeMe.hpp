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

	static void			countTime( std::string container, int containerSize, int beforeTime, int afterTime );
	static std::vector<int>		sortWithoutAlgo( std::vector<int> v );
	static std::vector<int>		FJalgorithm( std::vector<int> v );
	static void			printVector( std::vector<int> v );
	static std::vector<int>		insertNumber( int insertIt, std::vector<int> here, std::vector< std::pair<int, int> >	pairs );
	static std::vector<int>		insertStraggler( int straggler, std::vector<int> main );
	static int			findPair( int findIt, std::vector< std::pair<int, int> > inHere );
	static int			findMainPositionForPair( int findIt, std::vector<int> inHere );
	static bool			vectorIsSorted( std::vector<int> v );
	static void			getNextIndexWithJacobsthalSequence( int& index, int& previousIndex, int& previousOfThePreviousIndex );

private:
	void	sorting( char** av );
	void	fillContainers( char** av );
	void	avIsValid( std::string str );
	void	sortVector( void );
	void	makePairs( void );
	
	void	printPairs( std::vector< std::pair<int, int> > p );

	std::vector<int>			_nbV;
	std::vector< std::pair<int, int> >	_pairsV;










	void	printList();
	std::list<int>		_nbL;
	
};

template <typename T>
void	printTimeCallAlgo( T& container, std::string type );

#include "PmergeMe.tpp" 

#endif
