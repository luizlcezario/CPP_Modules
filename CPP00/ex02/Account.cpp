/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:37:01 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:47:46 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructors
Account::Account(int initial_deposit ) {
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";created" << std::endl;
}

Account::Account( void ) {
	this->_accountIndex = getNbAccounts();
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts ++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";created" << std::endl;
}

// Destructor
Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";closed";
	std::cout << std::endl;
}
// static methods
int		Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:"<< getNbAccounts() <<";total:"<< getTotalAmount() <<";deposits:"<< getNbDeposits() <<";withdrawals:" << getNbWithdrawals() << std::endl;
}
// methods public
int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::makeDeposit(int deposit ) {
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" 
		<< checkAmount() - deposit <<  ";deposit:" << deposit << ";amount:"
		<< checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal ) {
	_displayTimestamp();
	if (withdrawal < _amount) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" 
			<< checkAmount() + withdrawal <<  ";withdrawal:" << withdrawal 
			<< ";amount:"<< checkAmount() << ";nb_withdrawals:" 
			<< this->_nbDeposits << std::endl;
		return true;
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" 
		<< checkAmount() << ";withdrawal:refused" << std::endl;
	// index:0;p_amount:47;withdrawal:refused
	return false;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// methods private 

void	Account::_displayTimestamp( void ) {
	time_t presnt_time = std::time(0);
	tm *ltm = std::localtime(&presnt_time);
	char buffer[16];

	std::strftime(buffer, 16,"%Y%m%d_%H%M%S" , ltm);
	std::cout << "[" << buffer << "] ";
}
