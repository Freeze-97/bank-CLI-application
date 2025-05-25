// Tommy Yasi/toya1800
// Created by Admin on 2019-04-22.
// Definitionsfil för klassen Bank

#include "bank.h"
using namespace std;

bool Bank::deposit(string &accNum, double &ammount) {
    return customer->depositToAccount(accNum, ammount);
}

bool Bank::addTransactionAccount(std::string &accountNmb, double &balance, double &credit) {
    return customer->addTransactionAccount(accountNmb, balance, credit);
}

bool Bank::addSavingsAccount(std::string &accountNmb, double &balance) {
    return customer->addSavingsAccount(accountNmb, balance);
}

bool Bank::addLongSavingsAccount(std::string &accountNmb, double &balance) {
    return customer->addLongSavingsAccount(accountNmb, balance);
}

bool Bank::deleteAcc(string &accountNmb) {
    return customer->deleteAccount(accountNmb);
}

bool Bank::withdraw(string &accountNmb, double &amount) {
    return customer->withdrawal(accountNmb, amount);
}

bool Bank::changeCred(string &accountNmb, double &amount) {
    return customer->changeCredit(accountNmb, amount);
}

void Bank::saveFile() {
    customer->saveToFile();
}

bool Bank::readFile(string &pNr) {
    return customer->readFromFile(pNr);
}

bool Bank::getAccountNums(vector<std::string> &vec) const {
    return customer->getAccountNumbs(vec);
}

bool Bank::getAccountInfo(string tmpAccNum, vector<double> &vec) const {
    return customer->getAccountInfo(move(tmpAccNum), vec);
}

double Bank::getTotalAssets() const {
    return customer->getTotalAssets();
}

bool Bank::getSummery(vector<string> &aNr, vector<double> &summery) const {
    return customer->getSummery(aNr, summery);
}

void Bank::createCustomer(string &pName, string &pSecurityNumber) {
    customer.reset(new BankKund(pName, pSecurityNumber));
    customer->createCustomer(pName, pSecurityNumber);
}

std::string Bank::getAccountType(string &accountNr) const {
    return customer->getAccountType(accountNr);
}

int Bank::getMaxWithdrawals(string &accountNr) const {
    return customer->getMaxWithdrawals(accountNr);
}

int Bank::getNrOfWithdrawals(string &accountNr) const {
    return customer->getNrOfWithdrawals(accountNr);
}

bool Bank::duplicateAccNr(string &accountNr) const {
    return customer->duplicateAccNr(accountNr);
}

void Bank::setInterest(string &accountNr, double &interest) {
    customer->setInterest(accountNr, interest);
}
