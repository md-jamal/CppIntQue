// Q20. What if memset called in constructor of class 
// with virtual methods?
//
// Calling memset on class with virtual function is bad
// idea. It will wipe out vtable pointers and also call to
// virtual function will crash.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass() {}
	// Constructor

	virtual void fun() {
		cout<<"In base class";
	}
	// Virtual method

	~MyClass() {
	}
	// Destructor

private:

	int* m_var;
};

class SubClass : public MyClass {
public:
	SubClass() {
		memset(this,0,sizeof(*this));
		// This will wipe out vtable pointers
	}
	// Constructor

	void fun() { 
		cout<<"In derived class";
	}
	// Overridden method

	~SubClass() {
	}
	// Destructor

private:

};

int main() {

	MyClass* obj = new SubClass;
	// Call to virtual function will cause crash
	//obj->fun();
	delete obj;

	return 0;
}