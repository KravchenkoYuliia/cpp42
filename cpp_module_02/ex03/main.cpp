/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:42:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/07 17:09:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void ) {

	Point const	a(1, 1);
	Point const	b(1, 3);
	Point const	c(3, 1);

	Point const	pointToCheck(2, 1); //point P(1.5, 2) → inside the triangle
						
						//point P(3, 3.8) → outside the triangle
						//point P(1, 2) → on a border = outside
						//point P(3, 1) → same as Point C = outside
	
	if (bsp(a, b, c, pointToCheck))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside of the triangle" << std::endl;
	return 0;
}
