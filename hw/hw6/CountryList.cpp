// Implementation file for the CountryList class
#include <iostream>  // For cout  and NULL
#include <iomanip>
#include "CountryList.h"

//**************************************************
// displayList shows the value of the country      *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void CountryList::displayList() const
{
   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   cout << setw(4) << right << "Code" << " | " 
        << setw(18) << right<< "Country" << " | " 
        << setw(14) << right << "Capital" << " | " 
        << setw(10) << right << "Population" << endl;

     cout << setw(4)  << left << " ---- " 
        << setw(18) << right << " -------------------"  
        << setw(14) << right << " ---------------- " 
        << setw(10) << right << " ----------" << endl;



   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr)
   {
      // Display the value in this node.
      //cout << nodePtr->value << endl;
      cout << setw(4) << right << nodePtr->country.code << " | "  
         << setw(18) << right << nodePtr->country.name << " | " 
         << setw(14) << right << nodePtr->country.capital << " | "
         << setw(10) << right << nodePtr->country.population << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function creates a country with  *
// the values that are passed to it and creates and*
// node with the Country.                          *
//**************************************************

void CountryList::insertNode(string code, string name, string capital, int population)
{
   Country new_country;
   ListNode *newNode;             // A new node
   ListNode *nodePtr;             // To traverse the list
   ListNode *previousNode = NULL; // The previous node

   strcpy(new_country.code, code.c_str());
   new_country.name = name;
   new_country.capital = capital;
   new_country.population = population;

   // Allocate a new node and store num there.
   newNode = new ListNode;
   //newNode->value = num;
   newNode->country = new_country;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
      newNode->next = NULL;
   }
   else  // Otherwise, insert newNode
   {
      // Position nodePtr at the head of list.
      nodePtr = head;

      // Initialize previousNode to NULL.
      previousNode = NULL;

      // Skip all nodes whose value is less than num.
      while (nodePtr != NULL && strcmp(nodePtr->country.code,new_country.code) < 0)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
      if (previousNode == NULL)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise insert after the previous node.
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }
}

//**************************************************
// The deleteNode function searches for a node     *
// with input as its country code. The node, if    *
// found, country values are printed and the node  *
// is deleted from the list and from memory.       *
//**************************************************

void CountryList::deleteNode(string input)
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (strcmp(head->country.code,input.c_str())==0)
   {
      nodePtr = head->next;
      cout << "--> Country for deletion: " << head->country.code << " " << head->country.name << " "
         << head->country.capital << " " << head->country.population << endl;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != NULL && strcmp(nodePtr->country.code,input.c_str()) < 0)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list,
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr && strcmp(nodePtr->country.code,input.c_str()) == 0)
      {
         previousNode->next = nodePtr->next;
         cout << "--> Country for deletion: " << nodePtr->country.code << " " << nodePtr->country.name << " "
         << nodePtr->country.capital << " " << nodePtr->country.population << endl;
         delete nodePtr;
      } 
      else
         cout << "--> Country not found" << endl;
   }
}

//**************************************************
// The searchNode function searches for a node     *
// with input as its country's code. The node, if  *
// found, the country's values are printed.        *
//**************************************************

void CountryList::searchNode(string input) const
{
   ListNode *nodePtr;       // To traverse the list
   ListNode *previousNode;  // To point to the previous node

   // If the list is empty, do nothing.
   if (!head)
      return;

   // Determine if the first node is the one.
   if (strcmp(head->country.code,input.c_str())==0)
      cout << "--> Country Found: " << head->country.code << " " << head->country.name << " "
         << head->country.capital << " " << head->country.population << endl;
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is
      // not equal to num.
      while (nodePtr != NULL && strcmp(nodePtr->country.code,input.c_str()) < 0)
      {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If node found, print values, if not print not found
      if (nodePtr && strcmp(nodePtr->country.code,input.c_str()) == 0)
         cout << "--> Country Found: " << nodePtr->country.code << " " << nodePtr->country.name << " "
            << nodePtr->country.capital << " " << nodePtr->country.population << endl; 
      else
         cout << "--> Country not found" << endl;
   }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

CountryList::~CountryList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != NULL)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      // cout << "deleting node of " << nodePtr->country.code << endl;
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }
   // cout << "clist deleted" << endl;
}
