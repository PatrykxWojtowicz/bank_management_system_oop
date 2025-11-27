#include "Customer.hpp"

Customer::Customer(const std::string imie, 
            const std::string nazwisko, 
            int id) 
            : imie(imie), nazwisko(nazwisko), CustomerId(id) {};

void Customer::addAccount(const std::shared_ptr<Account> &acc)
{
    accounts.push_back(acc);
}

int Customer::getId() const
{
    return CustomerId;
}

std::string Customer::getImie() const
{
    return imie;
}

std::string Customer::getNazwisko() const
{
    return nazwisko;
}
