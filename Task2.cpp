#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

void displayMenu() {
    cout << "===================" << endl;
    cout << "  Digital Calculator" << endl;
    cout << "===================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Power" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an operation: ";
}

bool isValidNumber(double& number) {
    if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        return false;
    }
    return true;
}

double getNumberInput(const string& prompt) {
    double num;
    cout << prompt;
    cin >> num;
    while (!isValidNumber(num)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin >> num;
    }
    return num;
}

int main() {
    cout<<"Task-2:DIGITAL CALCULATOR"<<endl<<"Made by Ashish"<<endl;
    int choice;
    double num1, num2, result;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }

        num1 = getNumberInput("Enter first number: ");
        num2 = getNumberInput("Enter second number: ");

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;
            case 5:
                if (floor(num1) != num1 || floor(num2) != num2) {
                    cout << "Error: Modulus operation requires integer operands." << endl;
                } else {
                    result = static_cast<int>(num1) % static_cast<int>(num2);
                    cout << "Result: " << result << endl;
                }
                break;
            case 6:
                result = pow(num1, num2);
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid operation." << endl;
                break;
        }
    }

    return 0;
}
