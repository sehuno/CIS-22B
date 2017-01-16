#include <iostream>
#include "NumDays.h"
#include "NumDays.cpp"

int main() {

	NumDays nd1(30);
	cout << "NumDays nd1, was initialized to have " << nd1.getHours() << " hours." << endl;
	cout << "This translates to ";
	nd1.getPrettyDays();
	cout << "which is approximately " << nd1.getDays() << " days." << endl << endl;

	NumDays nd2(12);
	cout << "NumDays nd2, was initialized to have " << nd2.getHours() << " hours." << endl << endl;

	cout << "The difference between the two hours are " << (nd1-nd2).getHours() << " hours." << endl << endl;

	NumDays nd3;
	nd3 = nd1 + nd2;
	cout << "NumDays nd3 was the result of adding nd1 and nd2, and its hours are " << nd3.getHours() << endl;
	cout << "This translates to ";
	nd3.getPrettyDays();
	cout << "which is approximately " << nd3.getDays() << " days." << endl << endl;

	NumDays nd4;
	nd4 = nd3++;
	cout << "NumDays nd4 was set equal to the postfix incremented value of nd3. (nd4 = nd3++)" << endl;
	cout << "nd4's hour value is: " << nd4.getHours() << endl;
	cout << "nd3's hour value is: " << nd3.getHours() << endl;
	cout << "This is correct because nd4 will be set to nd3's value first and then nd3 will be incremented." << endl << endl;

	nd4 = ++nd3;
	cout << "NumDays nd4 was set equal to the prefix incremented value of nd3. (nd4 = ++nd3;)" << endl;
	cout << "nd4's hour value is: " << nd4.getHours() << endl;
	cout << "nd3's hour value is: " << nd3.getHours() << endl;
	cout << "This is correct because nd4 will be set to nd3's value after it is incremented." << endl << endl;

	nd4 = nd3--;
	cout << "NumDays nd4 was set equal to the postfix decremented value of nd3. (nd4 = nd3--)" << endl;
	cout << "nd4's hour value is: " << nd4.getHours() << endl;
	cout << "nd3's hour value is: " << nd3.getHours() << endl;
	cout << "This is correct because nd4 will be set to nd3's value first and then nd3 will be decremented." << endl << endl;

	nd4 = --nd3;
	cout << "NumDays nd4 was set equal to the prefix decremented value of nd3. (nd4 = --nd3)" << endl;
	cout << "nd4's hour value is: " << nd4.getHours() << endl;
	cout << "nd3's hour value is: " << nd3.getHours() << endl;
	cout << "This is correct because nd4 will be set to nd3's value after it is decremented." << endl << endl;

}

/*
	OUTPUT

NumDays nd1, was initialized to have 30 hours.
This translates to 1 day(s) and 6 hour(s), which is approximately 1.25 days.

NumDays nd2, was initialized to have 12 hours.

The difference between the two hours are 18 hours.

NumDays nd3 was the result of adding nd1 and nd2, and its hours are 42
This translates to 1 day(s) and 18 hour(s), which is approximately 1.75 days.

NumDays nd4 was set equal to the postfix incremented value of nd3. (nd4 = nd3++)
nd4's hour value is: 42
nd3's hour value is: 43
This is correct because nd4 will be set to nd3's value first and then nd3 will be incremented.

NumDays nd4 was set equal to the prefix incremented value of nd3. (nd4 = ++nd3;)
nd4's hour value is: 44
nd3's hour value is: 44
This is correct because nd4 will be set to nd3's value after it is incremented.

NumDays nd4 was set equal to the postfix decremented value of nd3. (nd4 = nd3--)
nd4's hour value is: 44
nd3's hour value is: 43
This is correct because nd4 will be set to nd3's value first and then nd3 will be decremented.

NumDays nd4 was set equal to the prefix decremented value of nd3. (nd4 = --nd3)
nd4's hour value is: 42
nd3's hour value is: 42
This is correct because nd4 will be set to nd3's value after it is decremented.


*/
