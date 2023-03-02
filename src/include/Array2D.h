#pragma once
#include <stdint.h>
#include <algorithm>

template<typename T=char>
class Array2D
{
private:
    uint32_t NRow;
    uint32_t NCol;
    T* m_data;
public:
    Array2D(uint32_t NRow, uint32_t NCol);
    ~Array2D();

// there are two method to prevent an object copy.
// 1. private copy constructor and copy assignment operator
// private:
//     Array2D(const Array2D&);
//     Array2D& operator=(const Array2D&);
    Array2D(const Array2D&) = delete;
    Array2D& operator=(const Array2D&) = delete;

    T& operator() (int row, int col);
    T* operator[](const int row);
    const T* operator[](const int row) const;

    void fill(const T v);
};

template<typename T>
Array2D<T>::Array2D(uint32_t NRow, uint32_t NCol)
    : NRow(NRow), NCol(NCol)
{
    m_data = new T[NRow * NCol];
}

template<typename T>
Array2D<T>::~Array2D()
{
    delete [] m_data;
}

template<typename T>
inline T& Array2D<T>::operator()(int row, int col)
{
    return this->m_data[row * this->NRow + col];
}

template <typename T>
inline T* Array2D<T>::operator[](const int row)
{
    return &(this->m_data[row * this->NRow]);
}

template <typename T>
inline const T* Array2D<T>::operator[](const int row) const
{
    return &(this->m_data[row * this->NRow]);
}

template<typename T>
void Array2D<T>::fill(const T v)
{
    std::fill(this->m_data, this->m_data + this->NRow * this->NRow, v);
}
