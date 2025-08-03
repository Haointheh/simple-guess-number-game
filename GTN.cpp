#include <iostream>
#include <string>
#include <cstdlib>  // Include this header for random number generation
#include <ctime>
using namespace std;

const int maxTries = 5;  // Use a named constant for maximum tries

char playername[50];

void displayOutcome(int randomnum) {
    if (randomnum == -1) {
        cout << "\n  ..................................................................\n";
        cout << "\n  .                         YOU LOST                               .\n";
        cout << "\n  .            Sorry, but you ran out of tries.                   .\n";
    } else {
        cout << "\n  ..................................................................\n";
        cout << "\n                              YOU WON                               \n";
        cout << "\n      Congratulations " << playername << ". You guessed it right       \n";
    }
    cout << "\n                   Returning back to the main menu..                \n";
    cout << "\n  ..................................................................\n";
}

int getPlayerGuess() {
    int guess;
    cout << "\nEnter your guess: ";
    cin >> guess;
    return guess;
}

void gamestart() {
    int range;
    cout << "\n\n              GAME START   " << endl;
    cout << "          Enter your choice of range: ";
    cin >> range;
    cout << "                Range chosen " << range << endl;

    int randomnum = rand() % range;
    cout << "(" << randomnum << ")" << endl;

    cout << "\n     Guess the number between 0 to " << range - 1 << endl;
    cout << "        You have " << maxTries << " tries. Good luck!" << endl;

    int tries = maxTries;
    int guess = -1;  // Initialize guess to a value outside the valid range

    while (tries != 0 && guess != randomnum) {
        guess = getPlayerGuess();
        tries--;

        if (guess < randomnum) {
            cout << "  (Your guess is too low), no. of tries left: " << tries << endl;
        } else if (guess > randomnum) {
            cout << "  (Your guess is too high), no. of tries left: " << tries << endl;
        }
    }

    displayOutcome(guess);
}

void displayWelcomeMessage() {
    cout << ".........................................................................................\n";
    cout << "  .....................................................................................\n";
    cout << "                                                                         \n";
    cout << "                        WELCOME TO THE GUESSING GAME                        \n";
    cout << "                         ------------------------                             \n";
    cout << "                                                                         \n";
    // Display rules and other messages...

    cout << "                                                                         \n";
    cout << "                     ~~press any key to start the game~~                \n";
    cout << "                                                                 \n";
    cout << "  .....................................................................................\n";
    cout << ".........................................................................................\n";
}

int main() {
    displayWelcomeMessage();

    cout << "Enter player name: ";
    cin >> playername;

    srand(time(NULL));

    int ch;
    do {
        cout << "\n\n\n  ..Main Menu.." << endl;
        cout << "1. Play game\n";
        cout << "0. Exit" << endl;
        cout << "\n Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 0:
                cout << "\n Exiting the game" << endl;
                break;

            case 1:
                gamestart();
                break;

            default:
                cout << "Please enter a valid choice";
        }
    } while (ch != 0);

    return 0;
}
