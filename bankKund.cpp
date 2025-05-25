// Tommy Yasi/toya1800
// Created by Admin on 2019-04-11.
// Definitionsfil för klassen BankKund
#include "bankKund.h"
using namespace std;

BankKund::BankKund(string &pFullName, string &pSecurityNumber) {
    fullName = pFullName;
    securityNumber = pSecurityNumber;
}

void BankKund::createCustomer(string &pName, string &pSecurityNumber) {
    fullName = pName;
    securityNumber = pSecurityNumber;
}

bool BankKund::addTransactionAccount(string &accountNmb, double &balance, double &credit) {
    if(accounts.size() < 3) {
        unique_ptr<Konto> newAccount{new TransactionAccount{accountNmb, balance, credit}};
        accounts.emplace_back(move(newAccount));
        return true;
    }
    else
        return false;
}

bool BankKund::addSavingsAccount(std::string &accountNmb, double &balance) {
    if(accounts.size() < 3) {
        unique_ptr<Konto> newAccount{new SavingsAccount{accountNmb, balance}};
        accounts.emplace_back(move(newAccount));
        return true;
    }
    else
        return false;
}

bool BankKund::addLongSavingsAccount(std::string &accountNmb, double &balance) {
    if(accounts.size() < 3) {
        unique_ptr<Konto> newAccount{new LongSavingsAccount{accountNmb, balance}};
        accounts.emplace_back(move(newAccount));
        return true;
    }
    else
        return false;
}

bool BankKund::getAccountNumbs(vector<string> &vec) const {
    if(accounts.empty()) {
        return false;
    }
    for (const auto& account: accounts) {
        vec.push_back(account->getAccountNum());
    }
    return true;
}
bool BankKund::getAccountInfo(string tmpAccNum, vector<double> &vec) const {
    for (const auto& account: accounts) {
        if(tmpAccNum == account->getAccountNum() && account->getAccountType() == "TransactionAccount") {
            vec.push_back(account->getBalance());
            vec.push_back(account->getDisBalance());
            vec.push_back(account->getCredit());
        }
        else if(tmpAccNum == account->getAccountNum()) {
            vec.push_back(account->getBalance());
            vec.push_back(account->getDisBalance());
            vec.push_back(account->getInterest());
        }
    }
    return !vec.empty();
}
double BankKund::getTotalAssets() const {
    double tmpTotalAmount = 0;
    for (const auto& account: accounts){
        tmpTotalAmount += account->getBalance();
        tmpTotalAmount += account->getCredit();
    }
    return tmpTotalAmount;
}
bool BankKund::deleteAccount(string &accountNmb) {
    auto result = find_if(accounts.begin(), accounts.end(),
            [accountNmb] (unique_ptr<Konto> &acc) {return acc->getAccountNum() == accountNmb;});
    if(result != accounts.end()) {
        accounts.erase(result);
        return true;
    }
    return false;
}
bool BankKund::depositToAccount(string &accountNmb, double &amount) {
    for (const auto& account: accounts) {
        if (accountNmb == account->getAccountNum()) {
            account ->deposit(amount);
          return true;
        }
    }
    return false;
}
bool BankKund::withdrawal(string &accountNmb, double &amount) {
    for (const auto& account: accounts) {
        if(accountNmb == account->getAccountNum()) {
            return account->withdraw(amount);
        }
    }
    return false;
}
bool BankKund::changeCredit(string &accountNmb, double &amount) {
    for (const auto& account: accounts) {
        if(accountNmb == account->getAccountNum()) {
            account->changeCredit(amount);
            return true;
        }
    }
    return false;
}
void BankKund::saveToFile() {
    ofstream outFile(securityNumber + ".knt");
    outFile << fullName << endl
    << securityNumber << endl;

    for(auto &idx : accounts){
        outFile << idx->getAccountNum() << endl
        << idx->getBalance() << endl
        << idx->getCredit() << endl;
    }
    outFile.close();
}
bool BankKund::readFromFile(string &pNr) {
    string tmpANr;
    int tmpBalance, tmpCredit;

    ifstream inFile(pNr + ".knt");
    if(inFile.is_open()){
        getline(inFile, fullName);
        getline(inFile, securityNumber);

        while(getline(inFile, tmpANr)){
            inFile >> tmpBalance;
            inFile >> tmpCredit;
            inFile.get();

            accounts.push_back(unique_ptr<Konto>(new TransactionAccount(tmpANr, tmpBalance, tmpCredit)));
        }
        inFile.close();
        return true;
    }
    else
        return false;
}

bool BankKund::getSummery(vector<string> &aNr, vector<double> &summery) const {
    if (accounts.empty()) {
        return false;
    }
    for (const auto& account: accounts) {
        aNr.push_back(account->getAccountNum());
    }

    double tmpBalance = 0, tmpCredit = 0, tmpDisBalance = 0;
    for (const auto& account: accounts) {
        tmpBalance += account->getBalance();
        tmpCredit += account->getCredit();
        tmpDisBalance += account->getDisBalance();
    }
    summery.push_back(tmpBalance);
    summery.push_back(tmpCredit);
    summery.push_back(tmpDisBalance);
    return true;
}
string BankKund::getAccountType(string &accountNr) const {
    for (const auto& account: accounts) {
        if (accountNr == account->getAccountNum()) {
            return account->getAccountType();
        }
    }
    return nullptr;
}

int BankKund::getMaxWithdrawals(string &accountNr) const {
    int maxWithdrawals = 0;
    for (const auto& account: accounts) {
        if (accountNr == account->getAccountNum()) {
            maxWithdrawals = account->getMaxWithdrawal();
        }
    }
    return maxWithdrawals;
}

int BankKund::getNrOfWithdrawals(string &accountNr) const {
    int nrOfWithdrawals = 0;
    for (const auto& account: accounts) {
        if (accountNr == account->getAccountNum()) {
            nrOfWithdrawals = account->getNrOfWithdrawals();
        }
    }
    return nrOfWithdrawals;
}

bool BankKund::duplicateAccNr(string &accountNr) const {
    for (const auto& account: accounts) {
        if (accountNr == account->getAccountNum()){
            return true;
        }
    }
    return false;
}

void BankKund::setInterest(string &accountNr, double &interest) {
    for (const auto& account: accounts) {
        if (accountNr == account->getAccountNum()){
            account->setInterest(interest);
        }
    }
}


