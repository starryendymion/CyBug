#include "Matrix.h"


namespace Cybug {
template<typename T>
inline Matrix<T>::Matrix(size_t theX, size_t theY)
	: m_X(theX), m_Y(theY)
{
	m_Size = m_X * m_Y;
	m_Data = new T(m_Size);
}

template<typename T>
Matrix<T>::Matrix(const Matrix& theMatrix)
{
	m_Size = theMatrix.m_Size;
	m_Data = new T[m_Size];
	m_X = theMatrix.m_X;
	m_Y = theMatrix.m_Y;
	for (size_t i = 0; i < m_Size; ++i)
	{
		m_Data[i] = theMatrix.m_Data[i];
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	delete[] m_Data;
}

template<typename T>
void Matrix<T>::Print()
{
	for (size_t i = 0; i < m_X; ++i)
	{
		for (size_t j = 0; j < m_Y; ++j)
		{
			std::cout << m_Data[i*m_Y + j] << ' ';
		}
		std::cout << '\n';
	}
}

template<typename T>
Matrix<T> Matrix<T>::Transpose()
{
	Matrix<T> aOther(m_Y, m_X);
	for (size_t i = 0; i < m_X; ++i)
	{
		for (size_t j = 0; j < m_Y; ++j)
		{
			aOther.m_Data[j * m_X + i] = this->At(i, j);
		}
	}
	return aOther;
}

template<typename T>
i64 Matrix<T>::Trace()
{
	i64 aTrace = 0;
	int aMinDimension = MIN(m_X, m_Y);

	for (size_t i = 0; i < aMinDimension; ++i)
	{
		aTrace += m_Data[i * m_Y + i];
	}
	return i64();
}

template<typename T>
Vector<T>& Matrix<T>::GetRow(size_t theRow)
{
	if (theRow > m_X)
	{
		std::cerr << "Out Of Bounds\n";
	}
	Vector<T> aRow;
	for (size_t i = 0; i < m_Y; ++i)
	{
		aRow.PushBack(m_Data[theRow * m_Y + i]);
	}
	return aRow;
}

template<typename T>
Vector<T>& Matrix<T>::GetColumn(size_t theCol)
{
	if (theCol> m_Y)
	{
		std::cerr << "Out Of Bounds\n";
	}
	Vector<T> aCol;
	for (size_t i = 0; i < m_X; ++i)
	{
		aCol.PushBack(m_Data[i * m_Y + theCol]);
	}
	return aCol;
}

template<typename T>
inline T Matrix<T>::At(size_t theX, size_t theY) const
{
	return m_Data[theX * m_Y + theY];
}

}
