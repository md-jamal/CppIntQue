// Q22. How to add and substract numbers without 
// using arithemetic operators?
//
// Arithemetic operations can be performed using 
// bitwise operators. Half adder logic can be used
// to add two numbers. Substraction is adding first
// number with 2's complement of second number.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
using namespace std;

// Addition using bitwise operators
int add(int a, int b)
{
    if (b==0)
		// There is no carry
        return a;
    else
		// bitwise XOR (^) will give sum of a and b
		// bitwise AND (&) will give carry bits, shift by one
		// Call add recursively
        return add(a^b, (a&b)<<1);  
}

// Substraction using bitwise operators
int sub(int a, int b) {
	// 2's complement of b
	int negate = add(~b, 1);
	// Add a and 2's complement of b
	return add(a,negate);
}

int main() {

	int a, b;
	cout<<"Enter two numbers :";
	cin>>a>>b;
	cout<<"a+b = "<<add(a,b)<<endl;
	cout<<"a-b = "<<sub(a,b);
	return 0;
}
