/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:42:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/06 11:57:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void ) {

	Point const	a(2.2f, 3.4f);
	Point const	b(3.1f, 2.8f);
	Point const	c(4.8f, 5.6);

	Point const	pointToCheck(3.5f, 3.9f); //Точка P(3.5, 3.9) → inside the triangle
						//Точка P(4.0, 5.8) → outside the triangle
						//Точка P(3.1, 2.8) → on a border
	
	if (bsp(a, b, c, pointToCheck))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside of the triangle" << std::endl;
	return 0;
}
