// Q38. Mutable keyword
//
// Objects of class declared as const can not
// modify their data members. To override this
// rule in some cases mutable can be used on
// data members where const object can modify
// such members.
//
// Author - Prashant Kothawade
// Date - 30-04-2016

#include <iostream>
using namespace std;

class MutableClass {
public:

	MutableClass(){}
	// Constructor

	void set_values(int x, int y) const {
		//m_var_1 = x; // Compilation error
		m_var_2 = y; // Fine b'coz m_var_2 is mutable
	}
	// Set values

	void set_var_1(int x) const {
		//m_var_1 = x; // compilation error
	}
	// Set m_var_1

	void set_var_2(int y) const {
		m_var_2 = y; // Fine b'coz m_var_2 is mutable
	}
	// Set m_var_2

	~MutableClass() {}
	// Destructor

private:

	int m_var_1;
	mutable int m_var_2;
};
/*
int main() {
	const MutableClass obj;
	obj.set_var_2(20);

	return 0;
}
*/
