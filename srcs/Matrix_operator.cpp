#include "../includes/Matrix.hpp"

Matrix operator+(Matrix const &a, Matrix const &b)
{
	if (a.matrix.size() == b.matrix.size() && a.matrix.at(0).size() == b.matrix.at(0).size())
	{
		size_t row_size = a.matrix.size();
		size_t col_size = a.matrix.at(0).size();
		Matrix sum(row_size, col_size);
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				sum.matrix.at(i).at(j) = a.matrix.at(i).at(j) + b.matrix.at(i).at(j);
			}
		}
		return (sum);
	}
	return (Matrix(0,0));
}

Matrix operator-(Matrix const &a, Matrix const &b)
{
	if (a.matrix.size() == b.matrix.size() && a.matrix.at(0).size() == b.matrix.at(0).size())
	{
		size_t row_size = a.matrix.size();
		size_t col_size = a.matrix.at(0).size();
		Matrix sum(row_size, col_size);
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				sum.matrix.at(i).at(j) = a.matrix.at(i).at(j) - b.matrix.at(i).at(j);
			}
		}
		return (sum);
	}
	return (Matrix(0,0));
}

Matrix operator*(Matrix const &a, Matrix const &b)
{
	if (a.matrix.size() == b.matrix.at(0).size())
	{
		size_t a_row = a.matrix.size();
		size_t a_col = a.matrix.at(0).size();
		size_t b_col = b.matrix.at(0).size();
		Matrix mult(a_row, b_col);
		for (int i = 0; i < a_row; i++)
		{
			for (int j = 0; j < b_col; j++)
			{
				for (int k = 0; k < a_col; k++)
				{
					mult.matrix.at(i).at(j) += a.matrix.at(i).at(k) * b.matrix.at(k).at(j);
				}
			}
		}
	}
	return (Matrix(0,0));
}

Matrix operator/(Matrix const &a, Matrix const &b)
{
	return (Matrix(0,0));
}

void Matrix::operator+=(Matrix const &a)
{
	if (a.matrix.size() == this->matrix.size() && a.matrix.at(0).size() == this->matrix.at(0).size())
	{
		size_t row_size = a.matrix.size();
		size_t col_size = a.matrix.at(0).size();
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				this->matrix.at(i).at(j) = a.matrix.at(i).at(j) + this->matrix.at(i).at(j);
			}
		}
	}
}

void Matrix::operator-=(Matrix const &a)
{
	if (a.matrix.size() == this->matrix.size() && a.matrix.at(0).size() == this->matrix.at(0).size())
	{
		size_t row_size = a.matrix.size();
		size_t col_size = a.matrix.at(0).size();
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				this->matrix.at(i).at(j) = a.matrix.at(i).at(j) - this->matrix.at(i).at(j);
			}
		}
	}
}

void Matrix::operator*=(Matrix const &a)
{
	if (a.matrix.size() == this->matrix.at(0).size())
	{
		size_t row = this->matrix.size();
		size_t col = this->matrix.at(0).size();
		size_t a_col = a.matrix.at(0).size();
		Matrix mult(row, a_col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < a_col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					this->matrix.at(i).at(j) += this->matrix.at(i).at(k) * a.matrix.at(k).at(j);
				}
			}
		}
	}
}

void Matrix::operator/=(Matrix const &a)
{

}
