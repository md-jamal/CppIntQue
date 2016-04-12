// Q13. auto keyword in C++ 11
//
// auto in C++ 11 is placeholder for all types telling
// compiler it has to deduce the actual type of variable
// that is being declared from its initialiser.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
#include <map>

using namespace std;

// Some class
class MyClass {
};
/*
int main() {

	auto i = 42; // i is an int type
	cout<<typeid(i).name()<<endl; // prints int

	auto p = new MyClass; // p is MyClass type
	cout<<typeid(p).name()<<endl; // prints class MyClass *

	// The decltype type specifier yields the type 
	// of a specified expression.
	decltype(i) j; // j is declared as typr of i which is int
	cout<<typeid(j).name()<<endl; // prints int

	// auto can also be used on for ranged-based loop
	std::map<int, std::string> mymap;
	mymap[10] = "ABC";
	mymap[20] = "XYZ";
	mymap[30] = "PQR";
	for(auto it : mymap) {
		cout<<it.first<<" "<<(it.second).c_str()<<endl; // prints 10 ABC
		                                                //        20 XYZ
		                                                //        30 PQR
	}
	return 0;
}
*/