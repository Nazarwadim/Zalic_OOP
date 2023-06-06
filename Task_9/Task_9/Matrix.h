/*
* �������� 9
* c������� ���� Matrix ��� ������ � ���������. 
* ������ ����� � ���������� �����, ������� ����� �� ������� ��������.
* 1) ������ ���� ������� �������� ��������� (������������� �������� -),
*
* 2) ��������� ���� ������� �������� ��������� (������������� �������� +),
* 3) ��������� ���� ������� �������� ��������� (������������� ��������� >, <, ==, !=),
* 4) �������� ������� �� �����: ����� ������� ������� ��������� �� ������ ����� (������������� �������� *),
* 5) �������� �������� �� ��������� ������� (������������� ��������� << �� >>).
* ���. �������.(+2). ���������� �������� �������������� �������. 
*/
#pragma once
#include <iostream>
class Matrix {
public:
    Matrix(size_t column_size, size_t row_size);
    Matrix(const Matrix& other);

    int& at(size_t column, size_t row);
    void transpose_matrix();

    Matrix& operator = (const Matrix& mx);
    Matrix operator - (const Matrix& mx);
    Matrix operator + (const Matrix& mx);

    bool operator ==(const Matrix& mx);
    bool operator !=(const Matrix& mx)
    {
        return !(*this == mx);
    }
    bool operator >(const Matrix& mx);
    bool operator <(const Matrix& mx);

    friend std::ostream& operator << (std::ostream& os, const Matrix& mx);
    friend std::istream& operator >> (std::istream& is, Matrix& mx);
    friend Matrix operator*(const Matrix& matrix, int number);
    friend Matrix operator*(int number, const Matrix& matrix);
    ~Matrix()
    {
        destroy_matrix();
    }
private:
    int** create_matrix(size_t _col_size, size_t _row_size);
    void destroy_matrix();

    size_t _col_size;
    size_t _row_size;
    int** _matrix;
};

std::ostream& operator<<(std::ostream& os, const Matrix& mx);

std::istream& operator>>(std::istream& is, Matrix& mx);

Matrix operator*(const Matrix& matrix, int number);

Matrix operator*(int number, const Matrix& matrix);
