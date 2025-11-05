/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/05 14:14:54 by yukravch         ###   ########.fr       */
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
	Fixed&	operator = (const Fixed& other);

	bool	operator > (const Fixed& other) const;
	bool	operator < (const Fixed& other) const;
	bool	operator >= (const Fixed& other) const;
	bool	operator <= (const Fixed& other) const;
	bool	operator == (const Fixed& other) const;
	bool	operator != (const Fixed& other) const;

	Fixed	operator+(Fixed const &other) const;
	Fixed	operator-(Fixed const &other) const;
	Fixed	operator*(Fixed const &other) const;
	Fixed	operator/(Fixed const &other) const;
	
	Fixed&	operator++(); //pre-increment (++i)
	Fixed&	operator--(); //pre-decrement (--i) changes the object and returns its reference immediatly
	
	Fixed	operator++( int ); //post-increment (++i)
	Fixed	operator--( int ); //post-decrement (--i) returns a copy of the old object and changes it after
				   //int is not used, write it just to make a difference between pre- and post-decrement

	float	toFloat( void ) const;
	int	toInt( void ) const;
	
	void	setRawBits( int const raw );
	int	getRawBits( void ) const;
	
	~Fixed();

	friend std::ostream& operator<<(std::ostream& out, const Fixed& c);
};

#endif
