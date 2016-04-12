// Q14. override keyword in C++ 11
//
// Using override specifier in function declaration - 
// - shows that function is a virtual function overriding from baseclass
// - Compiler ensures that function prototype is correct as of base class
//   and you are not adding overloaded function by mistake
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

	virtual void fun() const {
		cout<<"In fun() of class B"<<endl;
	}
	// Virtual function

	~B() {}
	// Destructor
};

// Derived class from B
class D1 : public B {
public:
	D1() {}
	// Constructor

	void fun() {
	//void fun() override {
		cout<<"In fun() of class D1"<<endl;
	}
	// Need to override fun() but missed out const
	// and so it got ddefined as overloaded function
	// Adding override as shown in commented line would
	// have been shown compilation error

	~D1() {}
	// Destructor
};

// Derived class from B
class D2 : public B {
public:
	D2() {}
	// Constructor

	void fun() const override {
		cout<<"In fun() of class D2"<<endl;
	}
	// Adding override ensures that function prototype
	// is matching with function in base class
	// So if we miss to add const it would show compilation
	// error

	~D2() {}
	// Destructor
};

int main() {

	// Assign object of D1 to Base class pointer
	D1 d1_obj;
	B* b_obj = &d1_obj;
	b_obj->fun(); // Prints - "In fun() of class B"
	// where we were expeting to print "In fun() of class D1"

	// Assign object of D2 to Base class pointer
	D2 d2_obj;
	b_obj = &d2_obj;
	b_obj->fun(); // Prints - "In fun() of class D2" as expected

	return 0;
}