#pragma once
#include<vector>
#include<memory>
#include <string>

//Bank to właściciel kont zatem używamy shared_ptr<Account>
//Bank to właściciel klientów zatem shared_ptr<Account> 
//Customer ma tylko wear_ptr<Account> bo tylko ,,ogląda'' konto ale nie posiada

class Account;
class Customer;

class Bank{
    private:
        std::vector<std::shared_ptr<Customer>> customers;
        std::vector<std::shared_ptr<Account>> accounts;

    public:
        Bank() = default;

        //Tworzenie obiektów

        std::shared_ptr<Customer> createCustomer(const std::string& imie,
        const std::string& nazwisko, int id);

        std::shared_ptr<Account> creatrAccount(int id, long long initialBalance,
        const std::string& waluta, std::shared_ptr<Customer> owner);

        //Wyszukiwanie

        std::shared_ptr<Account> findAccount(int id);
        std::shared_ptr<Customer> findCustomer(int id);

        //operacje dodatkowe

        void ShowAllCustomers() const;
        void ShowAllAccounts() const;

};