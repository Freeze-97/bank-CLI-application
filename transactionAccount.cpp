// Tommy Yasi/toya1800
// Created by Admin on 2019-05-21.
// Funktionsdefinition för klassen TransactionAccount
#include "transactionAccount.h"
using namespace std;

TransactionAccount::~TransactionAccount() = default; // Standard

bool TransactionAccount::withdraw(double &amount) {
    if(amount > getBalance() + credit) { // Om man vill ta ut mer än vad man kan
        return false;
    }
    if(getBalance() <= 0 && amount <= credit) {
        credit -= amount;
    }
    else if(amount <= getBalance() + credit && getBalance() > 0) {
        double tmpBalance = getBalance();
        Konto::withdraw(amount);
        if(getBalance() < 0 && tmpBalance > 0) {
            credit -= tmpBalance - amount;
        }
        else if(getBalance() < 0) {
            credit -= amount;
        }
    }
    withdrawals++;
    return true;
}

void TransactionAccount::changeCredit(double &amount) {
    credit = amount;
}

string TransactionAccount::getAccountType() const {
    return "TransactionAccount";
}

double TransactionAccount::getCredit() const {
    return credit;
}

double TransactionAccount::getDisBalance() const {
        return getBalance() + credit;
}

int TransactionAccount::getNrOfWithdrawals() const {
    return withdrawals;
}
