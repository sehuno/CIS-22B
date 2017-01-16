#include "Player.h"

// Default constructor for player
Player::Player() 
{ 
  name = "";
  correctGuesses = 0;
};

// Custom constructor for player, taking the name and password for a player
Player::Player(string n, string pw)
{
    name = n;
    password = pw;
    correctGuesses = 0;
};

// Assignment operator for the class Player
Player &Player::operator=(const Player &p)
{
   // Chek for self assignment
   if(this != &p) {
      this->name = p.name;
      this->password = p.password;
   }
   return *this;
};

// Increments the number of correct guesses for the player
void Player::incCorrectGuesses()
{
    correctGuesses++;
};

// Allows the player to play the game again when password input is correct.
//  When password is correct, resets the number of correct guesses.
bool Player::playAgain()
{
    string pw;
    cout << "Please enter your password to play again: ";
    cin >> pw;
    while(cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Please enter a valid string for your password: ";
    }

    if(pw == password) {
      cout << "Password accepted. Have fun playing again!" << endl << endl;
      correctGuesses = 0;
      return true;
    }
    else {
      cout << "Password incorrect. How about letting someone else try? See you again soon!" << endl << endl;
      correctGuesses = 0;
      password = "";
      name = "";
      return false;
    }
}

// Getter function for number of correct guesses
int Player::numCorrect() const
{
    return correctGuesses;
}

// Getter function for the name of the player
string Player::getName() const
{
    return name;
};
