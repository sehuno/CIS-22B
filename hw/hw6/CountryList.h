// Specification file for the CountryList class
#ifndef COUNTRYLIST_H
#define COUNTRYLIST_H

#include <cstring>
// Header file for the CountryList class
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Country
{
   char code[2];
   string name;
   string capital;
   int population;
};

struct ListNode
{
   Country country;
   ListNode *next;  // To point to the next node
};

class CountryList
{
   private:
      // Declare a structure for the list

      ListNode *head;            // List head pointer

   public:
      // Constructor
      CountryList()
         { head = NULL; };

      // Destructor
      ~CountryList();

      // Linked list operations
      void insertNode(string, string, string, int);
      void deleteNode(string);
      void searchNode(string) const;
      void displayList() const;

};
#endif
