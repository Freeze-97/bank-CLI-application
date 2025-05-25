// Tommy Yasi/toya1800
// Created by Admin on 2019-04-10.
// Definitionsfil för klassen Konto
#include "konto.h"
using namespace std;

Konto::Konto(string pAccountName, double pBalance) {
    accountNum = move(pAccountName);
    balance = pBalance;
}
bool Konto::withdraw(double &amount) {
    balance -= amount;
    return true;
}

