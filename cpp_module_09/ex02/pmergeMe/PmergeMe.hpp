/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:16:19 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/19 18:16:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm> 
#include <vector>
#include <list> 
#include <cstdlib>
#include <sstream>
#include <climits>
#include <ctime> 
#include "colors.hpp"

#define	NOLAST -1

class PmergeMe {

public:
	PmergeMe();
	PmergeMe(char** av);
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator = (const PmergeMe& other);

	~PmergeMe();

private:
	void	sorting(char** av);
	void	fillContainers(char** av);
	void	avIsValid(std::string str);

	void	sortVector();
	void	makeAndSortPairs();
	bool	maxValueAreSorted();
	void	sortList();
	
	void	printVector();
	void	printList();

	std::vector<int>			_nbV;
	std::vector< std::pair<int, int> >	_pairsV;
	int					_lastNbWithoutPair;
	std::list<int>		_nbL;

};

#endif
