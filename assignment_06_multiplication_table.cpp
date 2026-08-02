// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

// =============================================================================
// PART A — PRINT MULTIPLICATION TABLE FOR A SINGLE NUMBER
// =============================================================================
void printSingleTable(int num) {
    // Validate input
    if (num <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }
    
    cout << "Multiplication Table for " << num << ":" << endl;
    
    for (int i = 1; i <= 12; i++) {
        cout << setw(2) << num << "  x  " << setw(2) << i << "  =  " 
             << setw(3) << (num * i) << endl;
    }
}

// =============================================================================
// PART B — PRINT MULTIPLICATION TABLES FROM 1 TO N
// =============================================================================
void printMultipleTables(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }
    
    for (int num = 1; num <= n; num++) {
        cout << "Multiplication Table for " << num << ":" << endl;
        
        for (int i = 1; i <= 12; i++) {
            cout << setw(2) << num << "  x  " << setw(2) << i << "  =  " 
                 << setw(3) << (num * i) << endl;
        }
        
        // Print separator line between tables (except after the last one)
        if (num < n) {
            cout << "---------------------------" << endl;
        }
    }
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int choice;
    
    cout << "========== Multiplication Table Generator ==========" << endl;
    cout << "1. Print single multiplication table" << endl;
    cout << "2. Print tables from 1 to N" << endl;
    cout << "Choose operation (1-2): ";
    cin >> choice;
    cout << endl;
    
    if (choice == 1) {
        // PART A: Single Table
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;
        
        printSingleTable(num);
        
    } else if (choice == 2) {
        // PART B: Multiple Tables
        int n;
        cout << "Enter N (print tables 1 to N): ";
        cin >> n;
        cout << endl;
        
        printMultipleTables(n);
        
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}
