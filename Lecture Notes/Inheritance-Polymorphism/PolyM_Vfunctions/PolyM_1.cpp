/**
POLYMORPHISM // many shapes
1. Biology: The existence of two or more different forms in an adult organism of the same species, as of an insect.
   In bees, the presence of queen, worker, and drone is an example of polymorphism.
2. Chemistry: The crystallization of a compound in at least two distinct forms.
   Diamond and graphite, for example, are polymorphs of the element carbon.
   They both consist entirely of carbon but have different crystal structures and different physical properties.
3. Programming: functions behave differently in different contexts
   C++ polymorphism means that a call to a member function will cause a different function to be executed
   depending on the type of object that invokes the function.
*/

/** DERIVED CLASSES and POINTERS

    A pointer to a derived class is type-compatible with a pointer to its base class
    Polymorphism is based on this fact.
*/


// pointers to base class
#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width, height;
    public:
        void set_values (int w, int h) { width = w; height = h; }
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

int main()
{
    Rectangle rect;
    Triangle trgl;
    Shape *p1 = &rect;
    Shape *p2 = &trgl;

    p1->set_values (5, 8);
    p2->set_values (5, 8);
    cout << rect.calcArea() << endl;
    cout << trgl.calcArea() << endl;
    return 0;
}



