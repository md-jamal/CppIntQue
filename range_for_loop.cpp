// Q28. Range based for loop in C++ 11
//
// Author - Prashant Kothawade
// Date - 16-04-2016

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	// Array with 10 elements
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};

	// Range based for loop to print all elements in array
	for(int i : arr) {
		cout<<i<<" ";
	}
	cout<<endl;

	// Vector
	vector<double> vect;
	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);

	// Print elements of vector using range for loop
	for(const auto& j : vect) {
		cout<<j<<" ";
	}

	// Map
	map<int,string> mymap;
	mymap[1] = string("ABC");
	mymap[2] = string("PQR");
	mymap[3] = string("XYZ");

	// Print elements in map using for loop
	for(auto k : mymap) {
		cout<<endl<<k.first<<" "<<k.second.c_str();
	}

	return 0;
}