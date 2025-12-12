/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:12:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/12 17:12:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits> 

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span& other) {  *this = other;  }
Span::~Span() {}

Span&	Span::operator = (const Span& other) {

	if (this != &other) {  this->_N = other._N;  }
	return *this;
}



void	Span::addNumber(int newNumber) {

	unsigned int	already_in = std::distance(_numbers.begin(), _numbers.end());
	
	if (already_in < _N)
		this->_numbers.push_back(newNumber);
	else
		throw std::out_of_range("Error: there is no more place for this number");
}

int	Span::longestSpan() {

	int				min = INT_MAX;
	int				max = INT_MIN;
	std::vector<int>::iterator	it = _numbers.begin();

	while (it != _numbers.end()) {
		
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
		it++;
	}
	
	int	span = max - min;
	if (span < 0)
		span *= -1;

	return (span);
}

int	Span::shortestSpan() {

	int				span = INT_MAX;
	int				temp;
	int				previous;
	std::vector<int>::iterator	it = _numbers.begin();

	while (it != _numbers.end()) {
		if (it != _numbers.begin()) {
			temp = *it - previous;
			if (temp < 0) {  temp *= -1;  }
			if (temp < span)
				span = temp;
		}
		previous = *it;
		it++;
	}
	return span;
}
void	Span::addMultipleNumbers(std::vector<int>& other) {

	std::vector<int>::iterator	it = other.begin();
	while (it != other.end())
	{
		std::cout << "Adding number " << *it << std::endl;
		Span::addNumber(*it);
		std::cout << "Succes" << std::endl;

		it++;
	}
}
