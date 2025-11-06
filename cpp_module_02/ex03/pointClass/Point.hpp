/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:33:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/06 11:15:54 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point {


public:
	Point();
	~Point();
	
	Point(const float nb1, const float nb2);
	Point(const Point& other);
	
	Point&		operator = (const Point& other);

	float		getX() const;
	float		getY() const;

private:
	const Fixed	_x;
	const Fixed	_y;

};


std::ostream&	operator << (std::ostream &out, const Point& c);
bool		bsp( Point const a, Point const b, Point const c, Point const point);
float		getArea( Point const a, Point const b, Point const c);
