// Header file for NumDays class
#ifndef NUMDAYS_H
#define NUMDAYS_H

using namespace std;

class NumDays {
	public:
		NumDays() {hours = 0;};
		NumDays(int h) { hours = h; };
		~NumDays() {};

		// Overloaded operators
		NumDays operator+(const NumDays& right);
		NumDays operator-(const NumDays& right);
		NumDays operator ++ ();
		NumDays operator -- (); 
		NumDays operator ++ (int);
		NumDays operator -- (int); 

		// Setter functions 
		void setHours(int new_hours) 
			{ hours = new_hours; };
		void setDays(double new_days) 
			{ hours = new_days*24; };

		// Getter functions
		int getHours() const 
			{ return hours; };
		double getDays() const 
			{ return (double) hours/24.0; };
		void getPrettyDays() 
			{ cout << (int) hours / 24 << " day(s) and " <<  hours % 24 << " hour(s), ";};

	protected:
		int hours;
};

#endif