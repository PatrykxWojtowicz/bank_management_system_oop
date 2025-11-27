#pragma once
#include <string>

class Transaction{
    public:
        std::string type; //depo, wyplata, transfer
        long long amount;
        std::string data;
        int otherAccId; //do transferow, jesli -1 to nie dotyczy

        Transaction(const std::string& type, long long amount,
        std::string& data, int otherAccId = -1);

};