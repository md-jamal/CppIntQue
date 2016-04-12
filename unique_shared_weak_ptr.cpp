// Q16. unique_shared_weak_ptr.cpp
//
// unique_ptr - There can be at the most one unique ptr
// pointing to any one resource. Any attempt to make a
// copy will show an error
//
// shared_ptr - It is reference counting shared ownership pointer
// It is copyable and movable. It allows mulitple pointers to point
// at given resource.
// 
// weak_ptr - It provides non-owning access to pointee object.
// It is associated with shared_ptr and allows access if object exists
// rather than attempting to access destroyed object.
//
// Author - Prashant Kothawade
// Date - 12-04-2016

#include <iostream>
#include <memory>

using namespace std;

// Some class
class MyClass {
public:

	MyClass() {
		m_var = new int;
		*m_var = 10;
	}
	// Constructor

	int fun() {
		return *m_var;
	}

	~MyClass() {
		delete m_var;
	}

private:

	int* m_var;

};

int main() {

/////unique_ptr//////////
	// Create unique pointer to MyClass
	std::unique_ptr<MyClass> my_unique_ptr(new MyClass);
	cout<<my_unique_ptr->fun()<<endl;

	// Any attempt to make a copy will cause an error
	//std::unique_ptr<MyClass> other_unique_ptr = my_unique_ptr;

	// But we can use move to transfer ownership
	{
		std::unique_ptr<MyClass> other_unique_ptr = std::move(my_unique_ptr); 
		// No error - resource is stored in other_unique_ptr now
		cout<<other_unique_ptr->fun()<<endl;
	} // Resource goes out of scope so will get deleted

	// Attempt to access original resource will crash the program
	//cout<<my_unique_ptr->fun()<<endl;


/////shared_ptr//////////
	{
		// Create shared pointer to MyClass
		std::shared_ptr<MyClass> my_shared_ptr(new MyClass);
		cout<<my_shared_ptr->fun()<<endl; // refcount = 1

		// Making copy of resource is fine
		std::shared_ptr<MyClass> other_shared_ptr = my_shared_ptr; // refcount = 2

		// It is even movable
		std::shared_ptr<MyClass> another_shared_ptr = std::move(other_shared_ptr);  // refcount = 2

		{
			// Multiple pointers can point at the resoure
			std::shared_ptr<MyClass> more_shared_ptr;
			more_shared_ptr = my_shared_ptr; // refcount = 3
		} // refcount decreased to = 2
		
	} // Resource goes out of scope so will get deleted


/////weak_ptr//////////
	{
		// Create shared pointer to MyClass
		std::shared_ptr<MyClass> my_shared_ptr(new MyClass);

		// Create weak pointer by assigning my_shared_ptr
		std::weak_ptr<MyClass> my_weak_ptr = my_shared_ptr;

		// my_weak_ptr is valid so fun() method will be called
		if(auto tmp = my_weak_ptr.lock()) {
			cout<<tmp->fun()<<endl; // prints 10
		}

		// Reset shared pointer to acquire new object
		my_shared_ptr.reset(new MyClass);
		
		// my_weak_ptr is expied so won't go inside if condition
		if(auto tmp = my_weak_ptr.lock()) {
			cout<<tmp->fun(); // don't come here
		}
	}

	return 0;
}