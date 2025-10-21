/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_functions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:22:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/21 18:29:17 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"

void	Account::makeDeposit(int deposit) {

	Account::_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";deposit:" << deposit << ";amount:" << Account::_amount + deposit << ";nb_deposits:" << Account::_nbDeposits << std::endl;
	
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:";

	if (Account::_amount - withdrawal >= 0) {
		
		Account::_nbWithdrawals++;
		Account::_totalNbWithdrawals++;

		Account::_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;

		std::cout << withdrawal << ";amount:" << Account::_amount << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	}
	else
		std::cout << "refused" << std::endl;

	return true;
}

int	Account::checkAmount( void ) const {

	//???
	return Account::_amount;
}

void	Account::displayStatus() const {

	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}
