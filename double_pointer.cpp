// Q26. Double pointers
//
// Pointer stores the address of the variable and 
// pointer to pointer (double pointer) stores address
// of the pointer variable.
//
// Double pointers are useful as fuction parameters
// For example - function allocating memory
//
// Author - Prashant Kothawade
// Date - 15-04-2016

#include <iostream>
using namespace std;

// Forward declaration of function
void init_string(char** sptr);

int main(int argc, char** argv) {

	// Integer variable
	int num = 45;

	// Pointer to integer variable
	int* iptr = &num;

	cout<<"num = "<<num<<endl; // prints 45
	cout<<"Address of num ="<<&num<<endl; // prints address of num

	cout<<"iptr stores address of num ="<<iptr<<endl; // prints address of num
	cout<<"Address of iptr ="<<&iptr<<endl; // prints address of iptr itself
	cout<<"*iptr = "<<*iptr<<endl; // prints 45

	// double pointer
	int** dptr = &iptr;

	cout<<"dptr stores address of iptr ="<<dptr<<endl; // prints address if iptr
	cout<<"**dptr ="<<**dptr<<endl; // prints 45

	// Arguments to main are 'int argc' and 'char** argv' which store number of 
	// command line arguments and array of strings pointing to arguments
	cout<<"Number of command line args to main ="<<argc<<endl;
	for(int i=0; i<argc; i++) {
		cout<<"command line arg "<<(i+1)<<" ="<<argv[i]<<endl;
	}


	// Some character pointer to store string
	char* str;
	// Pass address of this pointer to a function to allocate 
	// memory and intialise the string
	init_string(&str);

	cout<<str; // prints "Empty string"

	// Delete memory assigned for string
	delete[] str;

	return 0;
}

// Function to allocate memory to string and initialise it
void init_string(char** sptr) { // double pointer
	*sptr = new char[50];
	strcpy(*sptr,"Empty string");
}
