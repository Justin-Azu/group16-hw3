//implementation code for credit_card struct here
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "credit_card.h"
using namespace std;

bool credit_card::make_purchase(double purchase_amount)
{
    if (purchase_amount <= 0)
        return false;

    if (current_balance + purchase_amount <= limit)
    {
        current_balance += purchase_amount;
        return true;
    }

    return false;
}

bool credit_card::make_payment(double payment_amount)
{
    if (payment_amount <= 0 || payment_amount > current_balance)
        return false;

    current_balance -= payment_amount;
    return true;
}

string credit_card::credit_card_info()
{
    ostringstream output;

    output << "Credit card number: " << cc_number << "\n"
           << "Credit Card Limit: $" << fixed << setprecision(2) << limit << "\n"
           << "Current Balance: $" << fixed << setprecision(2)
           << current_balance << "\n";

    return output.str();
}