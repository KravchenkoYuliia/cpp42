/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:10:51 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 15:37:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
#define INCLUDE_H


#include <iostream>
#include <stdio.h>

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"


#define SUCCESS 0
#define EXIT 100

#define INDEX 5
#define FIRST_NAME 10
#define LAST_NAME 20
#define NICKNAME 30
#define PHONE 40
#define SECRET 50



#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define BOLD "\033[1m"

#define RESET_ALL "\033[0m"
#define RESET_UNDERLINE "\033[4m"
#define RESET_BLINK "\033[25m"
#define RESET_BOLD "\033[22m"

#define PROMPT_COLOR "\033[38;5;205m"
#define PIPE_COLOR "\033[38;5;123m"
#define HEADLINES_COLOR "\033[38;5;105m"
#define USER_DATA_COLOR "\033[38;5;39m"

#define MAGENTA_BACKGROUND "\033[45m"
#define WHITE_BACKGROUND "\033[107m"


#endif
