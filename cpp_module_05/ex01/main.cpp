/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:00:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/18 17:00:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp" 
#include "Bureaucrat.hpp" 

int	main() {

	Bureaucrat	b("STEVE", 8);
	std::cout << b << std::endl << std::endl;

	Form		f("DECLARATION D'IMPOT", 10, 1);
	std::cout << f << std::endl << std::endl;
	b.signForm(f);
	b.execForm(f);
	std::cout << std::endl;
}
