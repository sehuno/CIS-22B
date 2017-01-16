// Header file for the Car class
#ifndef CAR_H
#define CAR_H
#include "Automobile.h"
#include <string>
using namespace std;

// The Car class represents a car.
class Car : public Automobile
{
private:
   int doors;
   
public:
   // Default constructor
   Car() : Automobile()
   { doors = 4; }
   
   // Constructor #2
   Car(string carMake, int carModel, int carMileage,
       double carPrice, int carDoors) :
       Automobile(carMake, carModel, carMileage, carPrice)
    { doors = carDoors; }

    // Destructor
   ~Car() {};
   
   // Accessor for doors attribute
   int getDoors()
   { return doors; }

   void printAutomobileType() {
    cout << "We have the following CAR in inventory: " << endl;
   }

   void printAdditionalInfo(){
    cout << setw(15) << right << "Doors: " << doors << endl;
   }
};
#endif 