#include "Matrix.h"

Matrix::Matrix(size_t column_size, size_t row_size)
{
    _col_size = column_size;
    _row_size = row_size;
    _matrix = create_matrix(column_size, row_size);
}

Matrix::Matrix(const Matrix& other)
{
    this->_col_size = other._col_size;
    this->_row_size = other._row_size;
    this->_matrix = create_matrix(other._col_size, other._row_size);
    for (size_t i = 0; i < this->_col_size; i++)
    {
        for (size_t j = 0; j < this->_row_size; j++)
        {
            this->_matrix[i][j] = other._matrix[i][j];
        }
    }
}

int& Matrix::at(size_t column, size_t row)
{
    return _matrix[column][row];
}

void Matrix::transpose_matrix()
{
    Matrix temp_matrix = *this;
    for (size_t i = 0; i < this->_col_size; i++)
    {
        for (size_t j = 0; j < this->_row_size; j++)
        {
            this->_matrix[i][j] = temp_matrix._matrix[j][i];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& mx)
{
    if (this->_col_size != mx._col_size || this->_row_size != mx._row_size) {
        throw new std::exception("Matrices must be of the same dimension");
    }
    this->_matrix = create_matrix(mx._col_size, mx._row_size);

    for (size_t i = 0; i < this->_col_size; i++)
    {
        for (size_t j = 0; j < this->_row_size; j++)
        {
            this->_matrix[i][j] =  mx._matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& mx)
{
    if (this->_col_size != mx._col_size || this->_row_size != mx._row_size) {
        throw new std::exception("Matrices must be of the same dimension");
    }
    Matrix temp_matrix(mx._col_size, mx._row_size);
    for (int i = 0; i < _col_size; i++)
    {
        for (int j = 0; j < _row_size; j++)
        {
            temp_matrix._matrix[i][j] = this->_matrix[i][j] - mx._matrix[i][j];
        }
    }
    return temp_matrix;
}

Matrix Matrix::operator+(const Matrix& mx)
{
    if (this->_col_size != mx._col_size || this->_row_size != mx._row_size) {
        throw new std::exception("Matrices must be of the same dimension");
    }
    Matrix temp_matrix(mx._col_size, mx._row_size);
    for (int i = 0; i < _col_size; i++)
    {
        for (int j = 0; j < _row_size; j++)
        {
            temp_matrix._matrix[i][j] = this->_matrix[i][j] + mx._matrix[i][j];
        }
    }
    return temp_matrix;
}


bool Matrix::operator==(const Matrix& mx)
{
    if (this->_col_size != mx._col_size || this->_row_size != mx._row_size) {
        throw new std::exception("Matrices must be of the same dimension");
    }
    for (size_t i = 0; i < mx._col_size; i++)
    {
        for (size_t j = 0; j < mx._row_size; j++)
        {
            if (this->_matrix[i][j] != mx._matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator>(const Matrix& mx)
{
    if (this->_col_size != mx._col_size || this->_row_size != mx._row_size) {
        throw new std::exception("Matrices must be of the same dimension");
    }
    int sum_first = 0;
    int sum_second = 0;
    for (size_t i = 0; i < mx._col_size; i++)
    {
        for (size_t j = 0; j < mx._row_size; j++)
        {
            sum_first += this->_matrix[i][j];
            sum_second += mx._matrix[i][j];
        }
    }
    return sum_first > sum_second;
}

bool Matrix::operator<(const Matrix& mx)
{
    return (!(*this > mx)) & *this != mx;
}

int** Matrix::create_matrix(size_t _col_size, size_t _row_size)
{
    int** _matrix;
    _matrix = new  int* [_col_size]();
    for (size_t i = 0; i < _col_size; i++)
    {
        _matrix[i] = new int[_row_size]();
        for (size_t j = 0; j < _row_size; j++)
        {
            _matrix[i][j] = 0;
        }
    }
    return _matrix;
}

void Matrix::destroy_matrix()
{
    for (size_t i = 0; i < _col_size; i++) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
    _matrix = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mx)
{
    for (size_t i = 0; i < mx._col_size; i++)
    {
        for (size_t j = 0; j < mx._row_size; j++)
        {
            os << mx._matrix[i][j] << ' ';
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& mx)
{
    for (size_t i = 0; i < mx._col_size; i++)
    {
        for (size_t j = 0; j < mx._row_size; j++)
        {
            is >> mx._matrix[i][j];
        }
    }
    return is;
}

Matrix operator*(const Matrix& matrix, int number)
{
    Matrix temp_matrix(matrix._col_size, matrix._row_size);
    for (int i = 0; i < matrix._col_size; i++)
    {
        for (int j = 0; j < matrix._row_size; j++)
        {
            temp_matrix._matrix[i][j] = matrix._matrix[i][j] * number;
        }
    }
    return temp_matrix;
}

Matrix operator*(int number, const Matrix& matrix)
{
    return matrix * number;
}
