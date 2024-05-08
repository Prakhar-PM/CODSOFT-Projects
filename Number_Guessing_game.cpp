#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <limits>  

using namespace std;

int main() {
    int sp, number_range, real_number, guess_number, guess_count = 0;
    srand(time(0)); 
    start:
    cout << "----------------------------------------------" << endl;
    cout << "------------- WELCOME TO THE GAME ------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Choose your option:" << endl;
    cout << "1. Play the game" << endl;
    cout << "2. See the last game score" << endl;
    cout << "3. Exit from the game" << endl;
    cout << "Enter Your Option: ";
    cin >> sp;

    switch (sp) {
        case 1:
            cout << "\nLet's Start the Game...\n" << endl;
            goto play;
            break;
        case 2:
            if (guess_count == 0) {
                cout << "\nYou haven't played the game yet.\n" << endl;
            } else if (guess_count == 1) {
                cout << "\nIn the last game, you won the game in " << guess_count << "st try.\n" << endl;
            } else {
                cout << "\nIn the last game, you won the game in " << guess_count << " tries.\n" << endl;
            }
            goto start;
            break;
        case 3:
            cout << "\nThanks for Playing the Game!\n" << endl;
            return 0;
            break;
        default:
            cout << "\nInvalid Option Choice. Please Try Again.\n" << endl;
            goto start;
            break;
    }

    play:
    guess_count = 1;
    cout << "\nEnter the range of the number: ";
    cin >> number_range;

    // Input validation
    while (cin.fail() || number_range <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> number_range;
    }

    real_number = rand() % number_range;

    do {
        cout << "\nEnter your guess number: ";
        cin >> guess_number;

        
        while (cin.fail()) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> guess_number;
        }

        if (guess_number > real_number) {
            guess_count++;
            cout << "The number is lower than you guessed." << endl;
        } else if (guess_number < real_number) {
            guess_count++;
            cout << "The number is higher than you guessed." << endl;
        } else {
            cout << "\nGreat! You guessed the correct number!" << endl;
            if (guess_count == 1) {
                cout << "You guessed the number in " << guess_count << "st try!" << endl;
            } else {
                cout << "You guessed the number in " << guess_count << " tries!" << endl;
            }
            goto start;
        }
    } while (guess_number != real_number);

    return 0;
}
