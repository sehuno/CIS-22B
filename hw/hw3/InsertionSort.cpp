//
// Modify the insertion sort function to 1. Sort in descending order, and 2. Replace int by double.
// Then use the modified insertion sort in your Homework 3
//
// This program uses the INSERTION sort algorithm to sort an
// array in ascending order.
//
#include <iostream>
using namespace std;

// Function prototypes
void insertionSort(int [], int);
void showArray(int [], int);

int main()
{
   // Define an array with unsorted values
   const int SIZE = 6;
   int values[SIZE] = {50, 70, 20, 80, 90, 10};

   // Display the values.
   cout << "The unsorted values are\n";
   showArray(values, SIZE);

   // Sort the values.
   insertionSort(values, SIZE);

   // Display the values again.
   cout << "The sorted values are\n";
   showArray(values, SIZE);
   return 0;
}

//**************************************************************
// Definition of function insertionSort.                       *
// This function performs an ascending order insertion sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void insertionSort(int array[], int size)
{
   for (int curr = 1; curr < size; curr++)
   {
      int hold = array[curr];                   // copy current element to hold
      int back = curr - 1;
      while (back >= 0 && hold < array[back])   // search where to insert the current element
      {
          array[back + 1] = array[back];        // shift to the right
          back--;
      }
      array[back + 1] = hold;                   // put hold back to the array
   }
}

//**************************************************************
// Definition of function showArray.                           *
// This function displays the contents of array. size is the   *
// number of elements.                                         *
//**************************************************************

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}
