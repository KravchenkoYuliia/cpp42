/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:34:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/11 18:34:52 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat& other);
	WrongCat&	operator = (const WrongCat& other);
	
	void	makeSound() const;
	~WrongCat();
};

#endif

