/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:25:28 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/19 16:18:50 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN( std::string calculation ) {  RPN::calculation(calculation);  }

RPN::RPN(const RPN& other) { *this = other; }

RPN&	RPN::operator=(const RPN& other) {

	if (this != &other) {}
	return *this;
}

RPN::~RPN() {}



void	RPN::calculation(std::string calculation) {

	if (!RPN::calculationIsValid(calculation)) {  throw std::runtime_error("Error: invalid input");  }

	int	sign = 1;
	for (int i = 0; calculation[i]; i++) {
	
		if (calculation[i] == '-' && calculation[i+1] && std::isdigit(calculation[i+1])) {  sign *= -1; i++;  }
		
		if (std::isdigit(calculation[i])) {

			if (calculation[i+1] && std::isdigit(calculation[i+1])) {  throw std::runtime_error("Error: invalid input");  }

			_numbers.push(sign * (calculation[i] - '0'));
			sign = 1;
		}
		else if (!std::isdigit(calculation[i]) && calculation[i] != ' ') {
			
			if (!calculation[i-1] || calculation[i-1] != ' ' || (calculation[i+1] && calculation[i+1] != ' ')) {  throw std::runtime_error("Error: invalid input");  }
			
			RPN::operation(calculation[i]);
		}
	}

	std::cout << "Result: " << _numbers.top() << std::endl;
}

void	RPN::operation(char type) {

	if (_numbers.size() < 2) {  throw std::runtime_error("Error: not enough numbers for the operation");  }
	
	int	second = _numbers.top();
	_numbers.pop();
	int	first = _numbers.top();
	_numbers.pop();
	
	if (type == '+')
		_numbers.push(first + second);
	else if (type == '-')
		_numbers.push(first - second);
	else if (type == '*')
		_numbers.push(first * second);
	else if (type == '/')
		_numbers.push(first / second);
}

bool	RPN::calculationIsValid(std::string calculation) {
	
	if (calculation == "") {  return false;  }

	for (int i = 0; calculation[i]; i++) {  if (!RPN::charIsValid(calculation[i])) { return false; }  }

	return true;
}

bool	RPN::charIsValid(char c) {

	std::string	validChars = "+-*/";

	if (std::isdigit(c)) {  return true;  }
	if (c == ' ') {  return true;  }

	for (int i = 0; validChars[i]; i++) {
		if (c == validChars[i]) {  return true;  }
	}

	return false;
}
