#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the secret number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess < secretNumber)
            cout << "Too low! Try again." << endl;
        else if (guess > secretNumber)
            cout << "Too high! Try again." << endl;
        else
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;

    } while (guess != secretNumber);

    return 0;
}
