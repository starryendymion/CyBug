#pragma once

#include "defines.h"

#include <utility>

#ifdef __clang__
using std::size_t;
#endif

#ifdef __GNUG__ 
#include <cstddef>
#endif

template <class T>
class Vector {
    private:
        T* m_Data;
        size_t m_Size;
        size_t m_BufferSize;
        /**
         * Reserves param size memory
         * @param  size_t theNewBuffer
         */
        void IncreaseBuffer(size_t theNewBuffer);

    public:
        Vector();
        Vector(size_t theSize);
        Vector(const Vector&);
        Vector(Vector&&);
        ~Vector();

        /**
         * Stdout the elements of the Vector
         */
        void Print();

        /**
         * Returns the current size
         * @return size_t
         */
        inline size_t GetSize() const {return (size_t)&m_Size;}
        /**
         * Pushes the element into the Vector
         * @param T
         */
        void PushBack(const T&);
        /**
         * Pushes the element into the Vector
         * @param  T&
         */
        void PushBack(T&&);
        /**
         * Deletes the element
         */
        void Pop();
        /**
         * Returns the element at Last element pushed
         * @return T
         */
        T& Last();

        /**
         * Pushed back elements in place
         * @param  Args&... args
         * @return T
         */
        template<typename... Args>
        T& EmplaceBack(Args&&... args);

        /**
         * Clears all the elements
         */
        void Clear();

        T& operator[](size_t);
        const T& operator[](size_t) const;

        Vector<T>& operator=(const Vector&);
        Vector<T>& operator=(Vector&&);

        bool operator==(const Vector&);
};
