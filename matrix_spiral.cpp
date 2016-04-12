// Q12. Print a matrix in spiral form
//  ________________
//  _______________ |
// |  __________  | |
// | |          | | |
// | |  ________| | |
// | |____________| |
// |________________|
//
//  01 02 03 04
//  12 13 14 05
//  11 16 15 06
//  10 09 08 07
//
//  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16
//
// Author - Prashant Kothawade
// Date - 11-04-2016

#include <iostream>
#include <algorithm>

using namespace std;

// Function to print matrix in spiral form
void print_spiral(int *arr[], int row_order, int col_order)
{
	int row_start = 0;
	int col_start = 0;
	int row_end = row_order-1;
	int col_end = col_order-1;
	int i = 0;
	while(row_start<=row_end && col_start<=col_end) {
		// Print first row from remaining matrix
		for (i=col_start; i <= col_end ; i++) {
			cout<<arr[row_start][i]<<" ";
		}
		// Print last column from remaining matrix
		row_start++;
		for(i=row_start; i<=row_end; i++) {
			cout<<arr[i][col_end]<<" ";
		}
		// Print last row from remaining matrix
		col_end--;
		if(row_start<=row_end) {
			for(i=col_end; i>=col_start; i--) {
				cout<<arr[row_end][i]<<" ";
			}
		}
		// Print first column from remaining matrixs
		row_end--;
		if(col_start<=col_end) {
			for(i=row_end; i>=row_start; i--) {
				cout<<arr[i][col_start]<<" ";
			}
		}
		col_start++;
	}
}

int main() {

	// User input
	int row_sz = 0;
	int col_sz = 0;
	cout<<"Enter number of rows :";
	cin>>row_sz;
	cout<<"Enter number of columns :";
	cin>>col_sz;
	int** array = new int*[row_sz];
	cout<<endl<<"Enter matrix elements : ";
	for(int i=0; i<row_sz; i++) {
		array[i] = new int[col_sz];
		for(int j=0; j<col_sz; j++) {
		  cin>>array[i][j];
		}
	}

	// Print in spiral form
	print_spiral(array,row_sz, col_sz);

	// Delete array
	for(int i=0; i<row_sz; i++) {
		delete[] array[i];
	}
	delete[] array;

	return 0;
}