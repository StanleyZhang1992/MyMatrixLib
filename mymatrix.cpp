#ifndef _MYMATRIX_CPP
#define _MYMATRIX_CPP

#include"mymatrix.h"
#include<algorithm>

using std::cout; using std::endl;
using std::fill;
using std::for_each;

template<typename T>
MyMatrix<T>::MyMatrix() = default;

template<typename T>
MyMatrix<T>::MyMatrix(const unsigned rows, const unsigned cols) {
	matrix.resize(rows);
	for_each(matrix.begin(), matrix.end(), [cols](vector<T>& row) {row.resize(cols);});
	this->rows = rows;
	this->cols = cols;
}

template<typename T>
MyMatrix<T>::MyMatrix(const unsigned rows, const unsigned cols, const T& initElem) {
	matrix.resize(rows);
	fill(matrix.begin(), matrix.end(), vector<T>(cols, initElem));
	this->rows = rows;
	this->cols = cols;
}

template<typename T>
unsigned MyMatrix<T>::getRows() const {
	return rows;
}

template<typename T>
unsigned MyMatrix<T>::getCols() const {
	return cols;
}

template<typename T>
T& MyMatrix<T>::operator()(const unsigned row, const unsigned col)
{
	return matrix[row][col];
}

template<typename T>
const T& MyMatrix<T>::operator()(const unsigned row, const unsigned col) const
{
	return matrix[row][col];
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator+=(const MyMatrix<T>& rhs)
{
	(*this) = (*this) + rhs;
	return *this;
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator-=(const MyMatrix<T>& rhs)
{
	(*this) = (*this) - rhs;
	return *this;
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator*=(const MyMatrix<T>& rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator*=(const T& rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator*=(const vector<T>& rhs)
{
	(*this) = (*this) * rhs;
	return *this;
}

template<typename T>
MyMatrix<T> MyMatrix<T>::operator/=(const T& rhs)
{
	MyMatrix<T> res(this->rows, this->cols);
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->cols; ++j) {
			this->matrix[i][j] = this->matrix[i][j] / rhs;
		}
	}
	return res;
}

template<typename T>
MyMatrix<T> MyMatrix<T>::transpose()
{
	MyMatrix<T> res(this->cols, this->rows);
	for (size_t i = 0; i < this->rows; ++i) {
		for (size_t j = 0; j < this->cols; ++j) {
			res.matrix[j][i] = this->matrix[i][j];
		}
	}
	return res;
}

template<typename T>
MyMatrix<T> operator+(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs) {
	MyMatrix<T> res(lhs.rows, lhs.cols);
	for (size_t i = 0; i < lhs.rows; ++i) {
		for (size_t j = 0; j < lhs.cols; ++j) {
			res.matrix[i][j] = lhs(i, j) + rhs(i, j);
		}
	}
	return res;
}

template<typename T>
MyMatrix<T> operator-(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs) {
	MyMatrix<T> res(lhs.rows, lhs.cols);
	for (size_t i = 0; i < lhs.rows; ++i) {
		for (size_t j = 0; j < lhs.cols; ++j) {
			res.matrix[i][j] = lhs(i, j) - rhs(i, j);
		}
	}
	return res;
}

template<typename T>
MyMatrix<T> operator*(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs)
{
	MyMatrix<T> res(lhs.rows, rhs.cols, 0);
	if (lhs.cols != rhs.rows) // Two matrices must be matched in size to be able to perform multiplication
		return MyMatrix<T>();
	for (size_t i = 0; i < res.rows; ++i) {
		for (size_t j = 0; j < res.cols; ++j) {
			for (size_t k = 0; k < lhs.cols; ++k) {
				res.matrix[i][j] = res.matrix[i][j] + lhs(i, k) * rhs(k, j);
			}
		}
	}
	return res;
}

template<typename T>
MyMatrix<T> operator*(const T& lhs, const MyMatrix<T>& rhs)
{
	return rhs * lhs;
}

template<typename T>
MyMatrix<T> operator*(const MyMatrix<T>& lhs, const T& rhs)
{
	MyMatrix<T> res(lhs.rows, lhs.cols);
	for (size_t i = 0; i < lhs.rows; ++i) {
		for (size_t j = 0; j < lhs.cols; ++j) {
			res.matrix[i][j] = lhs(i, j) * rhs;
		}
	}
	return res;
}

template<typename T>
vector<T> operator*(const vector<T>& lhs, const MyMatrix<T>& rhs)
{
	return rhs * lhs;
}

template<typename T>
vector<T> operator*(const MyMatrix<T>& lhs, const vector<T>& rhs)
{
	vector<T> res(lhs.rows, 0);
	if (lhs.cols != rhs.size()) // The sizes of the matrix and the vector must be matched to be able to perform multiplication
		return vector<T>();
	for (size_t i = 0; i < lhs.rows; ++i) {
		for (size_t j = 0; j < lhs.cols; ++j) {
			res[i] = res[i] + lhs(i, j) * rhs[j];
		}
	}
	return res;
}

template<typename T>
bool operator==(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs)
{
	if (lhs.rows != rhs.rows || lhs.cols != rhs.cols)
		return false;
	for (int i = 0; i < lhs.rows; ++i) {
		for (int j = 0; j < lhs.cols; ++j) {
			if (lhs(i, j) != rhs(i, j))
				return false;
		}
	}
	return true;
}

template<typename T>
bool operator!=(const MyMatrix<T>& lhs, const MyMatrix<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T>
ostream& operator<<(ostream& out, const MyMatrix<T>& rhs) {
	out << "[" << endl;
	for (auto rowIter = rhs.matrix.begin(); rowIter != rhs.matrix.end(); ++rowIter) {
		out << " " << "[";
		for (auto iter = (*rowIter).begin(); iter != (*rowIter).end(); ++iter) {
			if (iter == (*rowIter).end() - 1)
				out << *iter;
			else
				out << *iter << ",";
		}
		out << "]" << endl;
	}
	out << "]";
	return out;
}

#endif