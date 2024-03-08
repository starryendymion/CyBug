#pragma once
#include "defines.h"

#include "Vector.h"
#include <iostream>

namespace Cybug {
    template<typename T>
    class Matrix
    {
    public:
        class DoubleSubscript
        {
        private:
            size_t m_i;
            Matrix<T>& m_array2d;

        public:
            DoubleSubscript(size_t _i, Matrix<T>& _array2d)
                : m_i(_i), m_array2d(_array2d) {}

            T& operator[](size_t _j)
            {
                return m_array2d.m_Data[_j + m_i * m_array2d.m_Y];
            }
        };

        Matrix() = delete;
        Matrix(size_t theX, size_t theY);
        Matrix(const Matrix& theMatrix);
        ~Matrix();

        DoubleSubscript operator[](size_t _i)
        {
            DoubleSubscript second_subscript(_i, *this);
            return second_subscript;
        }

        void Print();
        Matrix<T> Transpose();
        i64 Trace();

        /**
         * 
         * @param  size_t theRow 
         * @return Vector<T> 
         */
        Vector<T>& GetRow(size_t theRow);
        /**
         * 
         * @param  size_t theCol  
         * @return Vector<T>     
         */
        Vector<T>& GetColumn(size_t theCol);
        /**
         * 
         * @return size_t 
         */
        inline size_t GetRowSize() const {return m_X;}
        /**
         * 
         * @return size_t 
         */
        inline size_t GetColumnSize() const {return m_Y;}
        /**
         * 
         * @param  size_t theX 
         * @param  size_t theY 
         * @return T           
         */
        inline T At(size_t theX, size_t theY) const;

    private:
        size_t m_X, m_Y;
        size_t m_Size;
        T* m_Data;
    };
}
