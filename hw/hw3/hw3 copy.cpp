#include <iostream>
#include <fstream>

using namespace std;

void insertionSortRow(double *rp);

int main() {
	ifstream inputFile;
	double **raggedArr;
	double **pp;
	double **pp_end;

	double *rp;
	double *rp_end;

	int num_rows;
	int num_elems;

	inputFile.open("ragged.txt");

	if(!inputFile) {
		cout << "Error while opening file!" << endl;
		return 1;
	}
	else {
		while(!inputFile.eof()) {
			inputFile >> num_rows;
			raggedArr = new double*[num_rows+1];

			for(pp = raggedArr, pp_end = raggedArr+num_rows; pp <= pp_end; pp++) {

				if(pp == pp_end) {
					pp = NULL;
					break;
				}
				else {
					inputFile >> num_elems; 
					*pp = new double[num_elems+1];

					for(rp = *pp, rp_end = (*pp)+num_elems; rp <= rp_end; rp++) {
						if(rp == *pp)
							*rp = double(num_elems);
						else
							inputFile >> *rp;
						// cout << rp << ": " << *rp << endl;
					}

					insertionSortRow(*pp);

					delete[] *pp;

				}
				// cout << endl;
			}

			// Sort array
			// Display array
			// Delete rows and array

			delete[] raggedArr;
		}
	}



	return 0;
}

void insertionSortRow(double *rp) {
	double *p;
	double *curr;
	double *temp;
	double hold;
	double *back;

	// cout << (0x7f81e3c03438 > 0x7f81e3c03440) << endl;
	// for(p = rp+2; p != NULL; p++) {
	// 	back = p-1;
	// 	hold = *p;
	// 	cout << "back: " << back << " hold: " << hold << endl; 
	// 	while((back >= rp+1)==1 && hold > *back) {
	// 		cout << "back != NULL && hold > *back" << endl;
	// 		cout << "*(back+1) = " << *back << " back now --" << endl;
 // 			*(back+1) = *back;
 // 			back--;
	// 	}
	// 	*(back+1) = hold;
	// 	cout << "*(back+1) = " << hold << endl;
	// }
}

// void insertionSort(int array[], int size)
// {
//    for (int curr = 1; curr < size; curr++)
//    {
//       int hold = array[curr];                   // copy current element to hold
//       int back = curr - 1;
//       while (back >= 0 && hold < array[back])   // search where to insert the current element
//       {
//           array[back + 1] = array[back];        // shift to the right
//           back--;
//       }
//       array[back + 1] = hold;                   // put hold back to the array
//    }
// }

void insertionSortArray() {
	cout << "Needs to be implemented" << endl;
}
