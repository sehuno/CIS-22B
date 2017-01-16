#include "Question.h"
#include <time.h>
#include <stdlib.h>

// Custom constructor for the question, taking in a string for the question
//  and a string array for the answers
Question::Question(string ques, string ans[4]) 
{ 	
	question = ques;
	for(int i = 0; i < 4; i++)
		answers[i] = ans[i];
	answer_index = 0; 
};

// Assignment operator for the Question class
Question &Question::operator=(const Question &q)
{
   // Check for self assignment
   if(this != &q) {
      this->question = q.question;
      for(int i = 0; i < 4; i++) 
        this->answers[i] = q.answers[i];
      this->answer_index = q.answer_index;
   }
   return *this;
};

// Prints the question
void Question::displayQuestion() const 
{
  cout << question << endl;
}

// Print the answers
void Question::displayAnswers() const
{
  for(int i = 0; i < 4; i++)
    cout << "(" << i+1 << ") " << answers[i] << endl;
};

// Print the correct answer for the question
void Question::displayCorrectAnswer() const
{
  cout << "      The correct answer was: " << this->answers[answer_index] << endl << endl << endl;
}

// Takes in an int for choice input and checks whether if it was the correct choice
//  Prints messages corresponding to correct or incorrect choice.
int Question::checkAnswer(int choice) const
{
  if(answer_index == choice-1) {
    cout << endl << "Congratulations!" << endl << endl << endl;
    return 0;
  }
  else {
    cout << endl << "Sorry" << endl;
    this->displayCorrectAnswer();
    return 1;
  }
}

// Function that randomizes the answers
void Question::randomizeAnswers() {
  string temp;
  int j;
  for (int i = 3; i > 0; i--) {
    j = rand() % (i+1);
    if(i == answer_index || j == answer_index) {
      if(i == answer_index) 
        answer_index = j;
      else 
        answer_index = i;
    }
    temp = answers[i];
    answers[i] = answers[j];
    answers[j] = temp;
  }
}
