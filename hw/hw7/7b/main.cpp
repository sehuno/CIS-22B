// Program demonstrating the use of classes CustomerData and PersonData
#include "PersonData.h"
#include "CustomerData.h"
#include <iostream>

int main() {
	CustomerData new_customer;

	new_customer.setFirstName("Eric");
	new_customer.setLastName("Oh");
	new_customer.setAddress("1234 De Anza Boulevard");
	new_customer.setCity("Cupertino");
	new_customer.setState("CA");
	new_customer.setZip(91234);
	new_customer.setPhone(1234567890);
	new_customer.setCustomerNumber(10000);
	new_customer.setMailingListYN(true);

	cout << "Displaying information of customer " << new_customer.getCustomerNumber() 
		 << ", named, " << new_customer.getFirstName() << " " << new_customer.getLastName() << endl;
	cout << "Customer's address is: " << new_customer.getAddress() << " " 
		<< new_customer.getCity() << " " << new_customer.getState() << " " 
		<< new_customer.getZip() << endl;
	cout << "This customer has set mailing list option to " << (new_customer.getMailingListYN() ? "yes." : "no.") << endl;

	return 0;
}

/*
	OUTPUT

Displaying information of customer 10000, named, Eric Oh
Customer's address is: 1234 De Anza Boulevard Cupertino CA 91234
This customer has set mailing list option to yes.

*/