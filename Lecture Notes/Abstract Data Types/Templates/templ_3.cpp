/**
   Multiple Template Parameters

*/

#include <iostream>
using namespace std;

template <class T, class U>
U average( T, U);

int main ()
{
    int   x = 95;
    double y = 92.5, avg;

    avg = average<int, double>(x, y);   /** T is int, U is double */

    cout << avg << endl;

    return 0;
}

/// ***************************************
template <class T, class U>
U average(T num1, U num2)
{
    return (num1 + num2) / 2;
}
