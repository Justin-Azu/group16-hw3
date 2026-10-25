//code for product struct here
#include <iostream>
#include <sstream>
#include <iomanip>
#include "product.h"
using namespace std;

string product::product_info()
{
    ostringstream output;
    output << "Product:\n"
           << "Name: " << name << "\n"
           << "Description: " << description << "\n"
           << "Price: $" << fixed << setprecision(2) << price << "\n";
    return output.str();
}