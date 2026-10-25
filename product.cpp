//code for product struct here
#include <iostream>
#include "product.h"
using std::string;

string product::product_info(){
    return string("Product:\n name: ") + name + "\n" + "Description: " + description +
    "Price: " + "\n" + std::to_string(price);
}