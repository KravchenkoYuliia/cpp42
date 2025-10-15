/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:27:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 15:26:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {

public:
	void    ft_start_prompt();
	void	ft_get_cmd();

private:
	int		counter;
	std::string	line;
	Contact		data[8];
};

#endif
