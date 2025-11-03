/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:50:45 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/03 10:56:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl {

public:
	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif
