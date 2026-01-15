/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:25:28 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/19 15:25:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include  <climits>
class RPN {

public:
	RPN();
	RPN( std::string calculation );
	RPN( const RPN& other );
	RPN&	operator = ( const RPN& other );

	~RPN();


private:
	std::stack<int>		_numbers;
	
	void	calculation( std::string calculation );
	bool	calculationIsValid( std::string calculation );
	bool	charIsValid( char c );
	void	operation( char type );
	bool	hasOnlyOneDigit( std::string calculation );
};

#endif
