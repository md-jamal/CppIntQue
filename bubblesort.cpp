// Q8. Bubble sort program
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>
using namespace std;

// Bubble sort function
void sort(int arr[], const int sz){
	bool change = true;
	// Outer pass (size-1) times
	// If there wasn't any change in last iteration
	// then we are done with sorting
	for(int i=0; i<sz-1 && change; i++) {
		change = false;
		// Inner pass (size-i-1) times
		for(int j=0; j<sz-i-1; j++) {
			if(arr[j]>arr[j+1]){
				// Exchange elements
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				change = true;
			}
		}
	}
}


int main()
{
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
	sort(array,sz);

	// Print sorted list 
	for(int i=0; i<sz; i++) {
		cout<<array[i]<<" ";
	}
	
	// Delete dynamic array
	delete[] array;

	return 0;
}
