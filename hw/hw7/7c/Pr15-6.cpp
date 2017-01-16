// This program demonstrates the Car, Truck, and SUV
// classes that are derived from the Automobile class.
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;

// Function prototypes
void printInventory(Automobile **automobiles, int numberOfCars);
Automobile** readInInventory(string filename, int &numberOfCars);

int main()
{
    int numberOfCars;           // Variable containing the number of cars we are reading in from the input file 
    string filename;            // Variable to contain the filepath for input file
    Automobile **automobiles;   // Pointer to store location for the dynamically allocated an array of pointers of Automobile objects

    // Prompt user for filepath to input file
    cout << "Please enter the file path to the input file containing inventory: ";
    getline(cin,filename);

    // Read in automobile inventory from input file
    automobiles = readInInventory(filename, numberOfCars);

    // Print all automobiles in the inventory
    printInventory(automobiles,numberOfCars);

    // Free dynamically allocated Automobile pointer array
    delete [] automobiles;

    return 0;
}

// Functions
Automobile** readInInventory(string filename, int &numberOfCars) {
    ifstream inputFile;
    Automobile **automobile_arr;
    inputFile.open(filename);

    string line, automobile_type, make, driveType;
    int model, mileage, doors, passengers;
    double price;

    if(!inputFile.good()) {
        cout << "Error opening input file! Exiting with error code 1.";
        exit(1);
    }
    else {
        while(inputFile.good()) {
            getline(inputFile,line);
            numberOfCars = stoi(line);                                // The first line of input file will contain the number of automobile objects we are dealing with 
            automobile_arr = new Automobile*[numberOfCars];           // Dynamically allocated array of Automobile pointers 

            for(int i = 0; i < numberOfCars; i++) {                   // example line: "Car; BMW; 2007; 50000; 15000.00; 4;""
                getline(inputFile, line);                                 // We will take a substring of the line and parse the attributes using ; as a delimiter

                automobile_type = line.substr(0, line.find(";"));
                line = line.substr(line.find(";")+2,line.length());
                
                make = line.substr(0, line.find(";"));
                line = line.substr(line.find(";")+2,line.length());
                
                model = stoi(line.substr(0, line.find(";")));
                line = line.substr(line.find(";")+2,line.length());
                
                mileage = stoi(line.substr(0, line.find(";")));
                line = line.substr(line.find(";")+2,line.length());
                
                price = stod(line.substr(0, line.find(";")));
                line = line.substr(line.find(";")+2,line.length());

                if(automobile_type == "Car") {                                          // If car, make a Car object
                    doors = stoi(line.substr(0, line.find(";")));
                    automobile_arr[i] = new Car(make,model,mileage,price,doors);
                } 
                else if (automobile_type == "Truck") {                                  // If truck, make a Truck object
                    driveType = line.substr(0, line.find(";"));
                    automobile_arr[i] = new Truck(make,model,mileage,price,driveType);
                } 
                else if (automobile_type == "SUV") {                                    // If SUV, make an SUV object
                    passengers = stoi(line.substr(0, line.find(";")));
                    automobile_arr[i] = new SUV(make,model,mileage,price,passengers);
                }
            }
        }
    }
    return automobile_arr;
}


// The printInventory function will take a double pointer to Automobile and print call the printVehicle function which will display the attributes for each car
void printInventory(Automobile **automobiles, int numberOfCars) {
    for (int j = 0; j < numberOfCars; j++) 
        automobiles[j]->printVehicle();
}

/*  OUTPUT
Please enter the file path to the input file containing inventory: /Users/sehun/Documents/22b/hw/hw7/7c/AutomobileInventory.txt

We have the following CAR in inventory: 
         Make: BMW
   Year/Model: 2007
      Mileage: 50000
        Price: 15000.00
        Doors: 4

We have the following TRUCK in inventory: 
         Make: Toyota
   Year/Model: 2006
      Mileage: 40000
        Price: 12000.00
   Drive Type: 4WD

We have the following SUV in inventory: 
         Make: Volvo
   Year/Model: 2005
      Mileage: 30000
        Price: 18000.00
   Passengers: 5

We have the following CAR in inventory: 
         Make: Audi
   Year/Model: 2007
      Mileage: 80000
        Price: 10000.00
        Doors: 4

We have the following TRUCK in inventory: 
         Make: Nissan
   Year/Model: 1995
      Mileage: 180000
        Price: 3000.00
   Drive Type: AWD

We have the following SUV in inventory: 
         Make: Hyundai
   Year/Model: 2013
      Mileage: 35000
        Price: 25000.00
   Passengers: 7

We have the following CAR in inventory: 
         Make: Mercedes Benz
   Year/Model: 2012
      Mileage: 40000
        Price: 40000.00
        Doors: 2

We have the following TRUCK in inventory: 
         Make: Honda
   Year/Model: 2008
      Mileage: 70000
        Price: 13000.00
   Drive Type: FWD

We have the following SUV in inventory: 
         Make: Suzuki
   Year/Model: 2009
      Mileage: 80000
        Price: 9000.00
   Passengers: 5

We have the following CAR in inventory: 
         Make: Chrysler
   Year/Model: 2007
      Mileage: 80000
        Price: 11000.00
        Doors: 2

We have the following TRUCK in inventory: 
         Make: Ford
   Year/Model: 2010
      Mileage: 40000
        Price: 12000.00
   Drive Type: RWD

We have the following SUV in inventory: 
         Make: GMC
   Year/Model: 1998
      Mileage: 230000
        Price: 4000.00
   Passengers: 10

We have the following CAR in inventory: 
         Make: Mazda
   Year/Model: 1994
      Mileage: 33000
        Price: 25000.00
        Doors: 2

We have the following TRUCK in inventory: 
         Make: Dodge
   Year/Model: 2000
      Mileage: 130000
        Price: 6000.00
   Drive Type: AWD

We have the following SUV in inventory: 
         Make: Mitsubishi
   Year/Model: 2010
      Mileage: 60000
        Price: 30000.00
   Passengers: 5
*/

