#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void insertionSortRow(double *row);		// Sorts the row in descending order
void insertionSortArray(double **arr);	// Sorts the ragged array from longest length to shortest length
void writeRaggedArray(double **arr);	// Prints elements of the ragged array to screen with proper formatting
void freeArray(double **arr);			// Frees all dynamically allocated arrays

int main() {
	ifstream inputFile;

	double **raggedArr;

	int num_rows;
	int num_elems;

	inputFile.open("ragged.txt");

	if(!inputFile) {
		cout << "Error while opening file!" << endl;
		return 1;
	}
	else {
		inputFile >> num_rows;
		raggedArr = new double*[num_rows+1];
		raggedArr[num_rows] = NULL;

		for(int i = 0; i < num_rows; i++) {

			inputFile >> num_elems;
			raggedArr[i] = new double[num_elems+1];

			raggedArr[i][0] = num_elems;
			for(int j = 1; j < num_elems+1; j++) 
				inputFile >> raggedArr[i][j];

			insertionSortRow(raggedArr[i]);
		}
		
		inputFile.close();

		insertionSortArray(raggedArr);

		cout << "The ragged array has " << num_rows << " rows:" << endl;
		writeRaggedArray(raggedArr);

		freeArray(raggedArr);
	}

	return 0;
}

void insertionSortRow(double *row) {
	int num = row[0]+1; 

	for (int curr = 1; curr < num; curr++) {
      double hold = row[curr];                   // copy current element to hold
      int back = curr - 1;
      while (back >= 1 && hold > row[back])   // search where to insert the current element
      {
          row[back + 1] = row[back];        // shift to the right
          back--;
      }
      row[back + 1] = hold;                   // put hold back to the array
   }
}

void insertionSortArray(double **arr) {
	double **curr;
	double **back;
	double *hold;

	for(curr = arr+1; *curr != NULL; curr++) {
		hold = *curr;
		back = curr-1;
		while( (back >= arr) == 1 && *hold > **back) {
			*(back+1) = *back;
			back--;
		}
		*(back+1) = hold;
	}
}

void writeRaggedArray(double **arr) {
	double **curr; 
	for(curr = arr; *curr != NULL; curr++) {
		for(int i = 0; i < (*curr)[0]+1 ; i++) {
			if(i == 0)
				cout << setw(2) << right << int((*curr)[i]);
			else 
				cout << fixed << setprecision(1) << setw(6) << right << (*curr)[i];
		}
		cout << endl;
	}

}

void freeArray(double **arr) {
	double **curr; 
	for(curr = arr; *curr != NULL; curr++) {
		delete [] *curr;
	}
	delete [] arr;
}


/* OUTPUT */
/* 

The ragged array has 13 rows:
11   9.0   8.9   7.5   6.2   5.3   3.5   2.1   1.6   1.2   1.2   0.8
 7 888.8  99.9  56.8  54.6  23.5  12.2  10.8
 6 888.8  56.8  54.6  23.5  12.2  10.8
 5  56.8  54.6  23.5  12.2   5.8
 5 125.6  38.4  25.2   6.3   4.6
 4  51.2  35.6  23.9   3.7
 3  51.2  35.6  23.9
 3 111.5  34.9  12.1
 3   5.6   5.1   3.5
 2  34.9  12.1
 2  88.8   0.5
 2 384.5   2.9
 1  88.8

 */

