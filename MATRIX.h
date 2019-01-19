#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

using namespace std;

template <class T>
class MATRIX {

private:
	// MATRIX data member 
	int cols_;
	int rows_;
	int depth_;
	T ***p;
    // dynamic allocate space for MATRIX object
	void allocSpace(); 
public:
	MATRIX(int, int, int);
	MATRIX();
	~MATRIX();
	MATRIX(const MATRIX&);
	MATRIX& operator=(const MATRIX&);

	inline T& operator()(int x, int y, int z) { return p[x][y][z]; }

	// Overload operator
	MATRIX& operator+=(const MATRIX&);
	MATRIX& operator-=(const MATRIX&);
	MATRIX& operator*=(const MATRIX&);
	MATRIX& operator*=(double);
	MATRIX& operator/=(double);

	// Tool Member Function
	void print_matrix();

	// Get Private Data Member
	int get_cols_() const;
	int get_rows_() const;
	int get_depth_() const;
};


/******************************************* GET/SET MEMBER FUNCTIONS ****************************************/
template <class T>
int MATRIX<T>::get_cols_() const { return cols_; }

template <class T>
int MATRIX<T>::get_rows_() const { return rows_; }

template <class T>
int MATRIX<T>::get_depth_() const { return depth_; }

/******************************************** NON-MEMBER FUNCTIONS *******************************************/
template <class T>
MATRIX<T> operator+(const MATRIX<T>& m1, const MATRIX<T> m2) {
	
	if (m1.get_cols_() != m2.get_cols_() || m1.get_rows_() != m2.get_rows_() || m1.get_depth_() != m2.get_depth_()) {
		cout << "Sizes are different." << endl;
		cout << "First Parameter Dimension(" 
			 << m1.get_cols_() << ',' << m1.get_rows_() << ',' << m1.get_depth_() << ")" << endl;
		cout << "Second Parameter Dimension("
			<< m2.get_cols_() << ',' << m2.get_rows_() << ',' << m2.get_depth_() << ")" << endl;
		terminate();
	}
	else {
		MATRIX<T> temp(m1);
		return (temp += m2);
	}
}

template <class T>
MATRIX<T> operator-(const MATRIX<T>& m1, const MATRIX<T> m2) {
	if (m1.get_cols_() != m2.get_cols_() || m1.get_rows_() != m2.get_rows_() || m1.get_depth_() != m2.get_depth_()) {
		cout << "Sizes are different." << endl;
		cout << "First Parameter Dimension("
			<< m1.get_cols_() << ',' << m1.get_rows_() << ',' << m1.get_depth_() << ")" << endl;
		cout << "Second Parameter Dimension("
			<< m2.get_cols_() << ',' << m2.get_rows_() << ',' << m2.get_depth_() << ")" << endl;
		terminate();
	}
	else {
		MATRIX<T> temp(m1);
		return (temp -= m2);
	}
}

template <class T>
MATRIX<T> operator*(const MATRIX<T>& m1, const MATRIX<T> m2) {
	if (m1.get_cols_() != m2.get_rows_() || m1.get_depth_() != m2.get_depth_()) {
		cout << "Sizes are different." << endl;
		cout << "First Parameter Dimension("
			<< m1.get_cols_() << ',' << m1.get_rows_() << ',' << m1.get_depth_() << ")" << endl;
		cout << "Second Parameter Dimension("
			<< m2.get_cols_() << ',' << m2.get_rows_() << ',' << m2.get_depth_() << ")" << endl;
		terminate();
	}
	else {
		MATRIX<T> temp(m1);
		return (temp *= m2);
	}
}

template <class T>
MATRIX<T> operator*(const MATRIX<T>& m1, const double num) {
	MATRIX<T> temp(m1);
	return (temp *= num);
}

template <class T>
MATRIX<T> operator/(const MATRIX<T>& m1, const double num) {
	MATRIX<T> temp(m1);
	return (temp /= num);
}

/****************************************** Private Member Function ******************************************/

template <class T>
void MATRIX<T>::allocSpace()
{
	p = new T**[depth_];

	for (int i = 0; i < depth_; ++i) {
		p[i] = new T*[rows_];
		for (int j = 0; j < rows_; ++j)
			p[i][j] = new T[cols_];
	}
}

/****************************************** Public Member Function ******************************************/
template <class T>
MATRIX<T>::MATRIX() : depth_(1), rows_(1), cols_(1)
{
	allocSpace();
	p[0][0][0] = 0;
}

template <class T>
MATRIX<T>::MATRIX(int depth, int rows, int cols) : depth_(depth), rows_(rows), cols_(cols) {
	allocSpace();
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k)
				p[i][j][k] = 0;
		}
	}
}

template <class T>
MATRIX<T>::~MATRIX() {
	for (int i = 0; i < depth_; ++i)
	{
		for (int j = 0; j < rows_; ++j)
			delete[] p[i][j];
		delete[] p[i];
	}
	delete[] p;
}

template <class T>
MATRIX<T>::MATRIX(const MATRIX<T>& m) : depth_(m.depth_), rows_(m.rows_), cols_(m.cols_)
{
	allocSpace();
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k)
				p[i][j][k] = m.p[i][j][k];
		}
	}
}

template <class T>
MATRIX<T>& MATRIX<T>::operator=(const MATRIX<T>& m)
{
	if (this == &m) { // 避免重覆給值(省時間)
		return *this;
	}

	// 如果 rows, cols, depth 不相同，必須先刪除原本的並分配一個新的空間
	if (rows_ != m.rows_ || cols_ != m.cols_ || depth_ != m.depth_) {
		for (int i = 0; i < depth_; ++i)
		{
			for (int j = 0; j < rows_; ++j)
				delete[] p[i][j];
			delete[] p[i];
		}
		delete[] p;

		rows_ = m.rows_;
		cols_ = m.cols_;
		depth_ = m.depth_;
		allocSpace();
	}

	// Assign value
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k)
				p[i][j][k] = m.p[i][j][k];
		}
	}

	return *this;
}

template <class T>
MATRIX<T>& MATRIX<T>::operator+=(const MATRIX<T>& m) {
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k) {
				p[i][j][k] += m.p[i][j][k];
			}
		}
	}
	return *this;
}

template <class T>
MATRIX<T>& MATRIX<T>::operator-=(const MATRIX<T>& m) {
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k) {
				p[i][j][k] -= m.p[i][j][k];
			}
		}
	}
	return *this;
}

template <class T>
MATRIX<T>& MATRIX<T>::operator*=(const MATRIX<T>& m) {
	
	MATRIX<T> temp(m.depth_, rows_, m.cols_);
	for (int d = 0; d < temp.depth_; ++d) {
		for (int i = 0; i < temp.rows_; ++i) {
			for (int j = 0; j < temp.cols_; ++j) {
				for (int k = 0; k < cols_; ++k) {
					temp.p[d][i][j] += (p[d][i][k] * m.p[d][k][j]);
				}
			}
		}
	}
	return (*this = temp);
}

template <class T>
MATRIX<T>& MATRIX<T>::operator*=(const double num) {
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k) {
				p[i][j][k] *= num;
			}
		}
	}
	return *this;
}

template <class T>
MATRIX<T>& MATRIX<T>::operator/=(const double num) {
	for (int i = 0; i < depth_; ++i) {
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k) {
				p[i][j][k] /= num;
			}
		}
	}
	return *this;
}

template <class T>
void MATRIX<T>::print_matrix() {
	for (int i = 0; i < depth_; ++i) {
		cout << "depth:" << i << endl;
		for (int j = 0; j < rows_; ++j) {
			for (int k = 0; k < cols_; ++k) {
				cout << p[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

#endif