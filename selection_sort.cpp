// Q39. Selection sort
//
// Given an array of length N
// => search 0 through N-1 and select smallest number
// => swap it with 0th element
// => search 1 through N-1 and select smallest number
// => swap it with 1st element
// ....and so on
//
// Author - Prashant Kothawade
// Date - 30-04-2016

#include <iostream>
using namespace std;

// Selection sort function
void sel_sort(int arr[], const int sz){
	int outer, inner, min;
	for(outer=0; outer<=sz-1; outer++) {
		min = outer;
		// Search for smallest number
		for(inner=outer+1;inner<sz;inner++) {
			if(arr[inner]<arr[min]) {
				min = inner;
			}
		}
		// swap
		if(min!=outer) {
			int temp = arr[outer];
			arr[outer] = arr[min];
			arr[min] = temp;
		}
	}
}

int main() {
	// User input
	int sz = 0;
	cout<<"Enter size of array :";
	cin>>sz;
	int* array = new int[sz];
	cout<<endl<<"Enter array elements : ";
	for(int i=0; i<sz; i++) {
		cin>>array[i];
	}

	// Sort the list
	sel_sort(array,sz);

	// Print sorted list 
	for(int i=0; i<sz; i++) {
		cout<<array[i]<<" ";
	}
	
	// Delete dynamic array
	delete[] array;

	return 0;
}