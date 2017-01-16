// Header file for the Automobile class
#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
#include <iomanip>
using namespace std;

// The Automobile class holds general data
// about an automobile in inventory.
class Automobile
{
private:
   string make;   // The auto's make
   int model;     // The auto's year model
   int mileage;   // The auto's mileage
   double price;  // The auto's price

public:
   // Default constructor
   Automobile()
   {  make = "";
      model = 0;
      mileage = 0;
      price = 0.0; }
               
   // Constructor
   Automobile(string autoMake, int autoModel,
              int autoMileage, double autoPrice)
   {  make = autoMake;
      model = autoModel;
      mileage = autoMileage;
      price = autoPrice; }

   // Virtual Destructor
   virtual ~Automobile() {}
   
   virtual void printAutomobileType() = 0;
   virtual void printAdditionalInfo() = 0;

   void printVehicle() {
      printAutomobileType();
      cout << setw(15) << right << "Make: " << getMake() << endl; 
      cout << setw(15) << right << "Year/Model: " << getModel() << endl;
      cout << setw(15) << right << "Mileage: " << getMileage() <<  endl;
      cout << setprecision(2) << fixed << setw(15) << right << "Price: " << getPrice() << endl;
      printAdditionalInfo();
      cout << endl;
   }
   
   // Accessors
   string getMake() const
   { return make; }
   
   int getModel() const
   { return model; }
   
   int getMileage() const
   { return mileage; }
   
   double getPrice() const
   { return price; }
};
#endif