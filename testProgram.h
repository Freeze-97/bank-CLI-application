// Tommy/Yasi
// Created by Admin on 2019-05-02.
// Testprogram

#ifndef OB_LABB2_TESTPROGRAM_H
#define OB_LABB2_TESTPROGRAM_H

#include "iostream"
#include "bank.h"
class TestProgram {
private:
    Bank bank; // Bank objekt

    // Funktioner
    void printPreMenu();
    void printMenu();
    bool loadCustomerFromFile();
    void createNewCostumer();
    void customerName();
    void customerSecurityNum();
    void numOfAccs();
    void printAccNums();
    void printTotalAssets();
    void printAccountInfo();
    void withdraw();
    void deposit();
    void setCredit();
    void summary();
    void createNewAccountMenu();
    void deleteAcc();
    void menuChoice();
    void createTransactionAccount();
    void createSavingsAccount();
    void createLongSavingsAccount();
    void setInterest();
    void saveToFile();
public:
    void run();

};

#endif //OB_LABB2_TESTPROGRAM_H
