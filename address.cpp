//implementation code for address struct here
#include <string>
#include "address.h"
using namespace std;

string address::address_info()
{
    string result = address_line1 + "\n";

    if (!address_line2.empty())
        result += address_line2 + "\n";

    result += city + "\n" + state + "\n" + zip + "\n";

    return result;
}