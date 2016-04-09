// Q3. - What is the size of empty class?
//
// It is always 1 byte which is the minimum memory compiler can assign
// in order to create objects of empty class. This way compiler can
// distinguish two objects of same empty class. Please note that member 
// functions do not occupy memory in object space.
//
// But for derived classes empty base class need not to be represeted 
// by a separate byte.
//
// Author - Prashant Kothawade
// Date - 09-04-2016

#include <iostream>
using namespace std;

// Empty class
class MyClass {
public:
	MyClass(){}
	// Constructor

	void message() {
		cout<<"This class has no member data";
	}
	// Memeber function

	~MyClass(){}
	// Destructor

private:

};

// Derived empty class
class NewClass : public MyClass {
public:

	NewClass(){}
	// Constructor

	~NewClass(){}
	// Destructor

private:
   
};

// Derived non-empty class
class DataClass : public MyClass {
public:

	DataClass(){}
	// Constructor

	~DataClass(){}
	// Destructor

private:
	int m_var;
};

int main() {

	// Size of class
	cout<<sizeof(MyClass)<<endl; // Prints 1

	// Size of object
	MyClass obj1;
	cout<<sizeof(obj1)<<endl; // Prints 1

	// Size of derived class
	cout<<sizeof(NewClass)<<endl; // Prints 1 only

	// Size of derived class with 1 integer member
	cout<<sizeof(DataClass)<<endl; // Prints 4 
	//(Depending upon integer size on machine)

	return 0;
}