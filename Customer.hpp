#include "Account.hpp"
#include<string>
#include <vector>
#include <memory>
#pragma once


// imie,nazwisko, ID, liczba kont

class Account;

class Customer
{
    private:
        std::string imie;
        std::string nazwisko;
        int id;
        std::vector<std::weak_ptr<Account>> accounts;

    
    public:
        Customer(const std::string imie, 
            const std::string nazwisko, 
            int id) 
            : imie(imie), nazwisko(nazwisko), id(id) {};

        void addAccount(const std::shared_ptr<Account>& acc);
        
};