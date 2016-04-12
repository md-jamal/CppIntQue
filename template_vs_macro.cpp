// Q19. Template vs macro => template_vs_macro.cpp
//
// Template and macro both performs a simple text substitution
// and can work with any types but - 
// - macro is expanded without any type checking unlike template
// - if any parameter has pre/post incremental value then increment
//   will be performed multiple times giving wrong result
// - Macros are expanded by preprocessor compiler so error messages
//   will refer to expanded macros rather than macro definition itself.
// - return value from macros isn't specified so compiler can't tell
//   if it is assigned to incompatible variable.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
using namespace std;

#define MIN(i,j) (i<j ? i : j)

template <class T>
T tmin(T a, T b) {
	if(a<b)
		return a;
	else
		return b;
}

int main() {

	// No type checking happens in macro so
	// following code works with macro
	int a = 12;
	float b = 9;
	int min_val = MIN(a,b);
	// But it would give compilation error with template
	//min_val = tmin(a,b);

	int c = 9;
	min_val = tmin(a,++c); // c is 10 and so it is min
	cout<<"min value is "<<min_val<<endl; // prints 10

	min_val = MIN(a,++c); 
	// c is passed as 11 but it will be incremented twice to become 12
	cout<<"min value is "<<min_val; // prints 12

    // return value in macro is not specified so following code is fine
	char* res = MIN("a","b");

	// But template would check return type so will give an error
	//res = tmin("a","b");

	return 0;
}