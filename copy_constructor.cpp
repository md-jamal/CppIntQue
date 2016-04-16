// Q27. Copy constructor
//
// Copy constructor creates an object by initialising it
// with an existing object of same class. It is used to -
// 1. Initialise one object from another of same type
// 2. Copy an object to pass it as argument to function
//    when passed by value
// 3. Copy an object to return it from a function
//
// If copy constructor is not defined in a class then
// compiler itself provides one
//
// Copy constructor can be made private to make the class
// non-copyable
//
// Copy constructor must be passed by reference because a
// copy constructor is called when an object is passed by
// value and so if it is called by value then it will
// recursively call copy constructor
//
//
// Author - Prashant Kothawade
// Date - 16-04-2016

#include <iostream>
using namespace std;

class MyClass {
public:

	MyClass(char* name, int val) {
		cout<<"Overloaded constructor"<<endl;
		m_var = val;
		m_name = new char[strlen(name)+1];
		strcpy(m_name,name);
	}
	// Overloaded Constructor

	MyClass(const MyClass& obj) {
		cout<<"Copy constructor"<<endl;
		m_var = obj.m_var;
		m_name = new char[strlen(obj.m_name)+1];
		strcpy(m_name,obj.m_name);
	}
	// Copy Constructor

	int get_val() const {
		return m_var;
	}
	// Get value

	char* get_name() const {
		return m_name;
	}
	// Get name

	~MyClass() {
		if(m_name) delete m_name;
	}
	// Destructor

private:

	MyClass() {
		cout<<"Default constructor"<<endl;
	}
	// Private default constructor

	int m_var;
	char* m_name;
};

// Function to change value in object
// MyClass object is passed by value
// and returned from function by value
MyClass change_val(MyClass myclass) {
	cout<<"In change_val function"<<endl;
	char* name = myclass.get_name();
	int val = myclass.get_val() + 5;
	MyClass temp(name, val);
	return temp;
}

// Class having private copy constructor
class NoCopy {
public:

	NoCopy(){};
	// Constructor

	~NoCopy(){};
	// Destructor

private:

	NoCopy(const NoCopy& obj);
	// Private copy constructor
};

int main() {

	// Create instance of MyClass
	MyClass obj("ABC",20); // Prints "Overloaded constructor"
	cout<<obj.get_name()<<endl;  // Prints ABC
	cout<<obj.get_val()<<endl;   // Prints 20

	// Create new object by initialising with obj
	MyClass copy_obj = obj; // Prints "Copy constructor"
	cout<<copy_obj.get_name()<<endl;  // Prints ABC
	cout<<copy_obj.get_val()<<endl;   // Prints 20

	// Pass this object to function by value
	// get it returned by value
	MyClass change_obj = change_val(copy_obj); // Prints "Copy constructor"
	                                           //        "In change_val function"
	                                           //        "Overloaded constructor"
	                                           //        "Copy constructor"

	cout<<change_obj.get_name()<<endl; // Prints "ABC"
	cout<<change_obj.get_val()<<endl;  // Prints 25

	// Private copy constructor
	NoCopy no_copy_obj;
	// Trying to intialise object with private copy constructor
	// gives compilation error
	//NoCopy try_copy_obj = no_copy_obj;

	return 0;
}