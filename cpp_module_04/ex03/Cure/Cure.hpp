/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:56:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:56:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public virtual AMateria {

public:
	Cure();
	Cure(const Cure& other);
	Cure&	operator = (const Cure& other);

	~Cure();
	
	AMateria*	clone() const;
};

#endif
