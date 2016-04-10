// Q6. Reverse given array
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>
using namespace std;

// Function to reverse given array
void reverse_array(int arr[], const int sz) {
	// Use two indices one from start and another from end
	// and exchange elements till both indices cross each other
	for(int i=0,j=sz-1; i<sz; i++,j--) {
		// If start index crossing end index then break
		if(i>=j) break;

		// Exchange elements
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
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

	// Reverse the array
	reverse_array(array, sz);

	// Print reversed array
	cout<<endl<<"Reversed array :"<<endl;
	for(int i=0; i<sz; i++) {
		cout<<array[i]<<" ";
	}

	// Delete dynamic array
	delete[] array;

	return 0;
}
