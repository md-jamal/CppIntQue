// Q25. Why do we need virtual destructor? 
// Does it need even when there is no virtual function in class?
//
// Consider a case where base class pointer is assigned an object
// of derived class. Now if we delete the pointer (which is really 
// a base class pointer) it would call destructor of base class.
// But ideally first derived class destructor should be called 
// followed by base class destructor. This can be ensured by
// virtual destructor.
//
// Author - Prashant Kothawade
// Date - 14-04-2016

#include <iostream>
using namespace std;

// Base class without virtual destructor
class base {
public:
	base(){
		cout<<"In base constructor"<<endl;
	}
	// Constructor

    ~base(){
	//virtual ~base() {
		cout<<"Base class destructor"<<endl;
	}
	// destructor

private:

};

// Dervied class
class derived : public base {
public:

	derived() {
		cout<<"In derived constructor"<<endl;
		m_ptr = new int[5];
	}
	// Constructor

	~derived() {
		delete[] m_ptr;
		cout<<"Derived class destructor"<<endl;
	}
	// Destructor

private:

	int* m_ptr;
};

int main() {

	// Object of derived is assigned to base ptr
	base* base_ptr = new derived;
	delete base_ptr; // prints "In base constructor"
	                 //        "In derived constructor"
	                 //        "Base class destructor"
	// So destructor of derived class is not called
	// where memory of m_ptr is deleted causing memory leak

	// Size of class without virtual function
	cout<<"Size of base : "<<sizeof(base)<<endl; // Sizeof empty class 1 byte

	// Make base class destructor virtual by commenting
	// existing declaration and uncommenting following line
	// with virtual keyword.
	// You will see that now it calls derived class destructor
	// first followed by base class destructor

	// Size of class with virtual function
	cout<<"Size of base : "<<sizeof(base); // prints 4 with virtual destructor

	// Clearly virtual function add overhead to class
	// "If a class does not contain any virtual functions, that is 
	// often an indication that it is not meant to be used as a base class. 
	// When a class is not intended to be used as a base class, making the 
	// destructor virtual is usually a bad idea."

}