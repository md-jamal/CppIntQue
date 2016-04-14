// Q23. Matrix implementation 
//
// Author - Prashant Kothawade
// Date - 14-04-2016

#include <iostream>
using namespace std;

// Matrix class
class matrix 
{
public:

	matrix(){}
	// Default constructor
	// Invalid state

	matrix(int row, int col);
	// Overloaded constructor

	matrix(const matrix& mat);
	// Copy constructor

	matrix& operator=(const matrix& mat);
	// Assignment operator

	void input();
	// Input for matrix elements

	void display();
	// Display matrix

	matrix& operator+(const matrix& m);
	// Addition of matrix

	matrix& operator-(const matrix& m);
	// Substraction of matrix

	matrix operator*(const matrix& m);
	// Multiplication of matrix

	~matrix();
	// destructor

private:

	int m_rows;
	// Number of rows

	int m_cols;
	// Number of columns

	int** m_ptr;
	// Array pointer
};

/////////// Implementation

// Overloaded constructor
matrix::matrix(int row, int col) : m_rows(row), m_cols(col) {
	m_ptr = new int*[m_rows];
	for(int i = 0; i<m_rows; i++) {
		m_ptr[i] = new int[m_cols];
	}
}

// Copy constructor
matrix::matrix(const matrix& mat){
	m_rows = mat.m_rows;
	m_cols = mat.m_cols;
	m_ptr = new int*[m_rows];
	for(int i = 0; i<m_rows; i++) {
		m_ptr[i] = new int[m_cols];
	}
	for(int i = 0; i<m_rows; i++) {
		for(int j = 0; j<m_cols; j++) {
			m_ptr[i][j] = mat.m_ptr[i][j];
		}
	}
}

// Assignment operator
matrix& matrix::operator=(const matrix& mat) {
	if(this!=&mat) {
		m_rows = mat.m_rows;
		m_cols = mat.m_cols;
		m_ptr = new int*[m_rows];
		for(int i = 0; i<m_rows; i++) {
			m_ptr[i] = new int[m_cols];
		}
		for(int i = 0; i<m_rows; i++) {
			for(int j = 0; j<m_cols; j++) {
				m_ptr[i][j] = mat.m_ptr[i][j];
			}
		}
	}
	return *this;
}

// Input for matrix elements
void matrix::input() {
	cout<<"Enter row wise matrix elements :";
	for(int i = 0; i<m_rows; i++) {
		for(int j = 0; j<m_cols; j++) {
			cin>>m_ptr[i][j];
		}
	}
}

// Display matrix
void matrix::display(){
	cout<<endl;
	for(int i = 0; i<m_rows; i++) {
		for(int j = 0; j<m_cols; j++) {
			cout<<m_ptr[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Addition of matrix
matrix& matrix::operator+(const matrix& m){
	for(int i = 0; i<m_rows; i++) {
		for(int j = 0; j<m_cols; j++) {
			m_ptr[i][j] = m_ptr[i][j]+m.m_ptr[i][j];
		}
	}
	return *this;
}

// Substraction of matrix
matrix& matrix::operator-(const matrix& m){
	for(int i = 0; i<m_rows; i++) {
		for(int j = 0; j<m_cols; j++) {
			m_ptr[i][j] = m_ptr[i][j]-m.m_ptr[i][j];
		}
	}
	return *this;
}

// Multiplication of matrix
matrix matrix::operator*(const matrix& m){
	matrix temp(m.m_rows,m.m_cols);
	for(int i=0;i<m_rows;i++) {
		for(int j=0;j<m.m_cols; j++) {
			temp.m_ptr[i][j] = 0;
			for(int k=0; k<m_cols; k++) {
				temp.m_ptr[i][j] += m_ptr[i][k] * m.m_ptr[k][j];
			}
		}
	}
	return temp;
}

// destructor
matrix::~matrix(){
	for(int i = 0; i<m_rows; i++) {
		delete m_ptr[i];
	}
	delete m_ptr;
}


int main() {

	// Manu selection
	int choice = 0;
	cout<<"Matrix :"<<endl;
	cout<<"1 for addition"<<endl;
	cout<<"2 for substraction"<<endl;
	cout<<"3 for multiplication"<<endl;
	cout<<"Enter choice : ";
	cin>>choice;
	if(choice<=0 || choice>3) {
		cout<<endl<<"Wrong choice";
		return 0;
	}

	// Input number of rows and columns for first matrix
	int rows = 0;
	int cols = 0;
	if(choice==3) {
		cout<<endl<<"Enter no of rows and cols for first matrix :";
	} else {
		cout<<endl<<"Enter no of rows and cols for matrices :";
	}
	cin>>rows>>cols;

	// Input elements for first matrix
	matrix mat(rows, cols);
	cout<<"First matrix :"<<endl;
	mat.input();

	if(choice==3) {
		rows = cols;
		// Input number of rows and columns for second matrix
		cout<<endl<<"Enter no of cols for second matrix :";
		cin>>cols;
	} else {
		cout<<"Second matrix :"<<endl;
	}

	// Input elements for second matrix
	matrix mat1(rows, cols);
	mat1.input();
	cout<<endl;

	// Display of first matrix
	mat.display();
	
	matrix t;
	switch(choice) {
	case 1:
		// Addition of matrices
		cout<<endl<<"+"<<endl;
		t = mat + mat1;
		break;
	case 2:
		// Subtraction of matrices
		cout<<endl<<"-"<<endl;
		t = mat - mat1;
		break;
	case 3:
		// Multiplication of matrices
		cout<<endl<<"*"<<endl;
		t = mat * mat1;
		break;
	}

	// display second matrix
	mat1.display();

	// Display resultant matrix
	cout<<endl<<"="<<endl;
	t.display();

	return 0;
}