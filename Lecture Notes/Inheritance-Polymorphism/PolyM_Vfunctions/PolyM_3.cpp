/**
    Abstract base classes

    A class that contains at least one pure virtual function is an ABSTRACT BASE CLASS
*/
#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width, height;
    public:
        void set_values (int w, int h) { width = w; height = h; }
        virtual int calcArea() = 0; // NO IMPLEMENTATION FOR THIS FUNCTION
                                    // PURE VIRTUAL FUNCTION
};

class Rectangle : public Shape
{
    public:
        int calcArea() { return (width * height); }
};

class Triangle : public Shape
{
    public:
        int calcArea() { return (width * height / 2); }
};

int main() {
    Rectangle rect;
    Triangle trgl;
    //Shape s;            // CANNOT CREATE AN INSTANCE OF AN ABSTRACT CLASS
    Shape *p1 = &rect;
    Shape *p2 = &trgl;
    //Shape *p3 = &s;

    p1->set_values (5, 8);
    p2->set_values (5, 8);
    //p3->set_values (5, 8);
    cout << p1->calcArea() << endl;
    cout << p2->calcArea() << endl;
    //cout << p3->calcArea() << endl;
    return 0;
}
