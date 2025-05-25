// Tommy Yasi/toya1800
// Created by Admin on 2019-04-09.
// Klass som hanterar uppgofter för ett bankkonto

#ifndef OB_LABB2_KONTO_H
#define OB_LABB2_KONTO_H

#include <string>

class Konto {
private:
    std::string accountNum;
    double balance; // Saldo
public:
    Konto(std::string pAccountNum, double pBalance);
    virtual ~Konto() = default;

    void deposit(double &amount) {balance += amount;} // Sätt in pengar
    virtual bool withdraw(double &amount); // Ta ut pengar
    virtual void changeCredit(double &amount) {}; // Ändra beviljad kredit
    virtual void setInterest(double inter) {}; // Ränta

    // Getfunktioner
    std::string getAccountNum() const {return accountNum;}
    virtual std::string getAccountType() const = 0;
    double getBalance() const {return balance;}
    virtual double getCredit() const {return 0;}
    virtual double getDisBalance() const {return balance;}
    virtual int getMaxWithdrawal() const {return 0;}
    virtual int getNrOfWithdrawals() const {return 0;}
    virtual double getInterest() const {return 0;};

    // Testers
    virtual bool hasCredit() const {return false;}
    virtual bool hasInterest() const {return false;}
    virtual bool hasMaxWithdrawals() const {return false;}

};

#endif //OB_LABB2_KONTO_H
