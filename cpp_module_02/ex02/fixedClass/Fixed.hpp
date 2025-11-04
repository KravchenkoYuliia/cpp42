/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/04 15:00:09 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

private:
	static const int	_nbFractionalBits = 8;
	int			_value;

public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	Fixed(const Fixed& other);
	Fixed& operator = (const Fixed& other);

	bool operator > (const Fixed& other);
	bool operator < (const Fixed& other);
	bool operator >= (const Fixed& other);
	bool operator <= (const Fixed& other);
	bool operator == (const Fixed& other);
	bool operator != (const Fixed& other);

	int operator + (const Fixed& other);
	int operator - (const Fixed& other);
	int operator / (const Fixed& other);
	int operator * (const Fixed& other);
	
	float	toFloat( void ) const;
	int	toInt( void ) const;
	
	void	setRawBits( int const raw );
	int	getRawBits( void ) const;
	
	~Fixed();

	friend std::ostream& operator<<(std::ostream& out, const Fixed& c);
};

#endif
