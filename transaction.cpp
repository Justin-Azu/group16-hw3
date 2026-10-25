//code for transaction struct here
#include <iostream>
#include "transaction.h"
using std::string;

string transaction::transaction_info()
{
    return string("Transaction Details:\n") +
           "Transaction #: " + std::to_string(transaction_number) + "\n" +
           customer.person_info() +
           purchased_item.product_info() +
           "Quantity: " + std::to_string(quantity) + "\n";
}