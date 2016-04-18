// Q29. STL vectors
//
// Vectors are seuence containers representing array that
// can change dynamically in size. Just like arrays vectors
// use continguous memory but vectors consume more memory
// for the ability manage storage and grow in size 
// dynamically in efficient way.
//
// Author - Prashant Kothawade
// Date - 16-04-2016

#include <iostream>
#include <vector>
using namespace std;

int main() {

	// Declare vector of integers
	vector<int> vec;

	// Add elements at the end
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// Print element accessing by index
	cout<<vec[0]<<" "; // Prints 10
	cout<<vec[1]<<" "; // Prints 20
	cout<<vec[2]<<" "; // Prints 30

	// Insert element at second position
	std::vector<int>::iterator it;
	it = vec.begin();
	vec.insert(it+1,15);

	// Iterate through vector
	cout<<endl<<"Sizr of vector ="<<vec.size()<<endl; // Prints 4
	for (it=vec.begin(); it<vec.end(); it++) {
		cout<<*it<<" ";
	} // Prints 10 15 20 30

	// Print 3rd element
	cout<<endl<<"Third element in vector ="<<vec.at(2);

	// Delete third element
	it = vec.begin();
	vec.erase(it+2);

	// Use range based for loop to print elements
	cout<<endl;
	for(auto i : vec) {
		cout<<i<<" ";
	} // Prints 10 15 30

	// clear the vector
	vec.clear();
	cout<<endl<<"Sizr of vector ="<<vec.size()<<endl; // Prints 0

	return 0;
}