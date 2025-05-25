// Tommy Yasi/toya1800
// Created by Admin on 2019-05-22.
// Funktionsdefinition för klassen SavgingsAccount
#include "savingsAccount.h"

SavingsAccount::~SavingsAccount() = default; // Standard

bool SavingsAccount::withdraw(double &amount) {
    if(withdrawals == maxWithdrawals) { // Max 4 uttag tillåtet
        return false;
    }
    Konto::withdraw(amount);
    withdrawals++;
    return true;
}

void SavingsAccount::setInterest(double inter) {
    interest = inter;
}

std::string SavingsAccount::getAccountType() const {
    return "SavingsAccount";
}

double SavingsAccount::getDisBalance() const {
    return getBalance();
}

int SavingsAccount::getMaxWithdrawal() const {
    return maxWithdrawals;
}

int SavingsAccount::getNrOfWithdrawals() const {
    return withdrawals;
}

double SavingsAccount::getInterest() const {
    return interest;
}
