/**
    Abstract base classes
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
        // CALL A PURE VIRTUAL MEMBER FROM THE ABSTRACT BASE CLASS
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
  Shape *p1 = &rect;
  Shape *p2 = &trgl;

  p1->set_values (5, 8);
  p2->set_values (5, 8);

  p1->printArea();
  p2->printArea();

  return 0;
}
