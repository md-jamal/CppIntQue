// Q10. Functor (Function object)
//
// A functor is an object which acts like a function.
// Basically a class which overload operator ()
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>

using namespace std;

class functor 
{
public:

	functor() {
		m_var = 0;
	}
	// Constructor

	functor(int val) {
		m_var = val;
	}
	// Overloaded constructor

	void operator()(const int val) {
		m_var = val;
	}
	// Overloaded operator()

	int operator()() const {
		return m_var;
	}

	~functor() {
	}
	// Destructor

private:

	int m_var;
	// Variable storing value
};

int main() {

	// Create object with default constructor
	functor fobj1;
	cout<<fobj1()<<endl; // Prints intialised value 0
	// Pass value to functor
	fobj1(10);
	cout<<fobj1()<<endl; // Prints 10
	fobj1(20);
	cout<<fobj1()<<endl; // Prints 20

	// Create object with overloaded constructor
	functor fobj2(100);
	cout<<fobj2()<<endl; // Prints 100
	fobj2(200);
	cout<<fobj2()<<endl; // Prints 200

	return 0;
}