// Q11. Find second largest element in array
//
// Two methods -
// 1. Sort the list and find out second last element
// 2. Iterate through list and find large and 
//    second large element by comparing
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>
#include <algorithm>

using namespace std;

// Sort and find second largest element
int sort_and_find(int arr[], const int sz) {
	if(sz>1) {
		std::sort(arr, arr+sz);
		return arr[sz-2];
	} else {
		return arr[0];
	}
}

// Iterate through array and find second largest element
int iterate_and_find(int arr[], const int sz) {
	
	// Intially set large and second_large as first element
	int large = arr[0];
	int second_large = large;

	// In second element is smaller than first then set it as second_large
	if(sz>1 && arr[1] < large) {
		second_large = arr[1];
	} 
	
	// Set large and second large by comparing
	for(int i=1; i<sz; i++) {
		if(arr[i]>large) {
			second_large = large;
			large = arr[i];
		} else if(arr[i]>second_large) {
			second_large = arr[i];
	    }
	}
	return second_large;
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

	int sec_largest = iterate_and_find(array,sz);
	cout<<"Second largest element (iterate method) :"<<sec_largest<<endl;

	sec_largest = sort_and_find(array,sz);
	cout<<"Second largest element (sort method) :"<<sec_largest<<endl;

	// Delete dynamic array
	delete[] array;

	return 0;
}