#include <iostream>
#include <fstream>

using namespace std;

void insertionSortRow(double *rp);

int main() {
	ifstream inputFile;
	double ***raggedArr;

	double ***rap;
	double ***rap_end;

	double **row_p;
	double **row_p_end;

	double *ep;
	double *ep_end;

	double val;

	int num_rows;
	int num_elems;

	inputFile.open("ragged.txt");

	if(!inputFile) {
		cout << "Error while opening file!" << endl;
		return 1;
	}
	else {
		// while(!inputFile.eof()) {
			inputFile >> num_rows;
			raggedArr = new double**[num_rows+1];

			for(rap = raggedArr, rap_end = raggedArr+num_rows-1; rap <= rap_end; rap++) {

				inputFile >> num_elems;
				*rap = new double*[num_elems+2];
				**rap = new	double(num_elems);

				for(row_p = *rap+1, row_p_end = *rap+num_elems+1; row_p <= row_p_end; row_p++) {

					if(row_p == row_p_end) {
						*row_p = NULL;
						break;
					}
					else {
						inputFile >> val;
						*row_p = new double(val);
						// cout << **row_p << endl;
					}

				}
				insertionSortRow(*rap);
				cout << endl;
			}

			// Sort array
			// Display array
			// Delete rows and array

			delete[] raggedArr;
		// }
	}



	return 0;
}

void insertionSortRow(double *rp) {
	double *back;
	double *hold;
	double *curr;
	double *temp;

	for(curr = rp; curr != NULL; curr++) {
		cout << *rp << endl;
	}

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
