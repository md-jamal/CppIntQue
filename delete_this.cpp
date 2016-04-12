// Q20. What will happen if I write 'delete this' in 
// member function or in destructor?
//
// Adding 'delete this' in any member function is fine
// but if object is created on heap using new otherwise
// it will crash for object on stack.
//
// Adding 'delete this' in destructor would cause call
// to destrcutor recursively
//
// Author - Prashant Kothawade
// Date - 12-04-2016

class MyClass {
public:

	MyClass() {}
	// Constructor

	void destroy() {
		delete this;
	}

	~MyClass() {}
	// Destructor

private:

};

class SomeClass {
public:

	SomeClass() {}
	// Constructor

	~SomeClass() {
		delete this;
	}
	// Destructor

private:

};

int main() {

	{
		// Create object on stack
		MyClass obj;
		// Trying to delete object with this will cause crash
		//obj.destroy();
		
		// Create object on heap
		MyClass* obj1 = new MyClass;
		// Deleting object in member function should be fine
		obj1->destroy();
	}

	SomeClass* obj = new SomeClass;
	//delete obj; 
	// This would call destructor which will in turn call 'delete this'
	// and it will cause destructor to be call recursively

	return 0;
}
