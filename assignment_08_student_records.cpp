// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// =============================================================================
// STRUCT: Student
// PURPOSE: Represents a student record with name, ID, and scores
// =============================================================================
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// =============================================================================
// FUNCTION: displayMenu
// PURPOSE: Displays the menu options
// RETURNS: void
// =============================================================================
void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

// =============================================================================
// FUNCTION: addStudent
// PURPOSE: Adds a new student record to the system
// PARAMETERS: vector<Student> &students — reference to student list
// RETURNS: void
// =============================================================================
void addStudent(vector<Student> &students) {
    Student newStudent;
    
    cout << "\nStudent name: ";
    cin.ignore();  // Clear newline from input buffer
    getline(cin, newStudent.name);
    
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    int numScores;
    cout << "How many scores? ";
    cin >> numScores;
    
    if (numScores <= 0) {
        cout << "Error: Number of scores must be positive." << endl;
        return;
    }
    
    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }
    
    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// =============================================================================
// FUNCTION: calculateAverageScore
// PURPOSE: Calculates the average of a student's scores
// PARAMETERS: vector<double> scores — list of scores
// RETURNS: double — the average score
// =============================================================================
double calculateAverageScore(vector<double> scores) {
    if (scores.empty()) {
        return 0.0;
    }
    
    double sum = 0;
    for (double score : scores) {
        sum += score;
    }
    
    return sum / scores.size();
}

// =============================================================================
// FUNCTION: displayAllStudents
// PURPOSE: Displays all students in a formatted table
// PARAMETERS: vector<Student> &students — reference to student list
// RETURNS: void
// =============================================================================
void displayAllStudents(vector<Student> &students) {
    if (students.empty()) {
        cout << "\nNo students in the system yet." << endl;
        return;
    }
    
    cout << "\n" << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << "Average" << endl;
    cout << string(80, '-') << endl;
    
    for (const Student &student : students) {
        cout << left << setw(20) << student.name
             << setw(12) << student.id;
        
        // Print all scores
        for (int i = 0; i < student.scores.size(); i++) {
            if (i > 0) cout << ", ";
            cout << student.scores[i];
        }
        
        // Print average
        double avg = calculateAverageScore(student.scores);
        cout << setw(20 - (student.scores.size() > 0 ? 5 : 0)) << " ";
        cout << fixed << setprecision(2) << avg << endl;
    }
}

// =============================================================================
// FUNCTION: findStudentById
// PURPOSE: Finds a student by ID and prints their average score
// PARAMETERS: vector<Student> &students — reference to student list
// RETURNS: void
// =============================================================================
void findStudentById(vector<Student> &students) {
    if (students.empty()) {
        cout << "\nNo students in the system yet." << endl;
        return;
    }
    
    int searchId;
    cout << "\nEnter student ID: ";
    cin >> searchId;
    
    for (const Student &student : students) {
        if (student.id == searchId) {
            double avg = calculateAverageScore(student.scores);
            cout << student.name << "'s average score: " 
                 << fixed << setprecision(2) << avg << endl;
            return;
        }
    }
    
    // Student not found
    cout << "Error: Student with ID " << searchId << " not found." << endl;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    vector<Student> students;  // Store all student records
    int choice;
    
    cout << "================================\n";
    cout << "Welcome to Student Record System\n";
    cout << "================================" << endl;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                findStudentById(students);
                break;
            case 4:
                cout << "\nGoodbye!" << endl;
                return 0;  // Exit program
            default:
                cout << "Error: Invalid choice. Please enter 1, 2, 3, or 4." << endl;
        }
    }
    
    return 0;
}

