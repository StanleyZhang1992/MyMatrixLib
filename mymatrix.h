#ifndef _MYMATRIX_H
#define _MYMATRIX_H

#include<vector>
#include<iostream>

using std::vector;
using std::ostream;

// Pre-declare template class and functions
template<typename T> class MyMatrix;
template<typename T> MyMatrix<T> operator+(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> MyMatrix<T> operator-(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> MyMatrix<T> operator*(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> MyMatrix<T> operator*(const T& lhs, const MyMatrix<T>& rhs);
template<typename T> MyMatrix<T> operator*(const MyMatrix<T>& lhs, const T& rhs);
template<typename T> vector<T> operator*(const vector<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> vector<T> operator*(const MyMatrix<T>& lhs, const vector<T>& rhs);
template<typename T> bool operator==(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> bool operator!=(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T> ostream& operator<<(ostream& out, const MyMatrix<T>& rhs);

template<typename T>
class MyMatrix {

public:

	// Constructors
	MyMatrix();
	MyMatrix(const unsigned rows, const unsigned cols);
	MyMatrix(const unsigned rows, const unsigned cols, const T& initElem);

	// Getters for rows and cols.
	unsigned getRows() const;
	unsigned getCols() const;

	// Overloading operator() to access individual elements
	T& operator()(const unsigned row, const unsigned col);
	const T& operator()(const unsigned row, const unsigned col) const;

	// Mathematical matrix operations
	MyMatrix<T>& operator+=(const MyMatrix<T>& rhs);
	MyMatrix<T>& operator-=(const MyMatrix<T>& rhs);
	MyMatrix<T>& operator*=(const MyMatrix<T>& rhs);
	MyMatrix<T>& operator*=(const T& rhs);
	MyMatrix<T>& operator*=(const vector<T>& rhs);
	MyMatrix<T> operator/=(const T& rhs);

	// Special matrix operations
	MyMatrix<T> transpose();

private:
	// Member variables to store the actual data
	vector<vector<T> > matrix;
	unsigned rows;
	unsigned cols;


	// Declaring friend functions
	friend MyMatrix<T> operator+<T>(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
	friend MyMatrix<T> operator-<T>(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
	friend MyMatrix<T> operator*<T>(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
	friend MyMatrix<T> operator*<T>(const T& lhs, const MyMatrix<T>& rhs);
	friend MyMatrix<T> operator*<T>(const MyMatrix<T>& lhs, const T& rhs);
	friend vector<T> operator*<T>(const vector<T>& lhs, const MyMatrix<T>& rhs);
	friend vector<T> operator*<T>(const MyMatrix<T>& lhs, const vector<T>& rhs);
	friend bool operator==<T>(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
	friend bool operator!=<T>(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
	friend ostream& operator<<<T>(ostream& out, const MyMatrix<T>& rhs);
};

// Mathematical matrix operations
template<typename T>
MyMatrix<T> operator+(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T>
MyMatrix<T> operator-(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T>
MyMatrix<T> operator*(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T>
MyMatrix<T> operator*(const T& lhs, const MyMatrix<T>& rhs);
template<typename T>
MyMatrix<T> operator*(const MyMatrix<T>& lhs, const T& rhs);
template<typename T>
vector<T> operator*(const vector<T>& lhs, const MyMatrix<T>& rhs);
template<typename T>
vector<T> operator*(const MyMatrix<T>& lhs, const vector<T>& rhs);

// Special matrix operations
template<typename T>
bool operator==(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);
template<typename T>
bool operator!=(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs);

// I/O operation
template<typename T>
ostream& operator<<(ostream& out, const MyMatrix<T>& rhs);

#include "mymatrix.cpp"

#endif