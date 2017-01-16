/**
   Overloaded Functions

   -> same names
   -> different types
   -> may have the same statements // <== better use templates
*/

#include <iostream>
using namespace std;

int    average(int, int);
double average(double, double);

int main ()
{
    int   s1 = 92,  s2 = 87, avg1;
    double x = 88.5, y = 92, avg2;

    avg1 = average(s1, s2);
    avg2 = average(x, y);

    cout << avg1 << endl;
    cout << avg2 << endl;

    return 0;
}

/***********************************/
int average(int a, int b)
{
    return (a + b) / 2;
}

/***********************************/
double average(double a, double b)
{
    return (a + b) / 2;
}
