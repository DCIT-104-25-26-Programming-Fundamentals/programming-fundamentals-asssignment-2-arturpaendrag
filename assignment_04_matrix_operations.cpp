// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>

#include <string>

using namespace std;

const int MAX_SIZE = 10;

// =============================================================================
// FUNCTION: readMatrix
// PURPOSE: Reads a matrix from the user
// PARAMETERS: int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols
// RETURNS: void (modifies matrix and row/col references)
// =============================================================================
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// =============================================================================
// FUNCTION: displayMatrix
// PURPOSE: Displays a matrix in a formatted grid
// PARAMETERS: int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols
// RETURNS: void
// =============================================================================
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// =============================================================================
// PART A — TRANSPOSE A MATRIX
// =============================================================================
void transposeMatrix(int original[MAX_SIZE][MAX_SIZE], 
                     int transposed[MAX_SIZE][MAX_SIZE],
                     int rows, int cols) {
    // Transpose: element at [i][j] goes to [j][i]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = original[i][j];
        }
    }
}

// =============================================================================
// PART B — ADD TWO MATRICES
// =============================================================================
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE],
                 int matrixB[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE],
                 int rows, int cols) {
    // Element-wise addition: result[i][j] = A[i][j] + B[i][j]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// =============================================================================
// PART C — MULTIPLY TWO MATRICES
// =============================================================================
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE],
                      int matrixB[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE],
                      int rowsA, int colsA, int rowsB, int colsB) {
    // Matrix multiplication: A (rowsA x colsA) * B (rowsB x colsB)
    // Result is rowsA x colsB
    // Important: colsA must equal rowsB
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;  // Initialize result element
            // Dot product of row i from A with column j from B
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int choice;
    
    cout << "========== Matrix Operations ==========" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose operation (1-3): ";
    cin >> choice;
    cout << endl;
    
    if (choice == 1) {
        // PART A: Transpose
        cout << "--- TRANSPOSE MATRIX ---" << endl;
        cout << "Enter the matrix to transpose:" << endl;
        readMatrix(matrix1, rows1, cols1);
        
        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(matrix1, rows1, cols1);
        
        transposeMatrix(matrix1, result, rows1, cols1);
        
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, cols1, rows1);
        
    } else if (choice == 2) {
        // PART B: Add Two Matrices
        cout << "--- ADD TWO MATRICES ---" << endl;
        cout << "Enter the first matrix:" << endl;
        readMatrix(matrix1, rows1, cols1);
        
        cout << "\nEnter the second matrix (must be same size):" << endl;
        readMatrix(matrix2, rows2, cols2);
        
        // Validate dimensions match
        if (rows1 != rows2 || cols1 != cols2) {
            cout << "\nError: Matrices must have the same dimensions!" << endl;
            return 1;
        }
        
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        
        cout << "\nMatrix 1:" << endl;
        displayMatrix(matrix1, rows1, cols1);
        
        cout << "\nMatrix 2:" << endl;
        displayMatrix(matrix2, rows2, cols2);
        
        cout << "\nSum (Matrix 1 + Matrix 2):" << endl;
        displayMatrix(result, rows1, cols1);
        
    } else if (choice == 3) {
        // PART C: Multiply Two Matrices
        cout << "--- MULTIPLY TWO MATRICES ---" << endl;
        cout << "Enter Matrix A:" << endl;
        readMatrix(matrix1, rows1, cols1);
        
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(matrix2, rows2, cols2);
        
        // Validate dimensions: cols of A must equal rows of B
        if (cols1 != rows2) {
            cout << "\nError: Number of columns in A must equal number of rows in B!" << endl;
            cout << "(A is " << rows1 << "x" << cols1 << ", B is " << rows2 << "x" << cols2 << ")" << endl;
            return 1;
        }
        
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
        
        cout << "\nMatrix A (" << rows1 << "x" << cols1 << "):" << endl;
        displayMatrix(matrix1, rows1, cols1);
        
        cout << "\nMatrix B (" << rows2 << "x" << cols2 << "):" << endl;
        displayMatrix(matrix2, rows2, cols2);
        
        cout << "\nProduct (A x B) (" << rows1 << "x" << cols2 << "):" << endl;
        displayMatrix(result, rows1, cols2);
        
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}