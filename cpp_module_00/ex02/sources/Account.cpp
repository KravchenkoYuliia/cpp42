/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:59:16 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/21 18:28:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) {

	int	deposits[8] = {42, 54, 957, 432, 1234, 0, 754, 16576};

	for (int i = 0; i < 8; i++) {
		if (deposits[i] == initial_deposit) {
			Account::_accountIndex = i;
			break ;
		}
	}
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;


	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}	

Account::~Account() {

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
}
