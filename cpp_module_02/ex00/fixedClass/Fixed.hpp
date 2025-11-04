/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/04 11:07:56 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {

private:
	static const int	_nbFractionalBits = 8;
	int			_value;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator = (const Fixed& other);

	void	setRawBits( int const raw );
	int	getRawBits( void ) const;
	
	~Fixed();

};

#endif
