/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_stdout.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:14:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 16:22:18 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

void	PhoneBook::ft_start_prompt() {
	
	std::cout << BLINK << PROMPT_COLOR << "Put your command: "
		<< RESET_ALL
		<< PROMPT_COLOR
		<< UNDERLINE << "ADD"
		<< RESET_ALL
		<< PROMPT_COLOR
		<< ", "
		<< UNDERLINE
		<< "SEARCH"
		<< RESET_ALL
		<< PROMPT_COLOR
		<< " or "
		<< UNDERLINE
		<< "EXIT"
		<< RESET_ALL
		<< std::endl;
}	

void	PhoneBook::ft_write_table_headlines() {

	std::cout << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "     Index"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "First name"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << " Last name"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< BOLD << HEADLINES_COLOR << "  Nickname"
		<< RESET_BOLD << PIPE_COLOR << '|'
		<< RESET_ALL << std::endl;
}

void	PhoneBook::ft_write_user_data() {

	for (int i = 0; i < 8; i++) {

		std::cout << PIPE_COLOR << '|'
			<< USER_DATA_COLOR << "         " << i + 1
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(FIRST_NAME, i)
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(LAST_NAME, i)
			<< PIPE_COLOR << '|'
			<< USER_DATA_COLOR << ft_format(NICKNAME, i)
			<< PIPE_COLOR << '|'
			<< RESET_ALL << std::endl;

	}
}
