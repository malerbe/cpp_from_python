#include <iostream>  // Allows for writing to the terminal... and much more.

// Printing to console
std::cout << "Hello world" << std::endl // Prints Hello World + newline

// Declare a variable
int a;     // Declare an integer variable 'a' (uninitialized)
// Three ways to declare and initialize an integer variable 'b' with value:
int b = 5; 
int b (5);
int b {5}; // prefered

// Allocate a variable valeu by copying another variable
int c = b; // c is now 5
int c (b);
int c {b}; // same

// Assign a value to an existing variable:
int a = 23;
a = 3; // a is now 3

// Elementary variable manipulations:
int a = 5;
int b = 3;
int c;

c = a + b; // c is now 8
// Computing c=a+b requires a temporary int to store the result of a+b before assigning it to c
// This temporary has been freed after being copied

int d = a + b; // Doesn't need the latest temporary, directly initializes d with the result of a+b

int a = 5;
c = ++a; // Pre-increment: a + 1, then assign to c. a is now 6, c is 6
int a = 5;
c = a++; // Post-increment: assign a to c, then a + 1
// In both cases, a is incremented (a becomes 6), but c = 6 in the first case and c = 5 in the second



// Scopes

/*  
Permet de manipuler une pile. En C++, les variables sont des valeurs stockées en mémoire


*/