// Specification file for the Customer Data class
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "PersonData.h"

class CustomerData : public PersonData {
	public:
		CustomerData() : PersonData()
			{ customerNumber = 0; mailingList = false; }
		~CustomerData() {};

		// Accessor functions
		int getCustomerNumber() const 
			{ return customerNumber; }

		bool getMailingListYN() const 
			{ return mailingList; }

		// Mutator functions
		void setCustomerNumber(int cn) 
			{ customerNumber = cn; }

		void setMailingListYN(bool ml) 
			{ mailingList = ml; }
	private:
		int customerNumber;
		bool mailingList;
};

#endif