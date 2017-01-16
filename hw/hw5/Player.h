#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>

using namespace std;

class Player {
	public:
		Player();								// Default constructor
		~Player() {};							// Default destructor
        Player(string n, string pw);			// Custom constructor
		Player &operator=(const Player &qp);	// Assignment operator

		int numCorrect() const;						// Returns the number of correct guesses for a player
        void incCorrectGuesses();				// Increments the correctGuesses variable
        string getName() const;   					// Returns the name of the player
        bool playAgain();
	private:
		string name;			// Variable for name
		string password;		// Variable for the password
		int correctGuesses;		// Variable for number of correct guesses
};

#endif