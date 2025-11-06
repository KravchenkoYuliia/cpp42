/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:42:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/06 11:52:03 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float	getArea (Point const a, Point const b, Point const c ) {

	float	area = a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - b.getY());

	if (area < 0)
		area += -1;
	return area / 2;
}

bool	checkifPointOnVertex( Point const a, Point const b, Point const c, Point const pointToCheck ) {

	if (pointToCheck.getX() == a.getX() && pointToCheck.getY() == a.getY())
		return true;
	if (pointToCheck.getX() == b.getX() && pointToCheck.getY() == b.getY())
		return true;
	if (pointToCheck.getX() == c.getX() && pointToCheck.getY() == c.getY())
		return true;
	return false;
}

bool	bsp( Point const a, Point const b, Point const c, Point const pointToCheck) {

	if (checkifPointOnVertex(a, b, c, pointToCheck))
		return false;
	
	float	areaABC = getArea(a, b, c); //main triangle
	if (areaABC == 0)
		return false;

	float	areaPAB = getArea(pointToCheck, a, b);
	float	areaPBC = getArea(pointToCheck, b, c);
	float	areaPCA = getArea(pointToCheck, c, a);
	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return false;

	float	areaSum = areaPAB + areaPBC + areaPCA;
	if (std::abs(areaABC - areaSum) < 0.01)
		return true;
	else
		return false;
}

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
