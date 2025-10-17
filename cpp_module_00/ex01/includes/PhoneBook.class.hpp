/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:27:11 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 18:29:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();
	
	int		counter;
	int		nb_of_users;
	bool		empty;

	void		ft_start_prompt();
	int		ft_get_cmd();
	int		ft_add();
	void		ft_set_users_data(int i);
	int		ft_search();
	void		ft_write_horizontal_line();
	void		ft_write_table_headlines();
	void		ft_write_users_data();
	void		ft_write_full_user_data(int index);
	std::string	ft_format(int type, int index);
	void		ft_exit();

private:
	std::string	line;
	std::string	input;
	Contact		user[12];
};

#endif
