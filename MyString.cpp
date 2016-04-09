// Q4. Write your own string class
//
// Author - Prashant Kothawade
// Date - 09-04-2016

#include <iostream>
using namespace std;
class MyString;

// Global overloaded stream operator to print MyString with cout
ostream& operator<<(ostream& stream, MyString& str);

class MyString
{
public:

	MyString(char* str);
	// Overloaded Constructor

	MyString(const MyString& str);
	// Copy constructor

	MyString operator+(MyString& str);
	// Concatenate with given string and return new string

	MyString& operator=(MyString& str);
	// Assigning given string

	MyString& operator+=(MyString& str);
	// Appending given string to this string

	int length() const;
	// Length of string

	~MyString();
	// Destructor

private:

	MyString();
	// Private default constructor

	char* m_str;
	// Character string

	friend ostream& operator<<(ostream& stream, MyString& str);
	// Stream operator to print string with cout
};

// Overloaded Constructor
MyString::MyString(char* str)
{
	_ASSERT(str);
	m_str = new char[strlen(str) + 1];
	strcpy(m_str,str);
}

// Copy Constructor
MyString::MyString(const MyString& str)
{
	m_str = new char[strlen(str.m_str) + 1];
	strcpy(m_str,str.m_str);
}

// Concatenate with given string and return new string
MyString MyString::operator+(MyString& str)
{
	char* tstr = new char[strlen(m_str)+strlen(str.m_str)+1];
	strcpy(tstr,m_str);
	strcat(tstr,str.m_str);
	return MyString(tstr);
}

// Assigning given string
MyString& MyString::operator=(MyString& str)
{
	if(this!=&str){
		delete[] m_str;
		m_str = new char[strlen(str.m_str) + 1];
		strcpy(m_str,str.m_str);
	}
	return *this;
}

// Appending given string to this string
MyString& MyString::operator+=(MyString& str)
{
	char* tstr = m_str;
	m_str = new char[strlen(m_str)+strlen(str.m_str)+1];
	strcpy(m_str,tstr);
	strcat(m_str,str.m_str);
	return *this;
}

// Length of string
int MyString::length() const
{
	return strlen(m_str);
}

//  Overloaded stream operator to print MyString with cout
ostream& operator<<(ostream& stream, MyString& str)
{
	stream<<str.m_str;
	return stream;
}

// Destructor
MyString::~MyString()
{
	delete m_str;
}

void main() {

	// Creating object without passsing string will give an erro
	//MyString str;

	// Instantiate with empty string
	MyString empty_str("");
	cout<<empty_str.length()<<endl; // Prints 0

	// Assignment operator
	empty_str = MyString("ABC");
	cout<<empty_str<<endl; // Overloaded stream operator prints ABC

	// Create new string
	MyString name("Jack");
	cout<<name<<endl; // Prints Jack
	cout<<name.length()<<endl; // Prints 4

	// Copy Constructor
	MyString jack_name = name;
	cout<<jack_name<<endl; // Prints Jack

	// + and = oprtator
	MyString jil_name("Jil");
	jack_name = jack_name + jil_name;
	cout<<jack_name<<endl; //Prints JackJil

	// += operator
	jack_name += MyString("Joe");
	cout<<jack_name<<endl; //Prints JackJilJoe
}