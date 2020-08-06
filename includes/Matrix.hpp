#if !defined(__MATRIX__)
# define __MATRIX__

# include <vector>
# include <iostream>

using namespace std;
template <typename T>
class Matrix
{
	vector<vector <T> > matrix;
	unsigned nrow;
	unsigned ncol;

	public:


	Matrix(size_t nrow_, size_t ncol_);
	Matrix(const vector<vector<T> >& matrix_);
	Matrix(const Matrix<T>& matrix_);

	Matrix<T>	transpose();

	/* Matrix with Matrix operators */
	Matrix<T>& 	operator=(const Matrix<T> &b_matrix);
	Matrix<T> 	operator+(const Matrix<T> &b_matrix);
	Matrix<T> 	operator-(const Matrix<T> &b_matrix);
	Matrix<T> 	operator*(const Matrix<T> &b_matrix);
	Matrix<T> 	operator/(const Matrix<T> &b_matrix);
	Matrix<T>&	operator+=(const Matrix<T> &b_matrix);
	Matrix<T>&	operator-=(const Matrix<T> &b_matrix);
	Matrix<T>&	operator*=(const Matrix<T> &b_matrix);
	Matrix<T>& 	operator/=(const Matrix<T> &b_matrix);

	/* Matrix with Scalar operators */
	Matrix<T>	operator+(const T& val);
	Matrix<T>	operator-(const T& val);
	Matrix<T>	operator*(const T& val);
	Matrix<T>	operator/(const T& val);
	Matrix<T>&	operator+=(const T& val);
	Matrix<T>&	operator-=(const T& val);
	Matrix<T>&	operator*=(const T& val);
	Matrix<T>&	operator/=(const T& val);
	void showMatrix();

};
/* --- Constructors --- */

template<typename T>
Matrix<T>::Matrix(size_t nrow_, size_t ncol_)
{
	this->matrix.resize(nrow_, vector<T>(ncol_, 0));
	this->nrow = nrow_;
	this->ncol = ncol_;
}

template<typename T>
Matrix<T>::Matrix(const vector<vector<T> >& matrix_)
{
	this->matrix = matrix_;
	this->nrow = matrix_.size();
	this->ncol = matrix_.at(0).size();
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> & matrix_)
{
	this->matrix = matrix_.matrix;
	this->ncol = matrix_.ncol;
	this->nrow = matrix_.nrow;
}

/* --- Usefull Functions --- */
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> result(this->ncol, this->nrow);
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < this->ncol; j++)
		{
			result.matrix.at(j).at(i) = this->matrix.at(i).at(j);
		}
	}
	return (result);
}

/* --- Mathematical Operators --- */

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &b_matrix)
{
	this->matrix = b_matrix.matrix;
	this->ncol = b_matrix.ncol;
	this->nrow = b_matrix.nrow;
	return (*this);
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& b_matrix)
{
	Matrix<T> result(this->nrow, this->ncol);
	if (this->nrow == b_matrix.nrow && this->nrow == b_matrix.ncol)
	{
		for (size_t i = 0; i < this->nrow; i++)
		{
			for (size_t j = 0; j < this->ncol; j++)
			{
				result.matrix.at(i).at(j) = this->matrix.at(i).at(j) + b_matrix.matrix.at(i).at(j);
			}
		}
	}
	return (result);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& b_matrix)
{
	Matrix<T> result(this->nrow, this->ncol);
	if (this->nrow == b_matrix.nrow && this->nrow == b_matrix.ncol)
	{
		for (size_t i = 0; i < this->nrow; i++)
		{
			for (size_t j = 0; j < this->ncol; j++)
			{
				result.matrix.at(i).at(j) = this->matrix.at(i).at(j) - b_matrix.matrix.at(i).at(j);
			}
		}
	}
	return (result);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& b_matrix)
{
	Matrix<T> result(this->nrow, b_matrix.ncol);
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < b_matrix.ncol; j++)
		{
			for (size_t k = 0; k < this->ncol; k++)
			{
				result.matrix.at(i).at(j) += this->matrix.at(i).at(k) * b_matrix.matrix.at(k).at(j);
			}
		}
	}
	return (result);
}
/*  --- TO BE ADDED ---
template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& b_matrix)
{

}
*/

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& b_matrix)
{
	*this = *this + b_matrix;
	return (*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& b_matrix)
{
	*this = *this - b_matrix;
	return (*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& b_matrix)
{
	*this = *this * b_matrix;
	return (*this);
}
/*  --- TO BE ADDED ---
template<typename T>
Matrix<T>& Matrix<T>::operator/=(const Matrix<T>& b_matrix)
{

}
*/

template<typename T>
Matrix<T> Matrix<T>::operator+(const T& val)
{
	Matrix result(*this);
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < this->ncol; j++)
		{
			result.matrix.at(i).at(j) += val;
		}
	}
	return (result);
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T& val)
{
	Matrix result(*this);
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < this->ncol; j++)
		{
			result.matrix.at(i).at(j) -= val;
		}
	}
	return (result);
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T& val)
{
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < this->ncol; j++)
		{
			this->matrix.at(i).at(j) *= val;
		}
	}
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T& val)
{
	for (size_t i = 0; i < this->nrow; i++)
	{
		for (size_t j = 0; j < this->ncol; j++)
		{
			this->matrix.at(i).at(j) /= val;
		}
	}
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const T& val)
{
	*this = *this + val;
	return (*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const T& val)
{
	*this = *this - val;
	return (*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T& val)
{
	*this = *this * val;
	return (*this);
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T& val)
{
	*this = *this / val;
	return (*this);
}

/* --- Show Functions --- */

template<typename T>
void Matrix<T>::showMatrix()
{
	for (size_t i = 0; i < this->nrow; i++)
	{
		for(size_t j = 0; j < this->ncol; j++)
		{
			cout << this->matrix.at(i).at(j) << " ";
		}
		cout << endl;
	}
}

#endif
