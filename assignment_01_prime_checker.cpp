// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <cmath>

using namespace std;

// =============================================================================
// FUNCTION: isPrime
// PURPOSE: Determines whether a given number is prime
// PARAMETERS: int num — the number to check
// RETURNS: bool — true if prime, false otherwise
// =============================================================================
bool isPrime(int num) {
    // Numbers less than 2 are not prime
    if (num < 2) {
        return false;
    }
    
    // 2 is prime
    if (num == 2) {
        return true;
    }
    
    // Even numbers (except 2) are not prime
    if (num % 2 == 0) {
        return false;
    }
    
    // Check for odd divisors up to sqrt(num)
    // If num has a divisor greater than sqrt(num),
    // it must also have a divisor smaller than sqrt(num)
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    // No divisors found, number is prime
    return true;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int number;
    
    // Prompt user for input
    cout << "Enter a number: ";
    cin >> number;
    
    // Call isPrime() and display result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}
