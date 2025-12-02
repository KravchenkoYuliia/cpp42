/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:25:43 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/29 18:32:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T& a, T& b) {

	T c = a;
	a = b;
	b = c;
}

template <typename T> T min(T a, T b) {

	if (a < b)
		return a;
	return b;
}

template <typename T> T max(T a, T b) {


	if (a > b)
		return a;
	return b;
}

#endif
