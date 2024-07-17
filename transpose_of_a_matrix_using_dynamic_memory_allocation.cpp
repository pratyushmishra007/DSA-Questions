__Transpose of a Matrix using dynamic memory allocation__
Problem statement
Write a program to take a matrix of size m*n as the input from the user and print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i]. Use dynamic memory allocation to create the 2D arrays.

For example:
Let matrix be : 
1 2
3 4

Then transpose of the matrix will be: 
1 3
2 4

Solution Approach
Input Handling: Read the number of test cases. For each test case, read the dimensions of the matrix (m and n) and then read the elements into a dynamically allocated 2D array.
Transposition: Iterate through the matrix and print the elements in transposed order, where the first row becomes the first column, the second row becomes the second column, and so on.
Memory Management: Properly allocate and deallocate memory to avoid memory leaks.

--------------------------
code
--------------------------
#include <iostream>
using namespace std;

int main() {
    int *t = new int; // Allocate memory for number of test cases
    cin >> *t; // Read number of test cases
    while ((*t)-- > 0) {  
        int *m = new int; // Allocate memory for rows
        int *n = new int; // Allocate memory for columns
        cin >> *m >> *n; // Read dimensions

        // Allocate memory for a 2D array (matrix)
        int **p = new int*[*m];
        for (int i = 0; i < *m; ++i) {
            p[i] = new int[*n]; // Allocate each row
            for (int j = 0; j < *n; ++j) {
                cin >> p[i][j]; // Read each element
            }
        }

        // Print the transposed matrix
        for (int i = 0; i < *n; ++i) { // Iterate over columns for transposition
            for (int j = 0; j < *m; ++j) { // Iterate over rows
                cout << p[j][i] << " "; // Access transposed elements
            }
            cout << endl; // New line after each row
        }

        // Deallocate memory for the 2D array
        for (int i = 0; i < *m; ++i) {
            delete[] p[i]; // Free each row
        }
        delete[] p; // Free the array of pointers
        delete m; // Free memory for dimensions
        delete n; // Free memory for dimensions
    }
    delete t; // Free allocated memory for test cases
    return 0; // Indicate successful completion
}
