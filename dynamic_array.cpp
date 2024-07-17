//Implemented dynamic memory allocation using pointers on a basic problem 
Q)Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, and all the non-zero elements are moved to the front. Use the concept of dynamic memory allocation for taking array input.

All non zero element will remain in same order as before.

For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be:

[1, -2, 3, 4, 5, -27, 9, 0, 0, 0].
-------------------------------------
code:
-------------------------------------
#include <iostream>
using namespace std;

int main() {
    // Step 1: Dynamically allocate memory for the number of test cases
    int *t = new int; // Pointer t to store the number of test cases
    cout << "Enter the number of test cases: ";
    cin >> *t; // Read the number of test cases

    // Step 2: Process each test case
    while ((*t)--) { // Decrement t after each iteration
        // Step 2a: Dynamically allocate memory for the size of the array
        int *n = new int; // Pointer n to store the size of the current array
        cout << "Enter the size of the array: ";
        cin >> *n; // Read the size of the array

        // Step 2b: Dynamically allocate memory for the array based on size n
        int *arr = new int[*n]; // Pointer arr to store the array elements

        // Step 2c: Read the elements of the array
        cout << "Enter " << *n << " elements: ";
        for (int i = 0; i < *n; ++i) {
            cin >> *(arr + i); // Read each element into the array
        }

        // Step 2d: Allocate memory for a counter
        int *a = new int; // Pointer a to count non-zero elements
        *a = *n; // Initialize the counter with the size of the array

        // Step 2e: Output non-zero elements and count remaining zeros
        cout << "Output: ";
        for (int i = 0; i < *n; ++i) {
            // Check if the current element is non-zero
            if (*(arr + i) != 0) {
                cout << *(arr + i) << " "; // Print the non-zero element
                (*a)--; // Decrement the counter for each non-zero element
            }
        }

        // Step 2f: Print remaining zeros based on the counter
        while ((*a) > 0) { // While there are zeros to print
            cout << 0 << " "; // Print zero
            (*a)--; // Decrement the counter
        }

        cout << endl; // Print a newline after the output for the current test case

        // Step 2g: Deallocate memory for the array and counter
        delete[] arr; // Free the memory allocated for the array
        delete a; // Free the memory allocated for the counter
        delete n; // Free the memory allocated for the size of the array
    }

    // Step 3: Deallocate memory for the number of test cases
    delete t; // Free the memory allocated for the number of test cases

    return 0; // Indicate that the program finished successfully
}
