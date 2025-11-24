/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:23:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/24 16:23:02 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer {

public:
	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);

private:	
	Serializer();
	Serializer(const Serializer& other);
	Serializer&	operator = (const Serializer& other);

	~Serializer();

};

#endif
