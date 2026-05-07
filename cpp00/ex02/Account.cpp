#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << 
				";amount:" << _amount <<
				";created" << std::endl; 
}

Account::~Account()
{
	_totalAmount -= _amount;
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << 
			";amount:" << _amount <<
			";closed" << std::endl; 
}

void	Account::makeDeposit(int amount)
{
	if (amount < 0)
		return ;
	_amount += amount;
	_totalAmount += amount;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount - amount
				<< ";deposit:" << amount
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex
					<< ";p_amount:" << _amount
					<< ";withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount + withdrawal
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

void	Account::_displayTimestamp(void)
{
	char		buf[20];
	time_t		now = time(NULL);
	struct tm	*current = localtime(&now);

	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", current);
	std::cout << buf;
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

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts <<
				";total:" << _totalAmount <<
				";deposits:" << _totalNbDeposits <<
				";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}
