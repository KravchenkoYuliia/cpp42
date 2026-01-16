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
#include <deque> 
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

	static int			findPair( int findIt, std::vector< std::pair<int, int> >& inHere );
	static void			getNextIndexWithJacobsthalSequence( int& index, int& previousIndex, int& previousOfThePreviousIndex );
	static void			printPairsV( std::vector< std::pair<int, int> > p );

private:
	void	sorting( char** av );
	void	fillContainers( char** av );
	void	avIsValid( std::string str );
	void	sortVector( void );
	void	makePairs( void );
	

	std::vector< std::pair<int, int> >	_pairsV;
	std::deque< std::pair<int, int> >	_pairsD;

	std::vector<int>	_v;
	std::deque<int>		_d;
	
};

template <typename T>
void	printTimeCallAlgo( T& container, std::string type );

template <typename T>
T	FJalgorithm( T container );

template <typename T>
void	printContainer( T& container, std::string type );

template <typename T>
T	sortWithoutAlgo( T v );

template <typename T>
T	insertNumber( int insertIt, T here, std::vector< std::pair<int, int> >	pairs );

template <typename T>
T	insertStraggler( int straggler, T main );

template <typename T>
int	findMainPositionForPair( int findIt, T& inHere );


template <typename T>
bool	vectorIsSorted( T v );

#include "PmergeMe.tpp" 

#endif
