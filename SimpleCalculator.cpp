#include <iostream>
#include <cmath> // for pow()

using namespace std;

int main() {
    char continue_option;
    do {
        cout << "\n---------------------- WELCOME TO SIMPLE CALCULATOR ----------------------\n" << endl;
        int a, b;
        int operation;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        cout << "\n";
        cout << "Press 1 for Addition (+)" << endl;
        cout << "Press 2 for Subtraction (-)" << endl;
        cout << "Press 3 for Multiplication (*)" << endl;
        cout << "Press 4 for Division-Quotient (/)" << endl;
        cout << "Press 5 for Remainder (%)" << endl;
        cout << "Press 6 for Power (^)" << endl;
        cout << "\nSelect any Operation: ";
        cin >> operation;
        cout << "\nYour Answer is: ";

        switch (operation) {
            case 1:
                cout << (a + b) << endl;
                break;
            case 2:
                cout << (a - b) << endl;
                break;
            case 3:
                cout << (a * b) << endl;
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    cout << (a / b) << endl;
                }
                break;
            case 5:
                cout << (a % b) << endl;
                break;
            case 6:
                cout << pow(a, b) << endl;
                break;
            default:
                cout << "Operation not Found. Please Try Again." << endl;
                break;
        }

        cout << "\nDo you want to continue (y/n)? ";
        cin >> continue_option;
    } while (continue_option == 'y' || continue_option == 'Y');

    cout << "Thank You for using this Calculator!"<< endl;

    return 0;
}
