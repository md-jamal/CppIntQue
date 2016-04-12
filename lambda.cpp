// Q17. lambda function in C++ 11
//
// lambda expression is a way to define an anonymous function
// [capture clause] (argument_list) mutable throw() -> trailing_return_type
// {
//   <function body>
// }
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
#include <algorithm>

using namespace std;

// Sort using lambda expression
void abs_sort(float* arr, int sz) {
	std::sort(arr, arr+sz, [](float a, float b) {
		  return (std::abs(a) < std::abs(b));
	    }
	);
}

int main() {

	// Sorting the array
	float arr[5] = {-3.2, 1.5, 4.35, 3.2, -5.6};
	abs_sort(arr,5);
	for( auto i : arr) {
		cout<<i<<" "; // Prints - 1.5 -3.2 3.2 4.35 -5.6
	}

	// lambda with return type
	auto sum = [](int a, int b) -> int {
		return a + b;
	};
	cout<<endl<<sum(5,7); // Prints 12

	// Capture clause
	int myvar = 10;
	[=]() { // Capture clause = by value
		//myvar = myvar + 10; // so can not change myvar
		int a = myvar; // But can access myvar
	} ();

	[&]() { // Capture clause = by value
		myvar = myvar + 10; // can access and even change myvar
	} ();
	cout<<endl<<myvar; // prints 20

	return 0;
}