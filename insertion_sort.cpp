// Q 40. Insertion sort
//
// => Find elements proper place
// => Make room for element to be inserted
//    by shifting other elements
// => Insert the element
//
// Author - Prashant Kothawade
// Date - 30-04-2016

#include <iostream>
using namespace std;

// Selection sort function
void insertion_sort(int arr[], const int sz){
	int outer, inner;
	for(outer=1; outer<sz; outer++) {
		int temp = arr[outer];
		inner = outer;
		while(inner>0 && arr[inner-1]>=temp) {
			arr[inner] = arr[inner-1];
			--inner;
		}
		arr[inner] = temp;
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
	insertion_sort(array,sz);

	// Print sorted list 
	for(int i=0; i<sz; i++) {
		cout<<array[i]<<" ";
	}
	
	// Delete dynamic array
	delete[] array;

	return 0;
}