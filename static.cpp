// Q32. static keyword
//
// static elements are allocated storage only once in a program
// lifetime in static storage area and they have a scope till
// program lifetime.
//
// static members belongs to class and shared by all objects
// of class. static member functions can access only static
// member variables of class and do not have this pointer
// inside them.
//
// Author - Prashant Kothawade
// Date - 18-04-2016

#include <iostream>

using namespace std;

// General static function
void counter()
{
	int num = 0;
	// Value of static variable is perist across function calls
	// and throughout program lifetime
	static int counter = 0;
	cout<<"num = "<<++num<<" "; // always prints 0
	cout<<"counter ="<<++counter<<endl; // increments counter and print it
}

// Class containing static members
class MyClass {
public:

	MyClass() : m_num(0) {
		++m_num;
		++m_counter;
	}
	// Constructor

	void print_num() {
		cout<<"m_num = "<<m_num<<" ";
		// Can access static members inside non-static functions
		cout<<"m_counter ="<<m_counter<<endl;
	}
	// Print value of m_num and m_counter

	static void print_counter() {
		// Can not access non-static member in static function
		//cout<<m_num;
		cout<<"m_counter = "<<m_counter<<endl;
	}
	// Prints object counter

	~MyClass() {}
	// Destructor

private:

	int m_num;
	static int m_counter;
};

// Need to define static variable outside class to get memory assigned
int MyClass::m_counter = 0;


// Global static variable
static int temp = 5;

int main() {

	// demo of static variable in normal function
	counter(); // prints counter 1
	counter(); // prints counter 2
	counter(); // prints counter 3

	// Create object of of MyClass
	MyClass obj1;
	obj1.print_num(); // prints 1 1
	obj1.print_counter(); // prints 1
	
	MyClass obj2;
	obj2.print_num(); // prints 1 2
	obj2.print_counter(); // prints 2

	MyClass obj3;
	// static methods can be called on class itself
	MyClass::print_counter(); // prints 3

	// Static variables in different scope
	cout<<endl;
	static int temp = 10;
	cout<<temp<<endl; // prints 10
	{ 
		static int temp = 20;
		cout<<temp<<endl; // prints 20
		{
			static int temp = 30;
			cout<<temp<<endl; // prints 30
			cout<<::temp<<endl; // prints 5 (global)
		}
		cout<<temp<<endl; // prints 20
	}
	cout<<temp<<endl; // prints 10

	return 0;
}
