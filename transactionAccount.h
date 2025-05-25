// Tommy Yasi/toya1800
// Created by Admin on 2019-05-20.
// Transaktionskonto
// Bindat till klassen Konto

#ifndef OB_LABB2_TRANSACTIONACCOUNT_H
#define OB_LABB2_TRANSACTIONACCOUNT_H

#include <utility>
#include "konto.h"

class TransactionAccount : public Konto {
private:
    int withdrawals = 0; // Antal uttag som har gjorts
    double credit = 0;
public:
    // Constructors
    TransactionAccount(std::string accountNr, double balance, double credit) :
    Konto(std::move(accountNr), balance), credit(credit) {}; // Constructor
    ~TransactionAccount() override;

    // Olika funktioner för kontot
    bool withdraw(double &amount) override;
    void changeCredit(double &amount) override;

    // Getfunktioner
    std::string getAccountType() const override;
    double getCredit() const override;
    double getDisBalance() const override;
    int getNrOfWithdrawals() const override;

    // Testers
    bool hasCredit() const override {return true;}
    bool hasInterest() const override {return false;}
    bool hasMaxWithdrawals() const override {return false;}
};

#endif //OB_LABB2_TRANSACTIONACCOUNT_H
