//implementation code for address struct here
#include <iostream>
#include "address.h"


string address::address_info(){
  return "Address:\n" + address_line1 + "\n" + address_line2 + "\n" + 
  city + "\n" + state + "\n" + zip + "\n";
}