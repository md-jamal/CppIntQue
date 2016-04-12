// Q15. final keyword in C++ 11
//
// final specifier in function declaration - 
// - makes method impossible to override
// - function to have only one implementation
// - typically final would be used in derived class
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
using namespace std;

// Base class
class B {
public:
	B() {}
	// Constructor

	virtual void fun() final {
		cout<<"In fun() of class B"<<endl;
	}
	// Virtual final function
	// Can not be overrided by derived classes

	~B() {}
	// Destructor
};

// Derived class from B
class D1 : public B {
public:
	D1() {}
	// Constructor

	//void fun() {}
	// Can not override fun()
	// Compilation error : function declared as 'final' cannot be overridden

	~D1() {}
	// Destructor
};
