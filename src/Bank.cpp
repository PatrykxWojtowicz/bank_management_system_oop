#include "Bank.hpp"
#include "Account.hpp"
#include "Customer.hpp"
#include <iostream>


std::shared_ptr<Customer> Bank::createCustomer(const std::string &imie, const std::string &nazwisko, int id)
{
    auto customer = std::make_shared<Customer>(imie, nazwisko, id);
    customers.push_back(customer);
    return customer;
}

std::shared_ptr<Account> Bank::createAccount(int id, long long initialBalance, const std::string &waluta, std::shared_ptr<Customer> owner)
{
    //Tworzenie konnnta
    auto account = std::make_shared<Account>(id, initialBalance, waluta);
    //Dodanie konta do HEAP, bank przechowuje konto
    accounts.push_back(account);
    //Customer zapamietuje konto jako weak_ptr
    owner->addAccount(account);

    return account;
}

std::shared_ptr<Account> Bank::findAccount(int id)
{
    //Pętla for do sprawdzenia czy konto istnieje poprzez sprawdzenie ID
    for(auto& acc : accounts)
    {
        if(acc->getId() == id)
        {
            return acc;
        }
        return nullptr;
    }
}
//Pętla for do sprawdzenia czy klient istnieje poprzez sprawdzenie ID
std::shared_ptr<Customer> Bank::findCustomer(int id)
{
    for(auto& cus : customers)
    {
        if(cus->getId() == id)
        {
            return cus;
        }
        return nullptr;
    }
}

//Wypisujemy wszystkie konta i klientow za pomoca metody
void Bank::ShowAllCustomers() const
{
    std::cout << "=== Lista klientow ===\n";
    for(const auto& cus : customers)
    {
        std::cout << "- " << cus->getImie() << " " << cus->getNazwisko() << " (ID: " << cus->getId() << ")\n";
    }
}

void Bank::ShowAllAccounts() const
{
    std::cout <<"=== Lista kont klientow ===\n";
    for(const auto& acc : accounts)
    {
        std::cout << "- Konto #" << acc->getId()
                  << " | saldo: " << acc->getBalance()
                  << " | waluta: " << acc->getCurrency() << "\n";
    }
}
