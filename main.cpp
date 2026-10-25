#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;

int main()
{

	//import from text files
	ifstream customer_file("people.txt");
    int customer_count;
	Store store1;
    customer_file >> customer_count;
    customer_file.ignore(1000, '\n');
	//add to store and other variables
  
	for (int i = 0; i < customer_count && i < 100; i++)
    {
        string name, phone;
        address customer_address;
        credit_card card;

        getline(customer_file, name);
        getline(customer_file, phone);
        getline(customer_file, customer_address.address_line1);
        getline(customer_file, customer_address.address_line2);
        getline(customer_file, customer_address.city);
        getline(customer_file, customer_address.state);
        getline(customer_file, customer_address.zip);

        card.cc_number = 10000000 + rand() % 90000000;
        card.limit = 5000.00;
        card.current_balance = 0.00;

        Person customer(name, phone, customer_address, card);
        store1.add_customer(customer);
    }

    customer_file.close();

    ifstream product_file("products.txt");

    if (!product_file)
    {
        cout << "Error opening products.txt" << endl;
        return 1;
    }

    int product_count;
    product_file >> product_count;
    product_file.ignore(10000, '\n');

    for (int i = 0; i < product_count && i < 100; i++)
    {
        product item;

        getline(product_file, item.name);
        getline(product_file, item.description);
        product_file >> item.price;
        product_file.ignore(10000, '\n');

        store1.add_product(item);
    }

    product_file.close();
	
	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions
int transaction_count = 11 + rand() % 89;

    cout << "Attempting " << transaction_count << " transactions." << endl;

    for (int i = 0; i < transaction_count; i++)
    {
        if (store1.num_customers() == 0 ||
            store1.num_products() == 0 ||
            store1.num_transactions() >= 100)
        {
            break;
        }

        int customer_index = rand() % store1.num_customers();
        int product_index = rand() % store1.num_products();
        int quantity = 1 + rand() % 3;

        Person customer = store1.get_customer(customer_index);
        product item = store1.get_product(product_index);

        cout << "Attempting purchase: " << customer.name()
             << " purchasing " << quantity << " x "
             << item.name << endl;

        if (store1.make_purchase(customer, item, quantity))
        {
            cout << "Purchase successful!" << endl;
            cout << store1.get_transaction(
                store1.num_transactions() - 1
            ).transaction_info() << endl;
        }
        else
        {
            cout << "Purchase failed. Insufficient credit or invalid purchase."
                 << endl;
        }
    }
	//print store info at the end
	cout << "Store info: " << endl << endl;
	cout << store1.store_info() << endl << endl;
	return 0;
}
