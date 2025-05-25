// Tommy Yasi/toya1800
// Created by Admin on 2019-05-25.
// Funktionsdefinitionsfil för klassen LongSavingsAccount
#include "longSavingsAccount.h"
using namespace std;


bool LongSavingsAccount::withdraw(double &amount) {
    if(withdrawals == maxWithdrawals) { // Max 4 uttag tillåtet
        return false;
    }
    SavingsAccount::withdraw(amount);
    withdrawals++;
    return true;
}

void LongSavingsAccount::setInterest(double inter) {
    interest = inter;
}

string LongSavingsAccount::getAccountType() const {
    return "SavingsAccount";
}

double LongSavingsAccount::getDisBalance() const {
    return getBalance();
}

int LongSavingsAccount::getMaxWithdrawal() const {
    return maxWithdrawals;
}

int LongSavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

double LongSavingsAccount::getInterest() const {
    return interestRate;
}
