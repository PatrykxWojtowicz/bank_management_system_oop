#include "Customer.hpp"

void Customer::addAccount(const std::shared_ptr<Account> &acc)
{
    accounts.push_back(acc);
}