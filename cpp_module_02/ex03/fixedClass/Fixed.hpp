/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/05 16:35:10 by yukravch         ###   ########.fr       */
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
	
	~Fixed();

	void	setRawBits( int const raw );
	int	getRawBits( void ) const;

	float		toFloat( void ) const;
	int		toInt( void ) const;
	static		Fixed&	min(Fixed& one, Fixed& two);
	static		Fixed&	max(Fixed& one, Fixed& two);
	static const	Fixed&	min(const Fixed& one, const Fixed& two);
	static const	Fixed&	max(const Fixed& one, const Fixed& two);
	
	

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
	
	Fixed&	operator++(); 		//pre-increment (++i)
	Fixed&	operator--(); 		//pre-decrement (--i) changes the object and returns its reference immediatly
	Fixed	operator++( int ); 	//post-increment (++i)
	Fixed	operator--( int ); 	//post-decrement (--i) returns a copy of the old object and changes it after
			   		//int is not used, write it just to make a difference between pre- and post-decrement
	
};
/*
std::ostream& operator<<(std::ostream &out, const Fixed& c) { //"<<" STREAM INSERTION OPEATOR

	out << c.toFloat();
	return out;
}*/


#endif
