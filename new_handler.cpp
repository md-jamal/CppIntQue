// Q18. Handling failure of new
//
// When new fails to allocate memory it may throw an exception std::bad_alloc
// It may also return 0 in such case
// Better way to handle failure of new is to use new_handler.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
using namespace std;

void new_failed() {
	cout<<"Failed to allocate memory, exiting application...";
	exit(0);
}

int main() {

	// new returns 0 if it fails (with no exception)
	int* a = new(std::nothrow) int[100];
	if(!a) return 0;

	// But better way is to use new-handler
	set_new_handler(new_failed);

	double* b = new double[99999999];
	double* c = new double[99999999];
	double* d = new double[99999999];

	// Reset new handler
	set_new_handler(0);

	return 0;
}