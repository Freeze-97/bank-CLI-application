// Tommy Yasi/toya1800
// Created by Admin on 2019-05-22.
// Headerfil för klassen LongSavingsAccount

#ifndef OB_LABB2_LONGSAVINGSACCOUNT_H
#define OB_LABB2_LONGSAVINGSACCOUNT_H

#include "savingsAccount.h"

class LongSavingsAccount : public SavingsAccount {
private:
    int withdrawals = 0; // Antal uttag som har gjorts
    int maxWithdrawals = 1; // Max antal uttag
    double interestRate = interest+2; // 2% högre ränta
public:
    // Constructor
    LongSavingsAccount(std::string accountNr, double balance) : SavingsAccount(std::move(accountNr), balance){};
    ~LongSavingsAccount() override = default;

    // Olika funktioner
    bool withdraw(double &amount) override;
    void setInterest(double inter) override;

    // Getfunktioner
    std::string getAccountType() const override;
    double getDisBalance() const override;
    int getMaxWithdrawal() const override;
    int getNrOfWithdrawals() const override;
    double getInterest() const override;

    // Testers
    bool hasCredit() const override {return false;}
    bool hasInterest() const override {return true;}
    bool hasMaxWithdrawals() const override {return true;}
};

#endif //OB_LABB2_LONGSAVINGSACCOUNT_H
