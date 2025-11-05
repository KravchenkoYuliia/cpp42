/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:33:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/05 16:28:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { //Default constructor

}

Point::Point(const float nb1, const float nb2) : _x(Fixed(nb1)), _y(Fixed(nb2)) { //Float constructor

}

Point::Point(const Point& other) : _x(other._x), _y(other._y) { //Copy constructor

}

float	Point::getX() const{

	return Point::_x.toFloat();
}

float	Point::getY() const{

	return Point::_y.toFloat();
}

Point::~Point() {

}
