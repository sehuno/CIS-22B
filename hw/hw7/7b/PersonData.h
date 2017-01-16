// Specification file for the PersonData class
#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>

using namespace std;

class PersonData {

public:
	PersonData() {
		lastName = "";
		firstName = "";
		address = ""; 
		city = "";
		state = "";
		zip = 0;
		phone = 0;
	};

	virtual ~PersonData() {};

	// Accessor functions
	string getFirstName() const 
		{ return firstName; }

	string getLastName() const 
		{ return lastName; }

	string getAddress() const 
		{ return address; }

	string getCity() const 
		{ return city; }

	string getState() const 
		{ return state; }

	int getZip() const
		{ return zip; }

	int getPhone() const
		{ return phone; }

	// Mutator functions
	void setFirstName(string fName) 
		{ firstName = fName; }

	void setLastName(string lName) 
		{ lastName = lName; }

	void setAddress(string add) 
		{ address = add; }

	void setCity(string c) 
		{ city = c; }

	void setState(string s) 
		{ state = s; }

	void setZip(int z)
		{ zip = z; }

	void setPhone(int pn)
		{ phone = pn; }

	protected:
		string lastName;
		string firstName;
		string address;
		string city;
		string state;
		int zip;
		int phone;	
};

#endif