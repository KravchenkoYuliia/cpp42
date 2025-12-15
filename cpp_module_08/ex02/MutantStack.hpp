/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:56:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/15 13:56:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream> 
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack() {}
	MutantStack(const MutantStack& other) {  *this = other;  }
	MutantStack&	operator = (const MutantStack& other) {  if (this != &other) {} return *this;  }
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typename std::stack<T>::container_type::iterator	begin() {  return this->c.begin();  }
	typename std::stack<T>::container_type::iterator	end() {  return this->c.end();  }
};

#endif
