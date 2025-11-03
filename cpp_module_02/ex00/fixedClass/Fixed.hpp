/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:45:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 17:34:39 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

class Fixed {

private:
	static const int	_nbFractionalBits;
	int			_value;

public:
	Fixed();
	Fixed(const Fixed &copyNumber);
	
	void	setRawBits( int const raw );
	int	getRawBits( void ) const;
	
	~Fixed();

};

#endif
