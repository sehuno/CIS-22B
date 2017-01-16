/**
    Polymorphism and Dynamic Allocation
*/
#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width, height;
    public:
        void set_values (int w, int h) { width = w; height = h; }
        virtual int calcArea() = 0;
        void printArea() {cout << calcArea() << endl;}
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
    Shape *p1 = new Rectangle;
    Shape *p2 = new Triangle;

    p1->set_values (5, 8);
    p2->set_values (5, 8);

    p1->printArea();
    p2->printArea();

    delete p1;
    delete p2;

    return 0;
}
