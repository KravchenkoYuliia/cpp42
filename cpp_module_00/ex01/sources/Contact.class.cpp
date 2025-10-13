/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:14 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 13:23:01 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	Contact::ft_set(int index, int type, const char* data) {

	Contact::index = index;
	if (type == 1)
		Contact::first_name = data;
}

void	Contact::ft_get(int type) {

	if (type == 1)
		std::cout << '[' << Contact::index << "] " << Contact::first_name << std::endl;
}
