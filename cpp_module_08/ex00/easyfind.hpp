/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:47:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/11 14:47:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP 
#define EASYFIND_HPP 

#include <algorithm> 
#include <iostream> 

template <typename T>
typename T::iterator	easyfind(T& container, int value_to_find) {

	auto	it = find(container.begin(), container.end(), value_to_find);
	if (it == container.end())
		throw std::out_of_range("Error: there is no value you're looking for");
	return *it;
}


#endif
