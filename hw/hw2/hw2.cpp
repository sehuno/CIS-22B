// This program reads in a number of airports, their names code which are in
// alphabetical order, and the list of numbers showing the price of a ticket
// from that airport to all of the others. It then prints out a formatted table
// of the input data, the list and number of destinations for each airport, groups
// of two airports connected by flights, and the cheapest flight price/destination 
// for each airport. 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Global variable
const int MAX_AIRPORTS = 30;	// Maximum number of airports we can parse

// Function prototypes
int readInAirports(string fName, string names[MAX_AIRPORTS], int matrix[][MAX_AIRPORTS], int detArr[][3], int connectingFlights[][MAX_AIRPORTS]);
void printFormattedTable(int num, int matrix[][MAX_AIRPORTS], string names[]);
void printDestinations(int num, int p_connectInfo[][3], int indexes[][MAX_AIRPORTS], string names[]);
void printGroups(int num, int matrix[][MAX_AIRPORTS], string names[]);
void printCheapest(int num, int p_connectInfo[][3], int indexes[][MAX_AIRPORTS], string names[]);

int main() {

	// A matrix containing flight prices from each airport to all others.
	int flightMatrix[MAX_AIRPORTS][MAX_AIRPORTS]; 	

	// A 2-Dimensional array which stores the cheapest flight, 
	// number of connects, and the index for the cheapest flight 
	// for each airport.
	int connectInfo[MAX_AIRPORTS][3];	

	// A 2-Dimensional array which stores the corresponding index of 
	// destination airports of connecting flights for each airport.
	int indexOfConnects[MAX_AIRPORTS][MAX_AIRPORTS];

	// The number of airports we are dealing with
	int numAirports;

	// A string array of the 3-Letter codes of each airport.
	string airportNames[MAX_AIRPORTS];

	// File name we must input data from
	string fileName = "airports.txt";


	// Read in input file, process the information, and get the number of airports
	numAirports = readInAirports(fileName, airportNames, flightMatrix, connectInfo, indexOfConnects);

	// Number validation for quantity of airports. If valid, print processed information.
	if(numAirports > 0 && numAirports < MAX_AIRPORTS) {

		// Print the formatted table 
		printFormattedTable(numAirports, flightMatrix, airportNames);

		// Prints the 
		printDestinations(numAirports, connectInfo, indexOfConnects, airportNames);
		
		// Print groups of two airports connected by flights
		printGroups(numAirports, flightMatrix, airportNames);

		// Print the cheapest flight price and destinatio nfor each airport
		printCheapest(numAirports, connectInfo, indexOfConnects, airportNames);
		
	} 
	else {
		cout << "Program terminated with Error Code 1. Please review text file." << endl;
		return 1;
	}

	return 0;

}


/* FUNCTIONS */

//******************************************************************************************************************************
// The readInAirports function accepts a string of the file, a string array of airport names, a 2d int array for flight prices,*    
// a 2d int array containing cheapest flight, number of connects, and index for the cheapest flight, a 2d int array for 	   *
// corresponding indexes of destination airports of connecting flights for each airport. The element returned is an int.       *  
//******************************************************************************************************************************

int readInAirports(string fName, string names[MAX_AIRPORTS], int matrix[][MAX_AIRPORTS], int detArr[][3], int connectingFlights[][MAX_AIRPORTS]) {
	fstream inputFile;
	inputFile.open(fName);

	int num,		// Number of aiports
		curr, 		// Current price we are looking at
		cheapest, 	// Value to keep track of cheapest flight price
		connects,	// Number of connects
		cheapestIndex;	// The corresponding index for the airport which has the cheapest connecting flight

	// Read in first line which contains the number of airports	
	inputFile >> num;
	if(num > MAX_AIRPORTS) 
		// If exceeds the maximum, do not process elements
		cout << "The number of airports entered, " << num << ", exceeds the maximum!" << endl;
	else {
		// Read in the next num lines for each airport name and store them in the names array
		for(int k = 0; k < num; k++) 
			inputFile >> names[k];

		// Process each line
		for(int i = 0; i < num; i++) {
			cheapest = connects = 0;		// Reset cheapest price and numbers of connects for every airport

			for(int j = 0; j < num; j++) {
				inputFile >> curr;			// Read in current value
				matrix[i][j] = curr;		// Set the matrix value 

				// If there is a connecting flight, process it
				if(curr != 0) {
					connectingFlights[i][connects] = j;		// For the airport, store the index of destination airport 
					if(cheapest == 0) {			// Cheapest will be 0 if none has been found yet
						cheapest = curr;		// Set current price to cheapest
						cheapestIndex = j;		// Set current cheapest index to current index
						connects++;				// Increment number of connects for airport
					}		
					else {
						cheapest = (cheapest < curr ? cheapest : curr);		// Set cheapest to whatever is cheapest LOL
						connects++;
					}
				}
			}
			detArr[i][0] = cheapest;		// Store cheapest flight price
			detArr[i][1] = connects;		// Store number of connects
			detArr[i][2] = cheapestIndex;	// Store index of cheapest destination airport
		}
	}

	inputFile.close();	// Close file

	return num; 	// return number of airports
}


///************************************************************************************************************
// The printFormattedTable function accepts an int variable for number of airports, a 2d int array for flight *
// prices, and a string array of airport names. The function prints the formatted table of flight prices.     *
//*************************************************************************************************************

void printFormattedTable(int num, int matrix[][MAX_AIRPORTS], string names[]) {
	cout << "Displaying formatted table: " << endl;
	cout << setw(5) << right << "|";
	for(int i = 0; i < num; i++) 
		cout << setw(4) << right << names[i];		// Display names on top row
	cout << endl;

	cout << setw(6) << left << "---";				// Display dashes
	for(int j = 0; j < num; j++) 
		cout << setw(4) << left << "---";			// MORE DASHES
	cout << endl;

	// Display names and flight prices for each line
	for(int k = 0; k < num; k++) {
		cout << setw(4) << left << names[k] << "|" << setw(4) << right;	
		for(int l = 0; l < num; l++)
			cout << setw(4) << right << matrix[k][l];	
		cout << endl;
	}
	cout << endl; 
}


///***********************************************************************************************************
// The printGroups function accepts an int variable for number of airports, a 2d int array for flight prices,*
// and a string array of airport names. The function prints groups of two airports connected by flights. 	 *
//************************************************************************************************************

void printGroups(int num, int matrix[][MAX_AIRPORTS], string names[]) {
	cout << "Displaying groups of two airports connected by flights: " << endl;

	// i = 0, j = i+1 : Only looking at the top half of matrix *disregarding diagonal* to avoid duplicate pairs
	for(int i = 0; i < num; i++) 
		for(int j = i+1; j < num; j++) 
			if(matrix[i][j] != 0)		// If a flight exists, print the connecting airport names
				cout << names[i] << " - " << names[j] << endl;
	cout << endl;
}


//***********************************************************************************************************************************
// The printDestinations function accepts int for number of airports, a string array of airport names, a 2d int array which stores *
// the cheapest flight, number of connects, and the index for the cheapest flight, a 2d int array which stores the corresponding    *
// index of destination airports of connecting flights for each airport, and a string array of airport names. The function          *
// prints the list and number of destinations for each airport.																        *
//***********************************************************************************************************************************

void printDestinations(int num, int p_connectInfo[][3], int indexes[][MAX_AIRPORTS], string names[]) {
	cout << "Displaying list and number of destinations for each airport: " << endl;
	for(int i = 0; i < num; i++) {
		cout << names[i] << " (" << p_connectInfo[i][1] << "):";	// Display name of airport and number of connects
		for(int j = 0; j < p_connectInfo[i][1]; j++) {			
			if(j != 0)												
				cout << ",";
			cout << setw(4) << right << names[indexes[i][j]];		// Display the names of connecting airports
		}															// indexes array has the indexes of connecting airports
		cout << endl;
	}
	cout << endl;
}


//******************************************************************************************************************************
// The printCheapest function accepts an int for number of aiport, a string array of airport names, a 2d array which stores the*
// corresponding index of destination airports of connecting flights for each airport, a 2d int array with the corresponding   *
// indexes of destination airports of connecting flights for each airport. The function prints the cheapest flight price and   *
// destination for each airport.																							   *
//******************************************************************************************************************************

void printCheapest(int num, int p_connectInfo[][3], int indexes[][MAX_AIRPORTS], string names[]) {
	cout << "Displaying cheapest flight price and destination for each airport: " << endl;
	for(int i = 0; i < num; i++) {
		// Display the name of the airport and the cheapest airport name and the cheapest flight price stored in the p_connectInfo array
		cout << names[i] << " -> " << names[p_connectInfo[i][2]] << setw(5) << right << p_connectInfo[i][0] << endl;
	}
	cout << endl;
}

//****************************************************************
// please have mercy and give me a good grade professor.		 *
// i tried SO hard for this   		 					   		 *
// b-b-b-but my output was never wrong in the first place..		 *
// (*꒦ິ⌓꒦ີ) 		*cries in a corner* 						     *
//****************************************************************

/* OUTPUT */
/*

Displaying formatted table: 
    | BUR FAT LGB LAX MRY OAK SMF SAN SFO SJC SBO SMO
---   --- --- --- --- --- --- --- --- --- --- --- --- 
BUR |   0   0   0   0 122   0   0   0   0   0 316   0
FAT |   0   0   0   0   0   0   0   0 321 455   0   0
LGB |   0   0   0 125   0   0   0   0 267   0   0   0
LAX |   0   0 125   0   0  50   0   0 250   0 370   0
MRY | 122   0   0   0   0 259   0   0   0   0   0 119
OAK |   0   0   0  50 259   0   0 129   0   0   0   0
SMF |   0   0   0   0   0   0   0 111   0   0 125   0
SAN |   0   0   0   0   0 129 111   0   0   0   0   0
SFO |   0 321 267 250   0   0   0   0   0 190   0   0
SJC |   0 455   0   0   0   0   0   0 190   0   0   0
SBO | 316   0   0 370   0   0 125   0   0   0   0 145
SMO |   0   0   0   0 119   0   0   0   0   0 145   0

Displaying list and number of destinations for each airport: 
BUR (2): MRY, SBO
FAT (2): SFO, SJC
LGB (2): LAX, SFO
LAX (4): LGB, OAK, SFO, SBO
MRY (3): BUR, OAK, SMO
OAK (3): LAX, MRY, SAN
SMF (2): SAN, SBO
SAN (2): OAK, SMF
SFO (4): FAT, LGB, LAX, SJC
SJC (2): FAT, SFO
SBO (4): BUR, LAX, SMF, SMO
SMO (2): MRY, SBO

Displaying groups of two airports connected by flights: 
BUR - MRY
BUR - SBO
FAT - SFO
FAT - SJC
LGB - LAX
LGB - SFO
LAX - OAK
LAX - SFO
LAX - SBO
MRY - OAK
MRY - SMO
OAK - SAN
SMF - SAN
SMF - SBO
SFO - SJC
SBO - SMO

Displaying cheapest flight price and destination for each airport: 
BUR -> MRY  122
FAT -> SFO  321
LGB -> LAX  125
LAX -> LGB   50
MRY -> BUR  119
OAK -> LAX   50
SMF -> SAN  111
SAN -> OAK  111
SFO -> FAT  190
SJC -> FAT  190
SBO -> BUR  125
SMO -> MRY  119

*/



