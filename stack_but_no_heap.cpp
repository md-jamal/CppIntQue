// Q1. - Restrict class instance to be created on heap
// so that object can be created only on stack.
//
// We can overload new operator and make it private
//
// Author - Prashant Kothawade
// Date - 09-04-2016

class MyClass
{
public:

	MyClass(){}
	// Constructor

	~MyClass(){}
	// Destructor

private:

	void* operator new(size_t sz){}
	// Private new operator
};

int main() {

	// Try creating object of MyClass with new
	//MyClass* obj = new MyClass();
	// It gives compilation error - 
	// operator new cannot access pvt member of MyClass

	// But creating object on stack is fine
	MyClass obj;

	return 0;
}
