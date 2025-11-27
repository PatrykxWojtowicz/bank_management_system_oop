#include "Account.hpp"
#include "Transaction.hpp"
#include <iostream>

Account::Account(int id, long long InitialBalance, const std::string &waluta) :
    AccountId(id), Balance(InitialBalance), waluta(waluta){}


int Account::getId() const
{
    return AccountId;
}

long long Account::getBalance() const
{
    return Balance;
}

const std::string &Account::getCurrency() const
{
    return waluta;
}

void Account::depozyt(long long amount)
{
    if(amount <=  0) return;
    Balance += amount;
}

bool Account::wyplata(long long amount)
{
    if(amount <= 0)
    {
        std::cout << "Kwota musi byc dodatnia. " <<std::endl;
        return false;
    }
    else if(amount > Balance)
    {
        std::cout << "Brak wystarczajacych srodkow na koncie. " <<std::endl;
        return false;
    }

    Balance -= amount;
    return true;
}

bool Account::transferTo(Account& other, long long amount)
{
    if (amount <= 0)
    {
        std::cout << "Kwota musi byc dodatnia." << std::endl;
        return false;
    }

    if (waluta != other.waluta)
    {
        std::cout << "Nie mozna wykonac przelewu miedzy roznymi walutami." << std::endl;
        return false;
    }

    if (!wyplata(amount))
    {
        // wypłata sama wypisze komunikat
        return false;
    }

    other.depozyt(amount);

//Tworzymy nowy obiekt na koncu vector logs 
    logs.emplace_back("transfer_out", amount, "2024-01-01", other.getId());
    other.logs.emplace_back("transfer_in", amount, "2024-01-01", this->getId());

    return true;
}
