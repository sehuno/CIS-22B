#include "Player.cpp"
#include "Question.cpp"
#include <fstream>
#include <time.h> 
#include <stdlib.h>


// Function prototypes
Question *readInFile(string fName, int &qNum);
void getPlayers(Player [], Player [], int &);
void swapQuestion(Question *q1, Question *q2);
void randomizeQuestions(Question *, int);
void playGame(Question *, Player []);
void displayWinner(Player currentPlayers[]);
void writeToFile(string fName, Player players[], int num_players);

int main() {

    string fileName;
    int num_questions;          // Number of questions read in
    int num_players = 0;        // Number of players
    char input;                 // Input char for playing again
    Question *questions;        // A pointer to array question objects
    Player players[50];         // Array of player objects
    Player currentPlayers[2];   // Array of player objects that are playing the game
    
    // Prompt user for the filepath
    cout << "Please enter the filepath to the TriviaQuestions.txt file" << endl;
    getline(cin,fileName);

    // Read in file and store number of questions and returns a pointer to the array of Questions
    questions = readInFile(fileName, num_questions);

    do {
        // Initialized random number for rand function
        srand((unsigned)time(NULL));

        // Randomize questions array
        randomizeQuestions(questions, num_questions);
        
        // Randomize answers
        for(int i = 0; i < num_questions; i++) 
            questions[i].randomizeAnswers();
        
        // Get player information and add players
        getPlayers(players, currentPlayers, num_players);
        
        // Play game
        playGame(questions, currentPlayers);
        
        // Display winnner
        displayWinner(currentPlayers);

        // Ask if players would like to play again 
        cout << "Would you like to play again? Enter Y to play again or N to quit: ";
        cin >> input;
        while(cin.fail()) {     // Input validation
            cin.clear();
            cin.ignore(1,'\n');
            cin >> input;
            cout << "Please enter a valid choice:";
        }
    } while(toupper(input) == 'Y'); 

    // Write name of players to output file.
    writeToFile(fileName, players, num_players);

    // for(int i = 0; i < num_questions; i++)
        delete [] questions;
}


/* FUNCTIONS */

/* The readInFile function take in a string for the filename, a reference to the number of questions
and reads in the input file, reading in each line and returning a pointer to the array of question objects */
Question *readInFile(string fName, int &qNum) {
    string ques, empty, num;    // String variables for the question, empty line, and number of questions
    string temp_ans[4];         // String array for answers.
    
    Question *questions;        // Pointer to array of question objects
        
    ifstream inputFile;
    inputFile.open(fName);      // Open input file
    
    if(!inputFile.good())
        cout << "Error occured when opening input file!" << endl;       // If error opening file, output error message.
    else {
        
        while(inputFile.good()) {
            while(!inputFile.eof()) {           
                getline(inputFile, num);                        // Read in first line to get number of questions
                qNum = atoi(num.c_str());                       // Convert string to int
                questions = new Question[qNum];                 // Dynamically allocate question objects
                    
                for(int i = 0; i < qNum; i++) {                 
                    getline(inputFile,ques);                    // Get the question, which is the first line of each block
                    
                    for(int j = 0; j < 4; j++)                  // Get the next four lines, which are the answers to questions
                        getline(inputFile, temp_ans[j]);
                    getline(inputFile,empty);                   // Read in empty line
                    
                    questions[i] = Question(ques, temp_ans);    // Set question in question array to newly declared question object
                }
            }
            inputFile.close();                                  // Close input file
        }
    }
    return questions;                                           // Return pointer to question array
}


/* The getPlayers function takes in an array of Player objects for all and currently playing players and a reference to the number 
of players. The function prompts the players for their names and passwords, creates Player objects and stores them into the corresponding
Player arrays. When it is run the first time, the two players are added into the Player array of all players, and sets the two players 
as currently playing the game. For every consequent time that it is run, it asks the two last players to have played if they would
like to play again. Otherwise, it prompts for new players.
*/
void getPlayers(Player players[], Player currentPlayers[], int &num_players) {
    string p1name, p2name;
    string p1pw, p2pw;
    
    if(num_players == 0) {                              // When no players have been encounteredyet
        cout << "Enter Player 1 Name: ";                //   Get player 1 info
        getline(cin, p1name);

        cout << "Player 1 Password: ";                
        getline(cin, p1pw);
        
        players[num_players] = Player(p1name,p1pw);     //  "Create player object with name and passwords
        currentPlayers[0] = players[num_players];       //  Set player as current player
        num_players++;                                  //  Increment number of players"
        cout << endl;
        
        cout << "Enter Player 2 Name: ";                //  Get player 2 info
        getline(cin, p2name);                           //
        cout << "Player 2 Password: ";                  //
        getline(cin, p2pw);
        
        players[num_players] = Player(p2name,p2pw);     // " "
        currentPlayers[1] = players[num_players];       //
        num_players++;                                  // 
        cout << endl;
        
    } else {                                            // For subsequent calls of the getPlayers function,
        int neededPlayers = 2;  

        for(int i = 0; i < 2; i++) {                    // Ask current players if they would like to play agin
            cout << endl << "Would Player " << i+1 << " like to play again? ";
            if(currentPlayers[i].playAgain()) 
                neededPlayers--;
            else
                currentPlayers[i] = Player();
        }

        for(int j = 0; j < 2; j++) {                    // For the number of needed players (based on how many players are playing again)
            string new_name;                            //   Get their information and add to new players and current players array
            string new_pw;
           
            if(currentPlayers[j].getName() == "") {     
               
                cout << "Enter new Player Name: ";
                cin.ignore(1,'\n');
                getline(cin, new_name);
                cout << "New Player Password: ";
                getline(cin, new_pw);

                players[num_players] = Player(new_name,new_pw);
                currentPlayers[j] = players[num_players];
                num_players++;
                cout << endl;
            } 
        }
    }
}


/* The randomizeQuestions takes in the point to questions array 
and the number of questions and randomizes the questions array. */
void randomizeQuestions(Question *questions, int num_questions) {
    for (int i = num_questions-1; i > 0; i--) {
        int j = rand() % (i+1);
        swapQuestion(&questions[i], &questions[j]);
    }
}

/* The swapQuestion function takes two pointers to questions and swaps them. */
void swapQuestion(Question *q1, Question *q2) {
    Question temp;
    temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}


/* The playGame function takes in a pointer to array of Questions and the array of players and allows the players 
to play the game. It displays 3 questions for each player but in corresponding order. It then checks the players
input to check if it was the correct answer. If it was correct, it increments the number of correct guesses the 
player has and prints Congratulations. If invalid, it displays the correct answer and prints a message saying sorry.*/
void playGame(Question *questions, Player currentPlayers[]) {
    int input;
    Player *currPlayer;
    for(int i = 0; i < 6; i++) {            // For each of the 6 questions,
        if(i % 2 == 0)
            currPlayer = &currentPlayers[0];
        else
            currPlayer = &currentPlayers[1];
        
        cout << "Question " << i+1 << " - " << "Player " << (i%2)+1 << ": " << currPlayer->getName() << endl << endl;
        questions[i].displayQuestion();     // Display question
        questions[i].displayAnswers();      // Display answers
        cout << "Answer: ";     
        cin >> input;                                       // Get user choice
        while(cin.fail() || input > 4 || input < 1) {       // Perform input validation
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid number for the choice: ";
            cin >> input;
        }
        if(questions[i].checkAnswer(input) == 0)            // Check if answer was correct and increment number of correct guesses
            currPlayer->incCorrectGuesses();
    }
}

/* The displayWinner function takes in an array of players that are currently playing the game. It compares the 
number of correct guesses by each player and display a message about which player won the game */
void displayWinner(Player currentPlayers[]) {
    cout << "Player 1: " << currentPlayers[0].numCorrect() << " correct answer(s)" << endl;
    cout << "Player 2: " << currentPlayers[1].numCorrect() << " correct answer(s)" << endl << endl;
    if(currentPlayers[0].numCorrect() == currentPlayers[1].numCorrect()) 
        cout << "Player 1 and Player 2 tied, both answering " << currentPlayers[0].numCorrect() << " question(s) correctly!" << endl << endl;
    else if(currentPlayers[0].numCorrect() > currentPlayers[1].numCorrect()) 
        cout << "Player 1, " << currentPlayers->getName() << ", won!" << endl << endl;
    else
        cout << "Player 2, " << currentPlayers->getName() << ", won!" << endl << endl;
}

/* The writeToFile function takes in the file name, the array of players, and the number of players and 
write the names of each player that played the game to an output file. */
void writeToFile(string fName, Player players[], int num_players) {
    ofstream outputFile;
    outputFile.open("output_"+fName);
    for(int i = 0; i < num_players; i++)                    // For each player that played the game, print name to output file.
        outputFile << players[i].getName() << "\n";
    cout << endl << "Names of players that participiated in the game were printed to output file." << endl;
}

/* OUTPUT

Please enter the filepath to the TriviaQuestions.txt file
/Users/sehun/Documents/22b/hw/hw5/TriviaQuestions.txt
Enter Player 1 Name: eric
Player 1 Password: eric

Enter Player 2 Name: jake
Player 2 Password: jake

Question 1 - Player 1: eric

For a UML Class diagram, what are the three sections?
(1) Function name, Data type, Function Parameter
(2) Default Constructor, User-Defined Constructor, Destructor
(3) Private variables, Public Variables, Protected Variables
(4) Class name, Member variables, Member functions
Answer: 3

Sorry
      The correct answer was: Class name, Member variables, Member functions


Question 2 - Player 2: jake

Encapsulation refers to
(1) Storing data into an object
(2) Protecting data
(3) Combining data and code into a single object 
(4) Creating functions for an object
Answer: 2

Sorry
      The correct answer was: Combining data and code into a single object 


Question 3 - Player 1: eric

Which method is correct when defining const member functions?
(1) double const getWidth();
(2) double getWidth() const;
(3) double getWidth(const);
(4) const double getWidth();
Answer: 4

Sorry
      The correct answer was: double getWidth() const;


Question 4 - Player 2: jake

An object is not a class, but it is
(1) A description of a class
(2) Code that specifies the functions that a class may have
(3) Code that specifies the attributes that a class may have 
(4) An instance of a class
Answer: 5
Please enter a valid number for the choice: 2

Sorry
      The correct answer was: An instance of a class


Question 5 - Player 1: eric

The operator that identifies the function as a member of a class is 
(1) ::
(2) :
(3) ->
(4) .
Answer: 1

Congratulations!


Question 6 - Player 2: jake

Which of the following is true about class constructors?
(1) A default constructor is a constructor that takes no parameters
(2) Constructors are not necessary for classes
(3) A class cannot have more than one constructors
(4) Constructors may have different names as their class
Answer: 3

Sorry
      The correct answer was: A default constructor is a constructor that takes no parameters


Player 1: 1 correct answer(s)
Player 2: 0 correct answer(s)

Player 1, eric, won!

Would you like to play again? Enter Y to play again or N to quit: y

Would Player 1 like to play again? Please enter your password to play again: eric
Password accepted. Have fun playing again!


Would Player 2 like to play again? Please enter your password to play again: fake
Password incorrect. How about letting someone else try? See you again soon!

Enter new Player Name: take
New Player Password: take

Question 1 - Player 1: eric

The operator that identifies the function as a member of a class is 
(1) .
(2) ->
(3) ::
(4) :
Answer: 2

Sorry
      The correct answer was: ::


Question 2 - Player 2: take

Encapsulation refers to
(1) Creating functions for an object
(2) Storing data into an object
(3) Protecting data
(4) Combining data and code into a single object 
Answer: 3

Sorry
      The correct answer was: Combining data and code into a single object 


Question 3 - Player 1: eric

Which of the following is an definition of an instance of a class?
(1) Rectangle::Rectangle() {};
(2) ~Rectangle();
(3) Rectangle(int width, int length) {};
(4) Rectangle r;
Answer: 4

Congratulations!


Question 4 - Player 2: take

An object is, conceptually, a self-contained unit consisting of 
(1) Attributes(data) and procedures(functions)
(2) Attributes
(3) Procedures
(4) Data
Answer: 1

Congratulations!


Question 5 - Player 1: eric

Data hiding refers to an object’s ability to
(1) Hide its procedures
(2) Hide its data
(3) Hide its data from code that is outside the object 
(4) Hide its data from code that is inside the object 
Answer: 3

Congratulations!


Question 6 - Player 2: take

Which method is correct when defining const member functions?
(1) double getWidth() const;
(2) double getWidth(const);
(3) const double getWidth();
(4) double const getWidth();
Answer: 4

Sorry
      The correct answer was: double getWidth() const;


Player 1: 2 correct answer(s)
Player 2: 1 correct answer(s)

Player 1, eric, won!

Would you like to play again? Enter Y to play again or N to quit: n

Names of players that participiated in the game were printed to output file.

*/
