#include "Transaction.hpp"

Transaction::Transaction(const std::string &type, long long amount,const std::string& data, int otherAccId) 
    : type(type), amount(amount), data(data), otherAccId(otherAccId)
{
}