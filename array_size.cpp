// Q37. How to find size of array? 
//
// Size of array can be determined by dividing
// sizeof array variable by sizeof type
// Example - sizeof(arr) / sizeof(int)
//
// But size of dynamic array can not be found
// int this way
//
// Author - Prashant Kothawade
// Date - 30-04-2016

#include <iostream>
using namespace std;

int main() {

	// Define integer array
	int int_arr[] = {2,4,6,8,10,12};
	int float_arr[] = {11.23,45.21,56.73};

	// Find size of array
	int arr_sz = sizeof(int_arr) / sizeof(int);

	// Print
	cout<<"Size of integer array : "<<arr_sz; // prints 6

	// Find size of array
	arr_sz = sizeof(float_arr) / sizeof(float);

	// Print
	cout<<endl<<"Size of float array : "<<arr_sz; // prints 3

	// But size of dynamic array can not be find in this way
	int* dyn_arr = new int[5];
	arr_sz = sizeof(dyn_arr) / sizeof(int);
	cout<<endl<<"Size of dynamic array : "<<arr_sz; // prints 1 which is wrong

	delete[] dyn_arr;

	return 0;
}