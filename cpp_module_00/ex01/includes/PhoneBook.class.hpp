/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:27:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:32:15 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	
	int		counter;
	void	ft_start_prompt();
	void	ft_get_cmd();
	void	ft_add();
	void	ft_search();
	void	ft_exit();

private:
	std::string	line;
	std::string	input;
	Contact		data[8];
};

#endif
