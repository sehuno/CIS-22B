// Question.h
#ifndef Question_H
#define Question_H

#include <iostream>
#include <string>

using namespace std;

class Question {
	public:
		Question() {};								// Default constructor
		Question(string, string[4]);				// Custom constructor that takes in a string question and array of strings for answers
		Question& operator=(const Question &q);		// Assignment operator
		~Question() {};								// Destructor

		void displayQuestion() const;			// Displays the question
		void displayAnswers() const;					// Displays list of answers

		int checkAnswer(int choice) const;		// Takes answer from player, checks answer and prints message accordingly (0 if correct, 1 if wrong)
		void displayCorrectAnswer() const;		// Displays correct answer.
		void randomizeAnswers();			// Randomize the answers of the question while maintaining correct answer index
	private:
		string question;					// The question stored as string
		string answers[4];					// The answers stored as a string array
		int answer_index;					// The index for the correct answer 
};



#endif
