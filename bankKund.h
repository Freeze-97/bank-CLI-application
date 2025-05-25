// Tommy Yasi/toya1800
// Created by Admin on 2019-04-11.
// Headerfil för BankKund som hanterar konton för en kund

#ifndef OB_LABB2_BANKKUND_H
#define OB_LABB2_BANKKUND_H

#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>
#include "konto.h"
#include "transactionAccount.h"
#include "longSavingsAccount.h"
class BankKund {
private:
    std::string fullName;
    std::string securityNumber;
    std::vector<std::unique_ptr<Konto>> accounts;
public:
    BankKund(std::string &pFullName, std::string &pSecurityNumber); // Constructor

    // Medlemsfunktioner
    bool addTransactionAccount(std::string &accountNmb, double &balance, double &credit); // Skapa konto
    bool addSavingsAccount(std::string &accountNmb, double &balance);
    bool addLongSavingsAccount(std::string &accountNmb, double &balance);
    bool deleteAccount(std::string &accountNmb);
    bool depositToAccount(std::string &accountNmb, double &amount);
    bool withdrawal(std::string &accountNmb, double &amount);
    bool changeCredit(std::string &accountNumb, double &amount);
    void createCustomer(std::string &pName, std::string &pSecurityNumber); // Skapa kund
    void setInterest(std::string &accountNr, double &interest);

    // File
    void saveToFile();
    bool readFromFile(std::string &pNr);

    // Getfunktioner
    std::string getName() const {return fullName;}
    std::string getSecurityNumber() const {return securityNumber;}
    int getNumOfAcc() const {return accounts.size();}
    bool getAccountNumbs(std::vector<std::string> &vec) const;
    bool getAccountInfo(std::string tmpAccNum, std::vector<double> &vec) const;
    double getTotalAssets() const;
    bool getSummery(std::vector<std::string> &aNr, std::vector<double> &summery) const;
    std::string getAccountType(std::string &accountNr) const;
    int getMaxWithdrawals(std::string &accountNr) const;
    int getNrOfWithdrawals(std::string &accountNr) const;
    bool duplicateAccNr(std::string &accountNr) const; // Kontrollera doubletter

};
#endif //OB_LABB2_BANKKUND_H
