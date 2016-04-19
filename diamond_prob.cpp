// Q35. What is a diamond inheritance problem 
// and a solution
//
// The diamond problem occures when two parent
// classes of a class have a common base class.
//
//                Devices
//                  /\
//                 /  \
//     Input_Devices  Output_Devices
//              \         /
//               \       /
//                \     /
//                 \   /
//               IO_Devices
//                
// Here IO_Devices is derived from both Input_Devices
// and Output_Devices which have common base Devices.
// So both classes derived from Devices will have their
// own copy of members defined in base class Devices
// hence IO_Devices will have multiple copies of those
// same members leading to ambiguity.
//
// Author - Prashant Kothawade
// Date - 19-04-2016

#include <iostream>
using namespace std;

// An abstract class Devices
class Devices {

public:

	Devices(){}
	// Constructor

	void set_device_id(const int id) {
		m_device_id = id;
	}
	// Set device id

	virtual ~Devices()=0 {}
	// Destructor

private:

	int m_device_id;
};

// Input class
class Input_Devices : public Devices {
//class Input_Devices : virtual public Devices {

public:

	Input_Devices(){}
	// Constructor

	~Input_Devices(){}
	// Destructor

private:

};

// Output class
class Output_Devices : public Devices {
//class Output_Devices : virtual public Devices {

public:

	Output_Devices(){}
	// Constructor

	~Output_Devices(){}
	// Destructor

private:

};

// IO class
class IO_Devices : public Input_Devices, public Output_Devices {

public:

	IO_Devices(){}
	// Constructor

	~IO_Devices(){}
	// Destructor

private:

};

int main() {

	// Create object of IO_Devices
	IO_Devices io_dev;
	// Call to any member in base class will be ambiguous
	// and compiler will give an error
	io_dev.set_device_id(10);

	// But if you add virtual while inheriting both  
	// Input_Devices & Output_Devices from Devices
	// (as shown in commeneted line below their declarations)
	// only one copy of members from Devices will be inherited
	// to get rid of ambiguity

	return 0;
}