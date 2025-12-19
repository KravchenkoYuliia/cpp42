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

RPN::RPN(const RPN& other) { *this = other; }

RPN&	RPN::operator=(const RPN& other) {

	if (this != &other) {}
	return *this;
}

RPN::~RPN() {}



void	RPN::calculation(std::string av) {

	if (!RPN::avIsValid(av)) {  throw std::runtime_error("Error: invalid input");  }

	int	sign = 1;
	for (int i = 0; av[i]; i++) {
	
		if (av[i] == '-' && av[i+1] && std::isdigit(av[i+1])) {  sign *= -1; i++;  }
		
		if (std::isdigit(av[i])) {

			if (av[i+1] && std::isdigit(av[i+1])) {  throw std::runtime_error("Error: invalid input");  }

			_numbers.push(sign * (av[i] - '0'));
			sign = 1;
		}
		else if (!std::isdigit(av[i]) && av[i] != ' ') {
			
			if (!av[i-1] || av[i-1] != ' ' || (av[i+1] && av[i+1] != ' ')) {  throw std::runtime_error("Error: invalid input");  }
			
			RPN::operation(av[i]);
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

bool	RPN::avIsValid(std::string av) {
	
	if (av == "") {  return false;  }

	for (int i = 0; av[i]; i++) {  if (!RPN::charIsValid(av[i])) { return false; }  }

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
