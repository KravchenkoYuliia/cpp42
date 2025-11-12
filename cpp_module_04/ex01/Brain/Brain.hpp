/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:24:01 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/12 12:18:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BRAIN_HPP
#define	BRAIN_HPP

#include <iostream>

class Brain {

public:
	Brain();
	Brain(const Brain& other);
	Brain&	operator = (const Brain& other);
	
	~Brain();
	
	std::string	getIdeas(int i) const;

private:
	std::string	_ideas[100];
	
};

#endif

