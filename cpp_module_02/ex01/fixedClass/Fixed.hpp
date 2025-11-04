/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/04 12:21:16 by yukravch         ###   ########.fr       */
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
	//Constructors
	
	Fixed(); 		//Default constructor
	Fixed(const int nb);    //Converts nb to the fixed-point value
	Fixed(const float nb);  //Converts nb to the fixed-point value

	Fixed(const Fixed& other); 		//copy constructor
	Fixed& operator = (const Fixed& other); //assignement operator

	float	toFloat( void ) const;	//Converts fixed-point value to a floating-point one
	int	toInt( void ) const;	//Converts fixed-point value to a integer one
	
	void	setRawBits( int const raw );
	int	getRawBits( void ) const;
	
	friend std::ostream& operator<<(std::ostream& out, const Fixed& c);
	~Fixed();

};

#endif
