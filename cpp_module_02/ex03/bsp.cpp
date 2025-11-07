/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:56:03 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/06 11:56:39 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

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
