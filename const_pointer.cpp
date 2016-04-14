// Q24. const pointer and pointer to const
//
// Author - Prashant Kothawade
// Date - 14-04-2016

#include <iostream>
using namespace std;

void main() {
	
	// String
	char name[] = "Sachin";
	
	// No const
	char* str = name;
	*str = 'A';    // Modify string works
	str = "Rahul"; // Change pointer works
	
	// pointer to const string
	const char* str1 = name;
	//*str1 = 'A';    // Modify string not allowed
	str1 = "Rahul";   // Change pointer works
	// Same
	char const* str2 = name;
	//*str2 = 'A';    // Modify string not allowed
	str2 = "Rahul";   // Change pointer works
	
	// const pointer to string
	char* const str3 = name;
	*str3 = 'A';      // Modify string works
	//str3 = "Rahul"; // Change pointer not allowed

	// const pointer to const string
	const char* const str4 = name;
	//*str4 = 'A';    // Modify string not allowed
	//str4 = "Rahul"; // Change pointer not allowed
}