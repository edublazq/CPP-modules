#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_totalAmount -= _amount;
	_nbAccounts--;
}

void	Account::makeDeposit(int amount)
{
	if (amount < 0)
		return ;
	_amount += amount;
	_totalAmount += amount;
	_totalNbDeposits++;
	_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
		return (false);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
