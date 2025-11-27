#include<iostream>
#include "Account.hpp"
#include "Bank.hpp"
#include "Customer.hpp"


int main()
{
    Bank bank;

    //Klienci
    auto janek = bank.createCustomer("Jan", "Kowalski", 1);
    auto ala = bank.createCustomer("Ala", "Nowak", 2);
    //Ich konta
    auto kontojanek = bank.createAccount(1001, 5000, "PLN", janek);
    auto kontoala = bank.createAccount(2001,6500, "PLN", ala);

    // 3. Wyświetlamy listy
    std::cout << "\n=== Klienci ===\n";
    bank.ShowAllCustomers();

    std::cout << "\n=== Konta ===\n";
    bank.ShowAllAccounts();

    // 4. Operacje
    std::cout << "\nJan robi depozyt 2000...\n";
    kontojanek->depozyt(2000);

    std::cout << "Ala robi wyplate 1000...\n";
    kontoala->wyplata(1000);

    std::cout << "\n=== Konta po operacjach ===\n";
    bank.ShowAllAccounts();

    // 5. Przelew
    std::cout << "\nJan przelewa 1500 do Ali...\n";
    if (kontojanek->transferTo(*kontoala, 1500))
        std::cout << "Przelew udany.\n";
    else
        std::cout << "Przelew nie udany.\n";

    // 6. Wynik końcowy
    std::cout << "\n=== Salda po przelewie ===\n";
    bank.ShowAllAccounts();

    return 0;

}