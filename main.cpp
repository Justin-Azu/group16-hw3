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
srand(time(0));
	//import from text files
	ifstream customer_file("people.txt");

	if (!customer_file)
	{
		cout << "Error opening people.txt" << endl;
		return 1;
	}

	int customer_count;
	Store store1;
	Person customers[100];

	customer_file >> customer_count;
	customer_file.ignore(10000, '\n');

	//add to store and other variables

	if (customer_count > 100)
		customer_count = 100;

	for (int i = 0; i < customer_count; i++)
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

		Person customer(name, phone, customer_address, card);
		customers[i] = customer;
		store1.add_customer(customer);
	}

	customer_file.close();

	ifstream card_file("credit_card.txt");

	if (!card_file)
	{
		cout << "Error opening credit_card.txt" << endl;
		return 1;
	}

	int card_count;
	card_file >> card_count;
	card_file.ignore(10000, '\n');

	for (int i = 0; i < card_count; i++)
	{
		string card_name;
		credit_card card;

		getline(card_file, card_name);
		card_file >> card.cc_number;
		card_file >> card.limit;
		card_file >> card.current_balance;
		card_file.ignore(10000, '\n');

		for (int j = 0; j < customer_count; j++)
		{
			if (customers[j].name() == card_name)
			{
				customers[j].person_credit_card(card);
				store1.update_customer(j, customers[j]);
				break;
			}
		}
	}

	card_file.close();

	ifstream product_file("products.txt");

	if (!product_file)
	{
		cout << "Error opening products.txt" << endl;
		return 1;
	}

	int product_count;
	product_file >> product_count;
	product_file.ignore(10000, '\n');

	if (product_count > 100)
		product_count = 100;

	for (int i = 0; i < product_count; i++)
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

		int customer_index = rand() % customer_count;
		int product_index = rand() % store1.num_products();
		int quantity = 1 + rand() % 3;

		Person customer = customers[customer_index];
		product item = store1.get_product(product_index);

		cout << "Attempting purchase: " << customer.name()
			<< " purchasing " << quantity << " x "
			<< item.name << endl;

		if (store1.make_purchase(customer, item, quantity))
		{
			cout << "Purchase successful!" << endl;
			cout << store1.transaction_info() << endl;
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