// Q34. Class for dynamic array creation
//
// Author - Prashant Kothawade
// Date - 18-04-2016

#include <iostream>
using namespace std;

template <class T>
class DynArr {
public:

	DynArr(int size) {
		m_arr = new T[size];
	}
	// Overloaded contructor

	void add(int index, T val) {
		m_arr[index] = val;
	}
	// Add value at given index

	T operator[](int index) {
		return m_arr[index];
	}
	// Return value at given index

	~DynArr() {
		delete[] m_arr;
	}
	// Destructor

private:

	DynArr();
	// Private default constructor

	T* m_arr;
	// Pointer to array
};

int main() {

	// Create dynamic array
	DynArr<int> darr(5);

	// Add elements
	int val = 10;
	for(int i=0; i<5; i++) {
		darr.add(i,val);
		val += 10;
	}

	// Print elements
	for(int i=0; i<5; i++) {
		cout<<darr[i]<<" ";
	}

	return 0;
}
