#pragma once
#include <string>
#include <vector>
#include "Transaction.hpp"

//Account id, balance, waluta, logi

class Transaction;

class Account{

    public:
        Account(int id, long long initialBalance, 
            const std::string& waluta); 
            

        int getId() const;
        long long getBalance() const;
        const std::string& getCurrency() const;

        void depozyt(long long amount);
        bool wyplata(long long amount);
        bool transferTo(Account& other, long long amount);





    private:
        int AccountId;
        long long Balance;
        std::vector<Transaction> logs;
        std::string waluta;



};