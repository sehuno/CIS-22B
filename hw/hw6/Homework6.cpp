// This is a function that 

#include <iostream>
#include <fstream>
#include "CountryList.h"
#include "CountryList.cpp"
using namespace std;

// Function prototypes
void buildList(CountryList *list, string fileName);
void deleteCountry(CountryList *list);
void searchCountry(CountryList *list);
bool codeValid(string code);

int main()
{
  string filename;

  // Prompt user for filepath to inputfile
  cout << "Please enter filepath for the Countries.txt file." << endl;
  getline(cin,filename);

   // Define a CountryList object.
  CountryList list;

   // Build list from file
  buildList(&list,filename);
   
   // Display list as tables
  list.displayList();

   // Prompt user for countries to be deleted
  deleteCountry(&list); cout << endl;

   // Search countries
  searchCountry(&list);

   // Destroy list
  return 0;
}

// The buildList function takes a pointer to a CountryList object and a string for the input filename
//  and builds a linked list of nodes in alphabetic order of country codes.
void buildList(CountryList *list, string fileName) {
  ifstream inputFile;
  inputFile.open(fileName); // open input file

  string code, line, name, capital;
  int population;

  if(!inputFile.good()) {                                   // Input file validation, exit it error
    cout << "Error opening input file!" << endl;
    exit(1);
  }
  else 
    while(!inputFile.eof()) {
      getline(inputFile, line);                             // Inputs line by line 
        
      code = line.substr(0, line.find(" "));                // Code is the first two characters of the line
      line = line.substr(line.find(" ")+1,line.length());   // Set the line to be the substring of the line excluding code

      name = line.substr(0, line.find(";"));                // Name of country is until the next semicolon
      line = line.substr(line.find(";")+2, line.length());  // Set the line to be the substring of the line excluding code 

      capital = line.substr(0, line.find(";"));             // Capital of country is until the next semicolon
      line = line.substr(line.find(";")+2, line.length());  // Set the line to be the substring of the line excluding code

      population = stoi(line.substr(0, line.find(" ")));    // Population is the remaining characters of the line

      list->insertNode(code, name, capital, population);    // Call the insertNode function with parsed values
    }
}

// The deleteCountry function takes in a pointer to a CountryList object and prompts the user
//  for the country code of the country they wish to delete, deletes it, and exits if 'quit' was entered
void deleteCountry(CountryList *list) {
  string input;
  do {
    cout << endl << "Enter country code of country for deletion: ";
    getline(cin,input);

    while(cin.fail()) {
      cout << "Please enter valid country code: ";
      getline(cin,input); 
      if(input == "quit" || input == "QUIT")
        return;
    }

    if(input == "quit" || input == "QUIT")
      return;
    
    while(!codeValid(input)) {
      cout << "Please enter valid country code: ";
      getline(cin,input); 
      if(input == "quit" || input == "QUIT")
        return;
    }

    // set the input to uppercase
    for(int i = 0; i < input.length(); i++)
      input[i] = toupper(input[i]);

    list->deleteNode(input);

  } while (input != "quit" || input == "QUIT");
}


// The searchCountry function takes in a pointer to a CountryList object and prompts the user
//  for the country code of the country they wish to search for, prints values of it, and exits if 'quit' was entered
void searchCountry(CountryList *list) {
  string input;
  do {
    cout << endl << "Enter country code of country to search for: ";
    getline(cin,input);

    while(cin.fail()) {
      cout << "Please enter valid country code: ";
      getline(cin,input); 
      if(input == "quit" || input == "QUIT")
        return;
    }

    if(input == "quit" || input == "QUIT")
      return;
    
    while(!codeValid(input)) {
      cout << "Please enter valid country code: ";
      getline(cin,input); 
      if(input == "quit" || input == "QUIT")
        return;
    }

    for(int i = 0; i < input.length(); i++)
      input[i] = toupper(input[i]);

    list->searchNode(input);

  } while (input != "quit" || input == "QUIT");
}


// The codeValid function validates a string to make sure that
// it is valid in format so that it can be used to search for 
// the country.
bool codeValid(string code) {
  // If the code is not of length two, then it is invalid
  if(code.length() != 2)    
    return false;

  // If the characters in the string are not alpha then it is invalid
  for(int i = 0; i < code.length(); i++)
    if(!isalpha(code[i]))
      return false;

  return true;
}

/* 
  OUTPUT

Please enter filepath for the Countries.txt file.
/Users/sehun/Documents/22b/hw/hw6/Countries.txt
Code |            Country |        Capital | Population
 ----  ------------------- ----------------  ----------
  AU |          Australia |       Canberra |   20090437
  BR |             Brazil |       Brasilia |  186112794
  BU |           Bulgaria |          Sofia |    7262675
  CA |             Canada |         Ottawa |   32805041
  CN |              China |        Beijing | 1306313812
  DO | Dominican Republic |  Santo Domingo |    8950034
  EG |              Egypt |          Cairo |   77505756
  ES |              Spain |         Madrid |   40341462
  FJ |               Figi |           Suva |     893354
  FR |             France |          Paris |   60656178
  GR |             Greece |         Athens |   10668354
  HU |            Hungary |       Budapest |   10006835
  IR |               Iran |         Tehran |   68017860
  JA |              Japan |          Tokyo |  127288419
  LI |      Liechtenstein |          Vaduz |      33717
  MC |             Monaco |         Monaco |      32409
  MU |          Mauritius |     Port Louis |    1230602
  MX |             Mexico |    Mexico City |  106202903
  NP |              Nepal |      Kathmandu |   27676547
  RU |             Russia |         Moscow |  143420309
  TW |             Taiwan |         Taipei |   22894384
  US |      United States | Washington, DC |  295734134

Enter country code of country for deletion: AU
--> Country for deletion: AU Australia Canberra 20090437

Enter country code of country for deletion: AU
--> Country not found

Enter country code of country for deletion: quit


Enter country code of country to search for: AU
--> Country not found

Enter country code of country to search for: DO
--> Country Found: DO Dominican Republic Santo Domingo 8950034

Enter country code of country to search for: QUIT


*/