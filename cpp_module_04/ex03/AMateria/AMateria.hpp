/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:12:30 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:12:30 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"
class AMateria {
    
public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	
	~AMateria();
        
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);


protected:
	const std::string	_type;

};

#endif
