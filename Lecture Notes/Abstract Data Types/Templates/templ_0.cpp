/**
   Overloaded Functions

   -> same names
   -> different types
*/

#include <iostream>
using namespace std;

int    process(int, int);
double process(double, int);

int main ()
{
    int score1 = 92, score2 = 87, max_score;
    double midAvg = 88.5, avg;

    max_score = process(score1, score2);
    avg = process(midAvg, score2);

    cout << max_score << endl;
    cout << avg << endl;

    return 0;
}

/***********************************/
int process(int a, int b)
{
    return a > b ? a : b;
}

/***********************************/
double process(double a, int b)
{
    return (a + b) / 2;
}
