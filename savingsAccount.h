// Tommy Yasi/toya1800
// Created by Admin on 2019-05-22.
// Header för SavingsAccount bindat till klassen Konto

#ifndef OB_LABB2_SAVINGSACCOUNT_H
#define OB_LABB2_SAVINGSACCOUNT_H

#include <utility>
#include "konto.h"

class SavingsAccount : public Konto {
private:
    int withdrawals = 0; // Antal uttag som har gjorts
    int maxWithdrawals = 4; // Max antal uttag
protected:
    double interest = 2; // Ränta på 2%
public:
    // Constructors
    SavingsAccount(std::string accountNr, double balance) : Konto(std::move(accountNr), balance) {};
    ~SavingsAccount() override;

    // Olika funktioner för kontot
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

#endif //OB_LABB2_SAVINGSACCOUNT_H
