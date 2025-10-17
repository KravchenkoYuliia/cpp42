/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:27:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 15:43:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	
	int		counter;
	void		ft_start_prompt();
	int		ft_get_cmd();
	void		ft_add();
	void		ft_set_users_data(int i);
	void		ft_search();
	void		ft_horizontal_line();
	std::string	ft_format(int type, int index);
	void		ft_exit();

private:
	std::string	line;
	std::string	input;
	Contact		user[12];
};

#endif
