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

// Loops:

for (INIT; TEST; INCREMENT) 
    // Instruction to repeat while TEST is true


// example:
for (int i=0; i<10; ++i) // Note that ++i is preferred to i++ for performance reasons (faster) 
    std::cout << i << std::endl; // prints numbers from 0 to 9

// If several instructions must be repeated, use braces { } to form a block:
for (int i=0; i<10; ++i) {
    std::cout << i << std::endl; // prints numbers from 0 to 9
}

// Arrays (tableaux):
#define SIZE 10 // Preprocessor directive to define a constant

// Tells the complier to replace all occurrences of SIZE with 10 before compilation

int array[SIZE]; // Declare an array of 10 integers (uninitialized)

for(int i = 0; i < SIZE; ++i) {
scope("for");
num tmp {"tmp", 2*i};
tab[i] = tmp; // The 10 variables are tab[0], tab[1], ... tab[9]
}

// Functions
int power(int a, int b); // Function declaration (prototype)
// Declares a function named power that takes two integers and returns an integer and thus
// the compiler will immediately allocate memory for both the return value and the two arguments
// In C++, it's very common to declare functions before their first use and even the implementation of their content

// We can then assign a value to a variable like this:
c = power(a, b); // Calls the function power with arguments a and b, assigns the result to c by using a temporary value
int c = power(a, b); // Calls the function power with arguments a and b, assigns the result to c directly

// Example to illustrate functions:
int power(int x, int n) {
  fun_scope;

  rem("You may have noticed that arguments have just been");
  rem("copied to two new variables on the stack.");

  // We can use symbols x and n to name those two copies.

  ___;

  // Let us use another variable for the result.
  int res     {"res",     1};
  rem("Indeed, res is not really allocated here... read comments in the code.");
  ___;

  for(int counter {"counter", 1}; counter <= n; ++counter)
    res *= x;

  ___;

  // "return" exits the function, but it also tells the compiler that
  // the "res" variable do not need to be allocated, since the memory
  // room needed for it is already on the stack, at the "slot" where
  // the result of the function is expected to be.
  return res;
}


// Functions by reference
void double_raz(num& x, num y) {
  fun_scope;
  
  x = 0;
  y = 0;
}


/*
In this case, if we put a reference to an 'x' variable when calling the function,
the function will modify the original variable, not a copy of it.
Outside of the scope of the function, the variable will be modified to be 0. 

= "Effet de bord" (side effect)
*/


// Scopes

/*  
Permet de manipuler une pile. En C++, les variables sont des valeurs stockées en mémoire


*/