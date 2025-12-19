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

class RPN {

public:
	RPN();
	RPN(const RPN& other);
	RPN&	operator = (const RPN& other);

	~RPN();

	void	calculation(std::string av);

private:
	std::stack<int>		_numbers;
	
	bool	avIsValid(std::string av);
	bool	charIsValid(char c);
	void	operation(char type);
};

#endif
