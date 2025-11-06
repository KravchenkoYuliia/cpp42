/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:33:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/06 11:17:09 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>

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

std::ostream& operator<<(std::ostream &out, const Point& c) { //"<<" STREAM INSERTION OPEATOR
        out << "Point x[" << std::setprecision(2) << c.getX() << "]" << std::endl;
        out << "Point y[" << c.getY() << "]" << std::endl;
        return out;
}

Point::~Point() {

}
