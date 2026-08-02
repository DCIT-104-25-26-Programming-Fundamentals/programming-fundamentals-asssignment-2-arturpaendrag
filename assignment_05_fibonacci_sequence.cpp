// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>

using namespace std;

// =============================================================================
// PART A — PRINT THE FIRST N TERMS OF FIBONACCI SEQUENCE
// =============================================================================
void printFibonacciSequence(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    // Handle first two terms separately
    if (n >= 1) {
        cout << "Fibonacci sequence: 0";
    }
    if (n >= 2) {
        cout << " 1";
    }
    
    // Generate and print remaining terms
    if (n > 2) {
        long long prev = 0;      // First Fibonacci number
        long long current = 1;   // Second Fibonacci number
        
        for (int i = 2; i < n; i++) {
            long long next = prev + current;
            cout << " " << next;
            prev = current;
            current = next;
        }
    }
    
    cout << endl;
}

// =============================================================================
// PART B — CHECK IF A NUMBER IS A FIBONACCI NUMBER
// =============================================================================
bool isFibonacciNumber(long long num) {
    // Handle negative numbers
    if (num < 0) {
        return false;
    }
    
    // Check for 0 and 1 (special cases)
    if (num == 0 || num == 1) {
        return true;
    }
    
    // Generate Fibonacci numbers until we reach or exceed the target number
    long long prev = 0;
    long long current = 1;
    
    while (current < num) {
        long long next = prev + current;
        prev = current;
        current = next;
    }
    
    // If current equals num, we found it
    return current == num;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int choice;
    
    cout << "========== Fibonacci Sequence Generator ==========" << endl;
    cout << "1. Print the first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Choose operation (1-2): ";
    cin >> choice;
    cout << endl;
    
    if (choice == 1) {
        // PART A: Print first N terms
        int n;
        cout << "How many terms? ";
        cin >> n;
        
        printFibonacciSequence(n);
        
    } else if (choice == 2) {
        // PART B: Check if number is Fibonacci
        long long num;
        cout << "Enter a number to check: ";
        cin >> num;
        
        if (isFibonacciNumber(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }
        
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}

