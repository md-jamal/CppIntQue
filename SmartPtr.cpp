// Q5. Implement smart pointer
//
// Smart pointer with auto deletion and 
// reference counting mechanism
//
// Author - Prashant Kothawade
// Date - 09-04-2016

#include <iostream>
using namespace std;

template <class T>
class SP {
public:

	SP() : m_refcount(0) {
		m_ptr = 0;
		m_refcount++;
	};
	// Default constructor

	// Overloaded constructor
	SP(T* ptr) : m_ptr(0), m_refcount(0){
		m_ptr = ptr;
		m_refcount++;
	}
	
	// Copy Constructor
	SP(const SP<T>& sp) {
		m_ptr = sp.m_ptr;
		m_refcount = sp.m_refcount;
		m_refcount++;
	}
	
	// Assignment operator
	SP<T> operator=(const SP<T>& sp) {
		// Avoid self assignment
		if(this!=&sp) {
			// Decrement the old reference count
            // if reference become zero delete the old data
			if((--m_refcount)==0) {
				delete m_ptr;
			}
			// Copy the data and reference count
            // and increment the reference count
			m_ptr = sp.m_ptr;
			m_refcount = sp.m_refcount;
			++m_refcount;
		}
		return *this;
	}
	
	// Overloaded Arrow operator
	T* operator->() {
		return m_ptr;
	}

	// Overloaded pointer operator
	T& operator*() {
		return *m_ptr;
	}

	// Destructor
	~SP() {
		if((--m_refcount)==0){
		  delete m_ptr;
		}
	}

private:

	T* m_ptr;
	// Stored pointer

	int m_refcount;
	// Reference count
};

// Some class
class MyClass {

public:

	void fn(){
		cout<<"In Function"<<endl;
	}

	~MyClass() {
		cout <<"In Destructor"<<endl;
	}
};

// Global function taking MyClass SP as parameter
template <class T>
void some_function(SP<T> ptr) {
	ptr->fn();
}

void main() {

	{
		// Create smart pointer of MyClass
		SP<MyClass> sptr(new MyClass());
		sptr->fn(); // Prints "In Function"

	} // When object goes out of scope object gets deleted
	// Prints "In Destructor"

	// Create object with smart pointer
	SP<MyClass> sptr1(new MyClass()); // m_refcount=1
	{
	  // Copy Constructor
	  SP<MyClass> sptr2 = sptr1; // m_refcount=2
	}
	// m_refcount=1

	// Assignment operator
	{
		SP<MyClass> sptr3;
		sptr3 = sptr1; // m_refcount=2
		some_function(sptr3); // m_refcount=3 with copy constructor
		// m_refcount=2
		sptr3->fn();
	}
	// m_refcount=1

	// Overloaded arrow operator
	sptr1->fn(); // Prints "In Function"

	// Overloaded * operator
	(*sptr1).fn(); // Prints "In Function"

} // m_refcount=0 delete object
