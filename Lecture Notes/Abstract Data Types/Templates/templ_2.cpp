/**
    Function templates are special functions that can operate with generic types.
                                                            // Template == Mold
    Advantage: avoid repeating the entire code for each type.
*/

#include <iostream>
using namespace std;

///template <class T> T average( T, T);
template <class T>
T average( T, T);

int main ()
{
    int   s1 = 95,  s2 = 87, avg1;
    double x = 88.5, y = 92, avg2, avg3;

    avg1 = average<int>(s1, s2);   /** Here T is int     */
    avg2 = average<double>(x, y);  /** Here T is double  */
    avg3 = average<double>(s1, y); /** Here T is double  */

    cout << avg1 << endl;
    cout << avg2 << endl;
    cout << avg3 << endl;

    /** The actual types: <int>, <double> could be left out
        It is recommended to keep them */
    avg1 = average(s1, s2);         /** default type is int    */
    avg2 = average(x, y);           /** default type is double */
    //avg3 = average(s1, y);        /** AMBIGUOUS  */

    cout << avg1 << endl;
    cout << avg2 << endl;

    return 0;
}

/// ***************************************
template <class T>
T average(T num1, T num2)
{
    return (num1 + num2) / 2;
}



/**
// Any identifier could be used, such as SomeType, but T is preferred

template <class SomeType>
SomeType average( SomeType, SomeType);

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

/// ***************************************
template <class SomeType>
SomeType average(SomeType num1, SomeType num2)
{
    return (num1 + num2) / 2;
}

*/
