#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyMatrix
{
    T** ptr;
    int rows;
    int cols;
public:
    MyMatrix();
    MyMatrix(int _str, int _st);
    MyMatrix(const MyMatrix<T>& m1);

    void SetEl(int r, int c, T newEl) const;
    T GetEl(int r, int c) const;

    MyMatrix<T> Sum(const MyMatrix<T>& m1) const;
    MyMatrix<T> Mul(const MyMatrix<T>& m1) const;
    MyMatrix<T> Transpose() const;

    void Input();
    void Print() const;

    T Min();
    T Max();

    ~MyMatrix();
};

template <typename T>
MyMatrix<T>::MyMatrix()
{
    ptr = nullptr;
    rows = cols = 0;
}

template <typename T>
MyMatrix<T>::MyMatrix(int _str, int _st)
{
    rows = _str;
    cols = _st;
    ptr = new T * [rows];

    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new T[cols];;
    }
}

template <typename T>
MyMatrix<T>::MyMatrix(const MyMatrix<T>& m1)
{
    rows = m1.rows;
    cols = m1.cols;

    ptr = new T * [rows];
    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new T[cols];
        for (int j = 0; j < cols; j++)
        {
            ptr[i][j] = m1.ptr[i][j];
        }
    }
}

template <typename T>
void MyMatrix<T>::SetEl(int r, int c, T newEl) const
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        ptr[r][c] = newEl;
    }
}

template <typename T>
T MyMatrix<T>::GetEl(int r, int c) const
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)
    {
        cout << "ERROR" << endl;
        return T();
    }
    else
    {
        return ptr[r][c];
    }
}

template <typename T>
MyMatrix<T> MyMatrix<T>::Sum(const MyMatrix<T>& m1) const
{
    if (rows == m1.rows && cols == m1.cols)
    {
        MyMatrix<T> sum(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sum.ptr[i][j] = this->ptr[i][j] + m1.ptr[i][j];
            }
        }
        return sum;
    }
    else
    {
        cout << "ERROR" << endl;
        return MyMatrix<T>(0, 0);
    }
}

template <typename T>
MyMatrix<T> MyMatrix<T>::Mul(const MyMatrix<T>& m1) const
{
    if (cols == m1.rows)
    {
        MyMatrix<T> mul(rows, m1.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m1.cols; j++)
            {
                mul.ptr[i][j] = T();

                for (int k = 0; k < cols; k++)
                {
                    mul.ptr[i][j] += this->ptr[i][k] * m1.ptr[k][j];
                }
            }
        }
        return mul;
    }
    else
    {
        cout << "ERROR" << endl;
        return MyMatrix<T>(0, 0);
    }
}

template <typename T>
MyMatrix<T> MyMatrix<T>::Transpose() const
{
    MyMatrix<T> transposed(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transposed.ptr[j][i] = this->ptr[i][j];
        }
    }
    return transposed;
}

template <typename T>
void MyMatrix<T>::Input()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr[i][j] = rand() % 10;
        }
    }
}

template <typename T>
void MyMatrix<T>::Print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ptr[i][j] << "\t";
        }
        cout << endl << endl;
    }
}

template <typename T>
T MyMatrix<T>::Min()
{
    int min = ptr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (min > ptr[i][j])
            {
                min = ptr[i][j];
            }
        }
    }

    return min;
}

template <typename T>
T MyMatrix<T>::Max()
{
    int max = ptr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (max < ptr[i][j])
            {
                max = ptr[i][j];
            }
        }
    }

    return max;
}

template <typename T>
MyMatrix<T>::~MyMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
}