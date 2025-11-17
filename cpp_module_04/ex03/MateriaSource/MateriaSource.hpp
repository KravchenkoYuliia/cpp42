/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:15:21 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/17 10:15:21 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator = (const MateriaSource& other);

	~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

private:
	AMateria*	_slot[4];

};

#endif
