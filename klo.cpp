#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GuessingGame {
private:
    int targetNumber;
    vector<int> guessHistory;

    int generateRandomNumber(int lower, int upper) {
        return lower + rand() % (upper - lower + 1);
    }

    bool isRepeatedGuess(int guess) {
        
        return find(guessHistory.begin(), guessHistory.end(), guess) != guessHistory.end();
    }

public:
    GuessingGame(int lower, int upper) {
        targetNumber = generateRandomNumber(lower, upper);
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "A number has been generated between " << lower << " and " << upper << "!" << endl;
    }

    void play() {
        int guess;
        while (true) {
            cout << "Enter your guess: ";
            cin >> guess;

            
            if (isRepeatedGuess(guess)) {
                cout << "You've already guessed " << guess << "! Try a different number." << endl;
                continue;
            }

            
            guessHistory.push_back(guess);

            
            if (guess == targetNumber) {
                cout << "Congratulations! You've guessed the correct number: " << targetNumber << endl;
                break;
            } else if (guess < targetNumber) {
                cout << "Your guess is too low. Try again!" << endl;
            } else {
                cout << "Your guess is too high. Try again!" << endl;
            }
        }
    }

    void displayHistory() const {
        cout << "Your guesses: ";
        for (size_t i = 0; i < guessHistory.size(); ++i) {
        cout << guessHistory[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int lower = 1, upper = 100;
    GuessingGame game(lower, upper);
    game.play();

    game.displayHistory();

    return 0;
}

