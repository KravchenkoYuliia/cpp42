/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:42:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/05 16:35:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"



int	main( void ) {

	Point	firstPoint(2.2f, 3.4f);
	Point	secondPoint(3.1f, 2.8f);

	std::cout << secondPoint << std::endl;
	return 0;
}
