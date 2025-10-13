/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:35:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 13:23:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact{

public:
	void	ft_set(int index, int type, const char* data);
	void	ft_get(int type);

private:
	int		index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
};

#endif
