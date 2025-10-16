/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:14:14 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 15:15:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"


void	Contact::ft_set_data(int type, int index, std::string data) {

	if (type == INDEX)
		this->index = index;
	else if (type == FIRST_NAME)
		this->first_name = data;
	else if (type == LAST_NAME)
		this->last_name = data;
	else if (type == NICKNAME)
		this->nickname = data;
	else if (type == PHONE)
		this->phone_number = data;
	else if (type == SECRET)
		this->darkest_secret = data;
}

std::string	Contact::ft_get_first_name() const {

	return this->first_name;
}

std::string	Contact::ft_get_last_name() const {

	return this->last_name;
}

std::string	Contact::ft_get_nickname() const {

	return this->nickname;
}

std::string	Contact::ft_get_phone() const {

	return this->phone_number;
}

std::string	Contact::ft_get_secret() const {

	return this->darkest_secret;
}
