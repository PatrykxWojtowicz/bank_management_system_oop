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
        int CustomerId;
        std::vector<std::weak_ptr<Account>> accounts;

    
    public:
        Customer(const std::string imie, 
            const std::string nazwisko, 
            int id);
           

        void addAccount(const std::shared_ptr<Account>& acc);
        int getId() const;
        std::string getImie() const;
        std::string getNazwisko() const;
        
};