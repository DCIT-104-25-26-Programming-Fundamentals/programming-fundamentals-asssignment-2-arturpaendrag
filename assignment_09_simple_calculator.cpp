// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// =============================================================================
// FUNCTION: displayMenu
// PURPOSE: Displays the calculator menu
// RETURNS: void
// =============================================================================
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// =============================================================================
// FUNCTION: add
// PURPOSE: Adds two numbers
// PARAMETERS: double num1, double num2
// RETURNS: double — sum of num1 and num2
// =============================================================================
double add(double num1, double num2) {
    return num1 + num2;
}

// =============================================================================
// FUNCTION: subtract
// PURPOSE: Subtracts two numbers
// PARAMETERS: double num1, double num2
// RETURNS: double — difference of num1 and num2
// =============================================================================
double subtract(double num1, double num2) {
    return num1 - num2;
}

// =============================================================================
// FUNCTION: multiply
// PURPOSE: Multiplies two numbers
// PARAMETERS: double num1, double num2
// RETURNS: double — product of num1 and num2
// =============================================================================
double multiply(double num1, double num2) {
    return num1 * num2;
}

// =============================================================================
// FUNCTION: divide
// PURPOSE: Divides two numbers (with zero check)
// PARAMETERS: double num1, double num2
// RETURNS: double — quotient of num1 and num2, or -1 if error
// =============================================================================
double divide(double num1, double num2) {
    if (num2 == 0) {
        return -1;  // Return -1 to indicate error
    }
    return num1 / num2;
}

// =============================================================================
// FUNCTION: modulus
// PURPOSE: Calculates remainder of division (integers only)
// PARAMETERS: int num1, int num2
// RETURNS: int — remainder of num1 divided by num2
// =============================================================================
int modulus(int num1, int num2) {
    if (num2 == 0) {
        return -1;  // Return -1 to indicate error
    }
    return num1 % num2;
}

// =============================================================================
// FUNCTION: exponentiate
// PURPOSE: Raises base to the power of exponent
// PARAMETERS: double base, int exponent
// RETURNS: double — base raised to exponent power
// =============================================================================
double exponentiate(double base, int exponent) {
    return pow(base, exponent);
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int choice;
    double num1, num2, result;
    int intNum1, intNum2;
    
    cout << "===========================\n";
    cout << "Welcome to Calculator\n";
    cout << "============================" << endl;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:  // Addition
                cout << "Enter first number : ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = add(num1, num2);
                cout << "Result: " << fixed << setprecision(2)
                     << num1 << " + " << num2 << " = " << result << endl;
                break;
                
            case 2:  // Subtraction
                cout << "Enter first number : ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = subtract(num1, num2);
                cout << "Result: " << fixed << setprecision(2)
                     << num1 << " - " << num2 << " = " << result << endl;
                break;
                
            case 3:  // Multiplication
                cout << "Enter first number : ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                result = multiply(num1, num2);
                cout << "Result: " << fixed << setprecision(2)
                     << num1 << " * " << num2 << " = " << result << endl;
                break;
                
            case 4:  // Division
                cout << "Enter first number : ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                } else {
                    result = divide(num1, num2);
                    cout << "Result: " << fixed << setprecision(2)
                         << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
                
            case 5:  // Modulus
                cout << "Enter first number : ";
                cin >> intNum1;
                cout << "Enter second number: ";
                cin >> intNum2;
                if (intNum2 == 0) {
                    cout << "Error: Cannot perform modulus with zero." << endl;
                } else {
                    int modResult = modulus(intNum1, intNum2);
                    cout << "Result: " << intNum1 << " % " << intNum2
                         << " = " << modResult << endl;
                }
                break;
                
            case 6:  // Exponentiation
                cout << "Enter base: ";
                cin >> num1;
                cout << "Enter exponent: ";
                cin >> intNum1;
                result = exponentiate(num1, intNum1);
                cout << "Result: " << fixed << setprecision(2)
                     << num1 << " ^ " << intNum1 << " = " << result << endl;
                break;
                
            case 7:  // Quit
                cout << "\nGoodbye!" << endl;
                return 0;
                
            default:
                cout << "Error: Invalid choice. Please enter 1-7." << endl;
        }
    }
    
    return 0;
}

