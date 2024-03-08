#include "Vector.h"
#include "defines.h"

#include "Physics/Vec2.h"
#include "Physics/PhysicsObject.h"

#include <cstdlib>
#include <cwchar>
#include <iostream>
#include <new>

#define ASSERT_VECTOR_SIZE(a, b) \
    a.m_Size == b.m_Size ? true : false

template <class T>
Vector<T>::Vector()
    : m_Size(0), m_BufferSize(3)
{
    m_Data = (T*)::operator new(m_BufferSize * sizeof(T));
}

template<class T>
void Vector<T>::IncreaseBuffer(size_t theNewBuffer)
{
    m_BufferSize = theNewBuffer;

    T* aNewData = (T*)::operator new(theNewBuffer * sizeof(T));

    for (size_t i = 0; i < m_Size; ++i)
    {
        aNewData[i] = std::move(m_Data[i]);
    }

    for (size_t i = 0; i < m_Size; ++i)
    {
        m_Data[i].~T();
    }

    ::operator delete(m_Data, m_BufferSize * sizeof(T));

    m_Data = aNewData;
}

template <class T>
Vector<T>::Vector(size_t theBufferSize)
    : m_Size(0), m_BufferSize(theBufferSize)
{
    m_Data = (T*)::operator new(m_BufferSize * sizeof(T));
}

template<class T>
Vector<T>::Vector(const Vector& theOther)
    : m_Size(theOther.m_Size), m_BufferSize(theOther.m_BufferSize)
{
    m_Data = (T*)::operator new(m_BufferSize * sizeof(T));

    for (size_t i = 0; i < theOther.m_Size; ++i)
    {
        m_Data[i] = theOther.m_Data[i];
    }
}

template<class T>
Vector<T>::Vector(Vector&& theOther)
    : m_Size(theOther.m_Size), m_BufferSize(theOther.m_BufferSize)
{
    m_Data = theOther.m_Data;

    theOther.m_Data = nullptr;
}

template<class T>
Vector<T>::~Vector()
{
    Clear();
    ::operator delete(m_Data, m_BufferSize * sizeof(T));
}


template <class T>
void Vector<T>::Print() {
    for (int i = 0; i < this->m_Size; i++) {
        std::cout << this->m_Data[i] << " ";
    }
    std::cout << "\n";
}


template <>
void Vector<Vec2>::Print() {
    for (int i = 0; i < this->m_Size; i++) {
        std::cout << this->m_Data[i].GetX() << ", " << this->m_Data[i].GetY() << " ";
    }
    std::cout << "\n";
}

template<class T>
void Vector<T>::PushBack(const T& theElement)
{
    if (m_Size >= m_BufferSize)
    {
        if (m_BufferSize == 0)
            m_BufferSize = 2;
        IncreaseBuffer(m_BufferSize + (m_BufferSize >> 1));
    }

    m_Data[++m_Size] = theElement;
}

template<class T>
void Vector<T>::PushBack(T&& theElement)
{
    if (m_Size >= m_BufferSize)
    {
        if (m_BufferSize == 0)
            m_BufferSize = 2;
        IncreaseBuffer(m_BufferSize + (m_BufferSize >> 1));
    }

    m_Data[++m_Size] = std::move(theElement);
}

template<class T>
template<typename ...Args>
inline T& Vector<T>::EmplaceBack(Args && ...args)
{
    if (m_Size >= m_BufferSize)
    {
        if (m_BufferSize == 0)
            m_BufferSize = 2;
        IncreaseBuffer(m_BufferSize + (m_BufferSize >> 1));
    }
    new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
    return m_Data[m_Size++];
}

template<class T>
void Vector<T>::Pop()
{
    if (m_Size > 0)
    {
        m_Data[--m_Size].~T();
    }
    else
    {
        std::cerr << "Can't Pop() on an empty vector\n";
    }
}

template<class T>
T& Vector<T>::Last()
{
    return this->m_Data[m_Size];
}

template<class T>
void Vector<T>::Clear()
{
    for (size_t i = 0; i < m_Size; ++i)
    {
        m_Data[i].~T();
    }
    m_Size = 0;
}

template <class T>
T& Vector<T>::operator[](size_t theIndex)
{
    return this->m_Data[theIndex];
}

template<class T>
const T& Vector<T>::operator[](size_t theIndex) const
{
    return this->m_Data[theIndex];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& theVector) {
    if (this != &theVector)
    {
        T* aNewData = (T*)::operator new(m_BufferSize * sizeof(T));;


        for (size_t i = 0; i < theVector.m_Size; ++i)
        {
            aNewData[i] = theVector.m_Data[i];
        }
        for (size_t i = 0; i < theVector.m_Size; ++i)
        {
            m_Data[i].~T();
        }
        ::operator delete(m_Data, m_BufferSize * sizeof(T));

        m_Data = aNewData;
        m_Size = theVector.m_Size;
        m_BufferSize = theVector.m_BufferSize;
    }

    return *this;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector&& theVector)
{
    if (this != &theVector)
    {
        #error C2352 operatoer=: a call of a non-static member function requires an object 
        m_Data = theVector.m_Data;
        theVector.m_Data = nullptr;
        m_Size = theVector.m_Size;
        m_BufferSize = theVector.m_BufferSize;
    }

    return *this;

}

template <class T>
bool Vector<T>::operator==(const Vector<T>& theVector) {
    if (this->m_Size != theVector.m_Size) {
        std::cerr << "Operating vectors of different sizes\n";
        return false;
    }
    bool equal = true;
    for (int i = 0; i < m_Size; i++) {
        if (this->m_Data[i] != theVector[i]) {
            equal = false;
            break;
        }
    }
    return equal;
}

template class Vector<i8 >;
template class Vector<i16>;
template class Vector<i32>;
template class Vector<i64>;
template class Vector<u8 >;
template class Vector<u16>;
template class Vector<u32>;
template class Vector<u64>;
template class Vector<f32>;
template class Vector<f64>;
template class Vector<bool>;
template class Vector<char>;
template class Vector<Vec2>;
template class Vector<PhysicsObject*>;
