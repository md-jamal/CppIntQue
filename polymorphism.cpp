// Q33. Virtual functions and polymorphism
//
// Virtual function is a member function that you
// expect to be redefined in derived classes. With
// virtual functions program that appears to be
// calling a function of one class may in reality
// be calling a function of different class.
//
// Polymorphism is achieved through virtual functions.
// When you refer to a derived class object using a 
// pointer and reference to the base class, you can call
// virtual functions on base pointer to execute the
// derived class's version of the function.
//
// Author - Prashant Kothawade
// Date - 18-04-2016

#include <iostream>
#define PI 3.14159265

using namespace std;

// An abstract class with pure virtual function
class shape {
public:

	shape() {}
	// Constructor

	virtual float area() = 0;
	// Pure virtual function

	~shape() {}
	// Destructor

private:

};

// Rectangle class derived from shape
class rectangle : public shape {
public:

	rectangle(float side1, float side2){
		m_side1 = side1;
		m_side2 = side2;
	};
	// Overloaded constructor

	float area() {
		return (m_side1 * m_side2);
	}
	// virtual overridden function

	~rectangle(){};
	// Destructor

private:

	rectangle(){};
	// Private constructor

	float m_side1;
	float m_side2;
};

// Circle class derived from shape
class circle : public shape {
public:

	circle(float rad){
		m_rad = rad;
	};
	// Overloaded constructor

	float area() {
		return (PI * m_rad * m_rad);
	}
	// virtual overridden function

	~circle(){};
	// Destructor

private:

	circle(){};
	// Private constructor

	float m_rad;
};

int main() {

	// Can not create object of shape class
	//shape shape_obj;

	// Pointer to base class
	shape* shape_ptr;

	// Create object of rectangle
	rectangle rect_obj(5,7);

	// Assign it to base class pointer
	shape_ptr = &rect_obj;

	// Print area - call area method on base class pointer
	// As it is being assigned retangle object it will call rectangle::area()
	cout<<"Rectangle area with sides 5 and 7 = "<<shape_ptr->area()<<endl;

	// Create object of circle and assign it to base class ptr
	shape_ptr = new circle(6);

	// Print area
	// Now it is being assigned circle object it will call rectangle::area()
	cout<<"circle area with radius 6 = "<<shape_ptr->area()<<endl;

	delete shape_ptr;

	return 0;
}