/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:00:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/19 12:51:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp" 
#include "Bureaucrat.hpp" 

int	main() {

	Bureaucrat	b("STEVE", 8);
	std::cout << b << std::endl << std::endl;

	std::cout << "***************** can sign - can't execute ***************" << std::endl;
	Form		f("DECLARATION D'IMPOT", 10, 2);
	std::cout << f << std::endl << std::endl;
	b.signForm(f);
	b.execForm(f);
	std::cout << std::endl;

	std::cout << "***************** can sign - can execute ***************" << std::endl;
	std::cout << "Upgrading " << b.getName() << "'s grade by 6" << std::endl;
	b.upgradeGrade(6);
	std::cout << b << std::endl << std::endl;
	b.signForm(f);
	b.execForm(f);
	std::cout << std::endl;

	std::cout << "***************** can't sign - can execute by grade but it has to be sign first ***************" << std::endl;
	std::cout << b << std::endl;
	Form	f2("Testament inutile", 1, 20);
	b.signForm(f2);
	b.execForm(f2);
	std::cout << std::endl;
}
