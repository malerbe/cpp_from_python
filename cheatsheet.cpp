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


// Pointers:


// Get the address of a variable and print it:
int a = 5;
std::cout << &a << std::endl; // prints the memory address of variable a

// Store the address of a variable in a pointer:
int* p = &a; // p is a pointer to an integer, initialized with the address of a

// p is also stored in a slot on the stack, which contains the address of a, and then we can do
std::cout << &p << std::endl; // prints the memory address of pointer p

// And... we can also store the address of the pointer p in another pointer:
int** pp = &p; // pp is a pointer to a pointer to an integer


// Pointers manipulations:

// Get an object that we know only by its address:

int a = 5;
int* p = &a; // p is a pointer to an integer, initialized with the address of a

std::cout << *p << std::endl; // prints the value of variable a (5) by dereferencing the pointer p


// Even assignment works:
*p = 3; // assigns the value 3 to variable a by dereferencing the pointer p
std::cout << a << std::endl; // prints 3


// /!\ Do not mix up *ptr and ptr* 

// Pointers as iterators:

// Iterators is an important concept in C++.
// An iterator is an object that points to an element in a container (like an array, a vector, etc.)
// and allows to traverse the elements of the container.

// Pointers can be used as iterators:

#define SIZE 10

int tab[SIZE]; // Declare an array of 10 integers (uninitialized)

for(int i = O; i < SIZE; ++i) 
    tab[i] = 2*i + 1; // Initialize the array with values 0 to 9

// tab is actually a pointer to the first element of the array

std::out << tab << std::endl; // prints the address of the first element of the array

int* ptr = tab; // ptr is a pointer to the first element of the array

// Pointer increment:
int* a = tab;
int* b = a + 1; // Addition on pointers doesn't actually add 1 (or any other number that you put)
// It adds the size of the type pointed to (here int, typically 4 bytes)
// So b points to the next integer in the array
int* c = a + 2; // c points to the second next integer in the array
int* d = a + 3; // d points to the third next integer in the array
// And so on... to access each element of the array

// Print variable size:

std::cout << sizeof(a) << std::endl; // prints the size of variable a in bytes (typically 4 bytes for int)


// Copy an array:


/*
Of course, since tab is a pointer to the first element of the array, it is not allowed to
do just tab = tib and expect to copy the content of the array tib into the content of the array tab.
It woudln't even be allowed as tab is not a variable, but a constant pointer to the first element of the array.

We need to copy each element one by one, using iterators (pointers in this case).
*/

num* it_tab = tab;
it_tib = tib;
// end_tib is already available from previous code.
while(it_tib != end_tib)
  *(it_tab++) = *(it_tib++);


// Pointers to memory in the heap (= "tas" (while stack = "pile" in French))

int* p = new int[SIZE]; // Allocates an array of SIZE integers in the heap


// /!\ Don't forget to free the memory when done !! It will not be the same as the stack memory 
// that is automatically freed when the function returns

// To do so, we use the delete operator:
delete ptr1;
delete [] p; // Frees the array of integers allocated in the heap


// Structures with constructors:

// Define types and operations with them:

struct gridPoint {
  int x;
  int y;
};


void gridPointPrint(grid_point that_point) {
  std::cout << "(" << that_point.x << ", " << that_point.y << ")" << std::endl;
}

void gridPointInit(gridPoint* that_point, int x, int y) {
  (*that_point).x = x;
  that_point->y = y; // THis is a syntactic sugar for (*that_point).y... use it !
}

// Or equivalently:
void gridPointInit(gridPoint& that_point, int& x, int& y) {
  that_point.x = x;
  that_point.y = y;
}


// Actually, we can define constructors for our structures:
struct gridPoint {
  int x;
  int y;

  // Constructor:
  gridPoint(int& x, int& y) {
    this->x = x; // 'this' is a pointer to the current object
    this->y = y;
  }
};



// Cleaner:

struct gridPoint {
  int x;
  int y;

  // Constructor:
  gridPoint(const int x,const  int y) : x(x), y(y) {} // Syntax available for constructors

  gridPoint(const gridPoint& other_point) : x(other_point.x), y(other_point.y) {} // Copy constructor

  gridPoint() : x(0), y(0) {} // Default constructor

  // Now we can define methods for our structure:
  void raz () {
    this->x = 0;
    y = 0; // 'this->' is optional here as there is no ambiguity
  }

  gridPoint add(const gridPoint& other_point) const { // 'const' means that this method doesn't modify the object, it's the
                                                      // equivalent of putting const before the type of the argument but for
                                                      // the object itself (this)
    gridPoint res{this->x + other_point.x, this->y + other_point.y};
    return res;
  }

  int dot_product(const gridPoint& other_point) const {
    return this->x * other_point.x + this->y * other_point.y;
  }

  gridPoint sub(const gridPoint& other_point) const {
    gridPoint res{this->x - other_point.x, this->y - other_point.y};
    return res;
  }

  int distance2(const gridPoint& other_point) const {
    gridPoint tmp = this->sub(other_point); // this can be omitted
    return tmp.dot_product(tmp);
  }

  bool is_equal(const gridPoint& other_point) const {
    return this->x == other_point.x && this->y == other_point.y;
  }

  // We can also make static methods that don't need an object to be called:
  static int distance2(const gridPoint& p1, const gridPoint& p2) {
    gridPoint tmp = p1.sub(p2);
    return tmp.dot_product(tmp);
  }

  

};

// We can call the methods like this:
gridPoint::distance2(...); // Explicitly using the class name for a static method

