/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:14:35 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/14 10:14:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
}

Cure::Cure(const Cure &other) {
    *this = other;
}

Cure & Cure::operator=(const Cure &other) {
    if (this != &other) {
        // copy members
    }
    return *this;
}

Cure::~Cure() {
}
