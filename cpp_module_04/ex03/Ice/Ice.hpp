/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:56:10 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:56:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public virtual AMateria{

public:
	Ice();
	Ice(const Ice& other);
	Ice&	operator = (const Ice& other);

	~Ice();
	
	AMateria*	clone() const;
};

#endif
