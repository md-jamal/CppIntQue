// Q9. Singleton pattern
//
// Author - Prashant Kothawade
// Date - 10-04-2016

#include <iostream>

using namespace std;

// Singleton class
class StClass
{
public:

	// Only access point to get instance of class
	static StClass* get_instance(){
		// If instance does not exist then create it
		// Otherwise return the pointer
		if(!m_ptr) {
			m_ptr = new StClass();
		}
		return m_ptr;
	}
	
	// Some method of class
	void display(){
		cout<<"MyClass display method";
	}
	
private:

	StClass(){};
	// Private constructor

	~StClass(){};
	// Private destructor

	static StClass* m_ptr;
	// Pointer to single instance of class
};

// Static initialisation
StClass* StClass::m_ptr = 0;

void main() {

	// Creating instance is not possible
	//StClass obj;

	// Get singleton instance and call method
	// First time it would create instance
	StClass::get_instance()->display();

	// Second time onward it will just return pointer
	// to single instance of class
	StClass::get_instance()->display();

	// Deleting instance is also not possible
	StClass* ptr = StClass::get_instance();
	//delete ptr;
}
