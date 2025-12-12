/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:12:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/12 17:12:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector> 
#include <algorithm> 

class	Span {

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	~Span();

	Span&	operator = (const Span& other);

	void	addNumber(int newNumber);
	void	addMultipleNumbers(std::vector<int>& other);
	int	shortestSpan();
	int	longestSpan();

private:
	std::vector<int> _numbers;
	unsigned int	_N;

};
