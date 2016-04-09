// Q2. - Restrict class instance to be created on stack
// so that object can be created only on heap.
//
// We can make destructor private
// But will need to provide other method to delete the instance
//
// Author - Prashant Kothawade
// Date - 09-04-2016

class MyClass
{
public:

	MyClass(){}
	// Constructor

	void destroy() {
		delete this;
	}
	// Method to delete instance
	// This will call destructor

private:

	~MyClass(){}
	// Private Destructor

};

int main() {

	// Try creating object on stack
	// It gives compilation error - 
	// ~MyClass cannot access private member
	//MyClass obj;

	// Creating object on heap is fine
	// but you need to call destroy method instead of delete.
	MyClass* obj = new MyClass();
	obj->destroy();

	return 0;
}
