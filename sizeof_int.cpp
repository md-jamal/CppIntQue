// Q7. How to identify size of integer without 
// using sizeof operator
//
// Idea is to use pointer.
// ++ operator increases pointer location by size of
// data type it points to so difference between these  
// two locations should give size of data type
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>
using namespace std;

int main() {

	// Integer data type
	int i = 10;
	int* ptr = &i; // Pointer to location i
	int* ptr1 = ptr;
	ptr1++; // Pointer to next location
	// Difference between two pointer locations
	cout<<"Size of integer :"<<int(ptr1)-int(ptr)<<endl;

	// Double data type
	double d = 10;
	double* dptr = &d; // Pointer to location d
	double* dptr1 = dptr;
	dptr1++; // Pointer to next location
	// Difference between two pointer locations
	cout<<"Size of double :"<<int(dptr1)-int(dptr);

	return 0;
}
