/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:35:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 15:14:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact{

public:
	//void	ft_set_index(int index);
	void	ft_set_data(int type, int index, std::string data);
	
	std::string	ft_get_first_name() const;
	std::string	ft_get_last_name() const;
	std::string	ft_get_nickname() const;
	std::string	ft_get_phone() const;
	std::string	ft_get_secret() const;

private:
	int		index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif
