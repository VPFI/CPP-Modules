/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:15:34 by vperez-f          #+#    #+#             */
/*   Updated: 2025/01/29 18:56:27 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <ctime>
#include <iostream>
#include <cmath>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;

	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created"
	<< std::endl;
	return ;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed"
	<< std::endl;
	return ;
}
//-----------------------------------------------//

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//-----------------------------------------------//

 void 	Account::_displayTimestamp( void )
{
	std::time_t	date;
	char 		buff[124];
	tm			*formatted_date;

	date = time(NULL);
	formatted_date = gmtime(&date);
	strftime(buff, sizeof buff, "[%Y%m%d_%H%M%S] ", formatted_date);
	std::cout << buff;
}

 void 	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void 	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";";

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;

	std::cout
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits
	<< std::endl;

	_totalNbDeposits++;

	return ;
}

bool 	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";

	if (checkAmount() < withdrawal)
	{
		std::cout
			<< "withdrawal:" << "refused"
		<< std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
	}

	std::cout
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;

	_totalNbWithdrawals++;

	return (true);
}

int 	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void 	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}
