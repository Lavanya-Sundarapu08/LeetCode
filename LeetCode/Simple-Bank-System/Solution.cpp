#include <vector>
using namespace std;

class Bank {
private:
    vector<long long> balance; // stores balances for each account

    // Helper to check if account number is valid
    bool isValidAccount(int account) {
        return account >= 1 && account <= (int)balance.size();
    }

public:
    // Constructor: initialize balances
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    // Transfer money from account1 to account2
    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1) || !isValidAccount(account2))
            return false;
        if (balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    // Deposit money into given account
    bool deposit(int account, long long money) {
        if (!isValidAccount(account))
            return false;

        balance[account - 1] += money;
        return true;
    }

    // Withdraw money from given account
    bool withdraw(int account, long long money) {
        if (!isValidAccount(account))
            return false;
        if (balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }
};

