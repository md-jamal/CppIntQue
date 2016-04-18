// Q31. STL map
//
// Maps are associative containers that store elements
// formed by a combination of key and associated value.
// Internally elements are always sorted by key value.
// 
// Author - Prashant Kothawade
// Date - 18-04-2016

#include <iostream>
#include <map>

using namespace std;

int main() {

	// Create map and add keys and associated values
	std::map<int, string> mymap;
	mymap[1] = "one";
	mymap[2] = "Two";
	mymap[3] = "Three";
	mymap.insert(make_pair(4,"Four"));
	mymap.insert(make_pair(5,"Five"));

	// Print first key and value
	cout<<mymap.begin()->first<<" "; // Prints 1
	cout<<mymap.begin()->second.c_str()<<endl; // Prints "One"

	// Iterate through all elements
	cout<<endl;
	std::map<int,string>::iterator it = mymap.begin();
	while(it!=mymap.end()) {
		cout<<it->first<<" ";
		cout<<it->second.c_str()<<endl;
		it++;
	}

	// Find key 3 and print it value
	cout<<endl;
	if(mymap.find(3) != mymap.end()) {
		cout<<"Key 3 found in map and associated value is = "<<mymap[3].c_str();
	}

	// Delete 3
	mymap.erase(mymap.find(3));

	// Print elements using range based for loop
	cout<<endl;
	for(auto iter : mymap) {
		cout<<iter.first<<" ";
		cout<<iter.second.c_str()<<endl;
	} // Prints 1,2,4 & 5

	return 0;
}