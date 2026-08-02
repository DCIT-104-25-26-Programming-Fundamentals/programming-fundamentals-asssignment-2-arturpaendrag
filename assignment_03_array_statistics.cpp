// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// FUNCTION: calculateSum
// PURPOSE: Calculates the sum of all numbers in the array
// PARAMETERS: int arr[] — array of numbers, int n — array size
// RETURNS: int — the sum of all numbers
// =============================================================================
int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// =============================================================================
// FUNCTION: calculateAverage
// PURPOSE: Calculates the average of all numbers in the array
// PARAMETERS: int sum — sum of all numbers, int n — count of numbers
// RETURNS: double — the average value
// =============================================================================
double calculateAverage(int sum, int n) {
    return (double)sum / n;
}

// =============================================================================
// FUNCTION: findMaximum
// PURPOSE: Finds the maximum value in the array
// PARAMETERS: int arr[] — array of numbers, int n — array size
// RETURNS: int — the maximum value
// =============================================================================
int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// =============================================================================
// FUNCTION: findMinimum
// PURPOSE: Finds the minimum value in the array
// PARAMETERS: int arr[] — array of numbers, int n — array size
// RETURNS: int — the minimum value
// =============================================================================
int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int n;
    
    // Prompt user for the number of elements
    cout << "How many numbers? ";
    cin >> n;
    
    // Validate that n is positive
    if (n <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }
    
    // Create array to store numbers
    int arr[n];
    
    // Read numbers from user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    // Calculate statistics using functions
    int sum = calculateSum(arr, n);
    double average = calculateAverage(sum, n);
    int maximum = findMaximum(arr, n);
    int minimum = findMinimum(arr, n);
    
    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
    
    return 0;
}
