//implementation code for credit_card struct here
#include <iostream>
#include <string>
#include "credit_card.h"

using namespace std;

bool credit_card::make_purchase(double purchase_amount)
{
    if (purchase_amount <= 0)
    {
        return false;
    }

    if (current_balance + purchase_amount <= limit)
    {
        current_balance += purchase_amount;
        return true;
    }

    return false;
}

// Makes a payment if the payment amount is valid
bool credit_card::make_payment(double payment_amount)
{
    if (payment_amount <= 0 || payment_amount > current_balance)
    {
        return false;
    }

    current_balance -= payment_amount;
    return true;
}

// Returns credit card information as a string
string credit_card::credit_card_info()
{
    return "Credit Card Number: " + to_string(cc_number) +
           "\nCredit Limit: " + to_string(limit) +
           "\nCurrent Balance: " + to_string(current_balance) + "\n";
}