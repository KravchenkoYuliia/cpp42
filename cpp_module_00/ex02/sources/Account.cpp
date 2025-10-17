/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:59:16 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/17 19:31:32 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) {

	std::cout << "Called constructor/ " <<  "Initial depot is: " << initial_deposit << std::endl;

}

static void	Account::displayAccountsInfos() {

	
}

Account::~Account() {

	std::cout << "Called destructor" << std::endl;
}
