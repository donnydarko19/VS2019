#ifndef account_h
#define account_h

class account
{
	private:
		double balance;
		double interestRate;
		double interest;
		int transactions;
	public:	
	account (double iRate = 0.035, double bal = 0)
	{
		balance = bal;
		interestRate = iRate;
		interest = 0;
		transactions = 0;
	}

	void setInterestRate(double iRate)
	{
		interestRate = iRate;
	}
	
	void makeDeposit(double sum)
	{
		balance += sum;
		transactions++;
	}

	void makeWithdrawal(double loss)	
	{			
		balance -= loss;
		transactions++;
	}

	void calcInterest()
	{
		interest = balance * interestRate;
		balance += interest;
	}

	void getInterestRate() const
	{
		return interestRate;
	}

	void getBalance() const
	{
		return balance;
	}

	void getInterest() const
	{
		return interest;
	}

	int getTransactions() const
	{
		return transactions;
	}
};
#endif
