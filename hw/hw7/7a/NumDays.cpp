#include "NumDays.h"

NumDays NumDays::operator+(const NumDays& right)  
{	
	NumDays nd;
	nd.setHours(this->getHours() + right.getHours());
	return nd;
};

NumDays NumDays::operator-(const NumDays& right)  
{	
	NumDays nd;
	nd.setHours(this->getHours() - right.getHours());
	return nd;
};

NumDays NumDays::operator++()
{ 
	++hours; 
	return *this;
};

NumDays NumDays::operator--()
{ 
	--hours; 
	return *this; 
};

NumDays NumDays::operator ++ (int) 
{
	NumDays temp(hours);
	hours++;
	return temp;
}


NumDays NumDays::operator -- (int)
{
	NumDays temp(hours);
	hours--;
	return temp;
}