// Program that parses a text file into words and counts 
// the number of occurences of each word, displays the
// word with the highest frequency, and writes to file
// processed information of the input file
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
const int MAX_SIZE = 100;

struct Word 
{
	string word; 	// Word
	int freq; 		// Frequency of word
};

// Function prototypes
void parseFile(string file, int &num, int &m_length, int &h_freq, Word[]);
void updateArr(int &num, int &h_freq, int &max, string word, Word[]);
void displayHighestWords(int num, int freq, Word[]);
void writeToFile(string file, int num, int h_freq, int max, Word[]);

int main() {
	int num_words;		// Number of words read in so far
	int max_length;		// The max length of word encountered
	int highest_freq;	// The high frequency of word encountered

	string fileName = "song_ten.txt";
	// string fileName = "song_row.txt";

	// Array of Word structs
	Word wordArr[MAX_SIZE];	

	// Parse input file and process each word 
	parseFile(fileName,num_words,max_length,highest_freq,wordArr);
	
	// Display the word(s) with the highest frequency
	displayHighestWords(num_words, highest_freq, wordArr);

	// Write to output file processed information of words encountered
	writeToFile(fileName, num_words, highest_freq, max_length, wordArr);
}

/* FUNCTIONS */

//*****************************************************************************************************************************************
// The parseFile function accepts a string variable of the filename, int variable of number of words, int variable of highest frequency   *
// of a word, and a Word array containing Word structs of words and frequencies. The function reads in each line and parses the line into *
// words with only characters and calls the updateArr function to store words into arrays.											      *
//*****************************************************************************************************************************************
void parseFile(string file, int &num, int &m_length, int &h_freq, Word wArr[]) {
	fstream inputFile;	// input file stream
	string word;	// string variables to each word

	inputFile.open(file, ifstream::in);	// open filestream with input file

	// while input file is open
	if(inputFile.is_open()) {

		while(inputFile >> word) {							// while word was input from file
			while(!isalpha(word[word.length()-1]))			// 	 remove nonalpha characters from word starting from end
				word = word.substr(0,word.length()-1);		//	  so that the word is a substring containing only alpha chars
			
			for(int i = 0; i < word.length()-1; i++)		// Edit word to only contain lowercase characters by checking each character
				if(isupper(word[i]))
					word[i] = tolower(word[i]);
			updateArr(num, h_freq, m_length, word, wArr);	// When word is done processing, update the Word array with proper values
		}

		if(num == 0)										// Print out message if no words were read in
			cout << "No words were read in!" << endl;

		inputFile.close();									// close input file
	}
}

//**************************************************************************************************************************************
// The displayHighestWords function accepts an int variable of number of words, int variable of highest frequency of a word, 		   *
// a Word array containing Word structs of words and frequencies. The function prints out the word(s) that have the highest frequency. *										   *
//**************************************************************************************************************************************
void displayHighestWords(int num, int freq, Word wArr[]) {
	cout << "Displaying word(s) with the highest frequency (" << freq << "):" << endl;

	for(int i = 0; i < num; i++) {			// Find the frequency value of wordwhich is equal to the highest freq
		if(wArr[i].freq == freq)				// If found, print the word(s)
			cout << wArr[i].word << endl;		
	}
}


//***************************************************************************************************************************************
// The updateArr function accepts an int variable of number of words, int variable of highest frequency of a word, int variable of the 	*
// longest length of a word, and a Word array containing Word structs of words and frequencies. The function will update the array that	*
// contain words and the frequencies. It also updates the number or words found, the highest frequency of a word, and the longest length*
// found so far from the input file.																									*
//***************************************************************************************************************************************
void updateArr(int &num, int &h_freq, int &max, string word, Word wArr[]) {
	int counter = num;				

	// if it is the first word 
	if(counter == 0) {		
		wArr[counter].word = word;	// Add word
		wArr[counter].freq = 1;		// Set frequency to 1
		h_freq = 1;					// highest frequency so far is set to 1
		max = word.length();		// set the longest length to length of the first word
		num++;						// increment number of words
 	}
 	else {
 		Word temp_w1, temp_w2;
 		temp_w1.word = temp_w2.word = "";		// set temp Word.word's to empty strings
 		temp_w1.freq = temp_w2.freq = 0;		// set temp Word.freq's to 0's

 		for(int i = 0; i < counter; i++) {		// traverse through arrays to find spot for current word

 			if(wArr[i].word == word) {		// if word exist increment frequency, and update highest frequency if needed
 				wArr[i].freq++; 				
 				h_freq = (h_freq > wArr[i].freq ? h_freq: wArr[i].freq);
 				return;
 			}
 			if(word < wArr[i].word) {		// if word comes before the current indexed word alphabetically edit arrays

 				for(int j = i-1; j < counter; j++) {	// for each word from this current index, push back values to make space
 					temp_w2 = temp_w1;			

 					temp_w1.word = wArr[j+1].word;
 					temp_w1.freq = wArr[j+1].freq;

 					wArr[j+1].word = temp_w2.word;
 					wArr[j+1].freq = temp_w2.freq;
 				}

 				wArr[i].word = word;			// insert current word at the index that was emptied
 				wArr[i].freq = 1;				// set the new frequency to be 1
 				max = (max > word.length() ? max : word.length());		// since new word was added, update longest length if needed
 				num++;						// increment number of words
 				return;						// return from function so that it does not check any further
 			}
 		}

 		// this part of function is reached if the current word read in comes after all others alphabetically
 		wArr[counter].word = word;			// insert word at the end
 		wArr[counter].freq = 1;				// increment frequency value
 		max = (max > word.length() ? max : word.length());		// since new word was added, update longest length if needed
 		num++;							// increment number of words
 	}
}


//***************************************************************************************************************************
// The writeToFile function accepts a string variable containing name of input file, int variable of number of words, int 	*
// variable of highest frequency of a word, int variable of the longest length of a word, and a Word array containing Word  *
// structs of words and frequencies. The function will write to an output file the processed information of the input file. *													*
//***************************************************************************************************************************
void writeToFile(string file, int num, int h_freq, int max, Word wArr[]) {
	ofstream outputFile;							// create output file stream
	string outputFileName = "output_" + file;		// output file name is "output_" + input filename
	outputFile.open(outputFileName);				// open output file stream

	string out_line = "";							// use an empty string to append need-to-print elements

	out_line = to_string(num) + " words" + "\n";				// first line for number of words
	outputFile << out_line;	
	out_line = "Maximum length: " + to_string(max) + "\n";		// second line for maximum length of word encountered
	outputFile << out_line;
	out_line = "Highest frequency: " + to_string(h_freq) + "\n" + "\n";		// third line for the highest frequency of word
	outputFile << out_line;

	for(int i = 0; i < num; i++) {		// for each line print the frequency and the word encountered with proper formatting
		int length = 1;
		int temp = wArr[i].freq;
		out_line = "";

		// find how many spaces are needed before the frequency of word for proper formatting
		while(temp /= 10)	
		   length++;
		for(int j = 0; j < 3-length; j++) 			
			out_line += " ";

		// append to line the frequency and word
		out_line += to_string(wArr[i].freq) + " " + wArr[i].word + "\n";	// 

		// write line to output file
		outputFile << out_line;
	}

	outputFile.close();	// close output file.
}

/* OUTPUT */
/* 
	*Note: output files are included in the folder

	For song_row.txt: 

		Displaying word(s) with the highest frequency (4):
		merrily

		*file: output_song_row.txt*

	For song_ten.txt: 

		Displaying word(s) with the highest frequency (4):
		green

		*file: output_song_ten.txt*

*/


	