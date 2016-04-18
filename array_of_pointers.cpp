// Q30. Array storing pointers and double pointers
//
// Author - Prashant Kothawade
// Date - 18-04-2016

#include <iostream>
using namespace std;

int main() {

	// Declare some integers
	int i=10, j=20, k=30;

	// Pointers to these integers
	int* iptr = &i;
	int* jptr = &j;
	int* kptr = &k;

	// Array storing these pointer
	int* arr[3];
	arr[0] = iptr;
	arr[1] = jptr;
	arr[2] = kptr;

	// Print elements
	for(int id=0; id<3; id++) {
		cout<<*arr[id]<<" "; // Prints 10 20 30
	}

	// dynamic array storing pointers
	int** darr = new int*[3];
	darr[0] = iptr;
	darr[1] = jptr;
	darr[2] = kptr;
	cout<<endl;
	int** tmp_it = darr;
	for(int id=0; id<3; id++) {
		cout<<**tmp_it<<" ";
		++tmp_it;
	} // Prints 10 20 30
	delete[] darr;

	// Double pointers (ponters to pointers)
	int** dbl_iptr = &iptr;
	int** dbl_jptr = &jptr;
	int** dbl_kptr = &kptr;

	// Array storing double pointers
	int** dbl_arr[3];
	dbl_arr[0] = dbl_iptr;
	dbl_arr[1] = dbl_jptr;
	dbl_arr[2] = dbl_kptr;

	// Print elements
	cout<<endl;
	for(int id=0; id<3; id++) {
		cout<<**dbl_arr[id]<<" "; 
	} // Prints 10 20 30

	// dynamic array storing double pointers
	int*** dbl_darr = new int**[3];
	dbl_darr[0] = dbl_iptr;
	dbl_darr[1] = dbl_jptr;
	dbl_darr[2] = dbl_kptr;
	cout<<endl;
	int*** dbl_tmp_it = dbl_darr;
	for(int id=0; id<3; id++) {
		cout<<***dbl_tmp_it<<" ";
		++dbl_tmp_it;
	} // Prints 10 20 30
	delete[] dbl_darr;

	return 0;
}