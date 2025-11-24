/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:23:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/24 16:23:02 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) { *this = other; }

Serializer&	Serializer::operator=(const Serializer& other) {

	if (this != &other) {}
	return *this;
}

Serializer::~Serializer() {}
