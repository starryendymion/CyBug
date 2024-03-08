#pragma once
#include "Linear/Vector.h"
#include <cmath>
#include <iostream>

class Vec2
{
    private:

    public:
        f32 m_X;
        f32 m_Y;
        Vec2()
            : m_X(0), m_Y(0) {}

        Vec2(float a, float b)
            : m_X(a), m_Y(b) {}

        Vec2(const Vec2& theVec)
            : m_X(theVec.m_X), m_Y(theVec.m_Y) {}

        Vec2(Vec2&& theVec)
            : m_X(theVec.m_X), m_Y(theVec.m_Y) {}

        /**
         * Returns X
         * @return f32 
         */
        inline f32 GetX() const {return m_X;}
        /**
         * Returns Y
         * @return f32 
         */
        inline f32 GetY() const {return m_Y;}
        inline void SetX(f32 a) {m_X = a;}
        inline void SetY(f32 a) {m_Y = a;}
        /**
         * Normalizes Vec2 to [0, 1]
         */
        void Normalize()
        {
            f32 aDistSq = SQ(m_X) + SQ(m_Y);
            f32 x = std::sqrt(aDistSq);
            this->m_X /= x;
            this->m_Y /= x;
        }
        /**
         * dot product of two Vec2s
         * @param  Vec2 theVec
         * @return f32
         */
        f32 dot(Vec2 theVec) {
            return (m_X * theVec.m_X) + (m_Y * theVec.m_Y);
        }

        Vec2 operator+(const Vec2& theVec) {
            return Vec2(m_X + theVec.m_X, m_Y + theVec.m_Y);
        }

        Vec2 operator*(f32 theFloat) {
            return Vec2(m_X * theFloat, m_Y * theFloat);
        }

        Vec2 operator-(const Vec2& theVec) {
            return Vec2(m_X - theVec.m_X, m_Y - theVec.m_Y);
        }

        Vec2& operator=(const Vec2& theVec) {
            if (this != &theVec)
            {
                m_X = theVec.m_X;
                m_Y = theVec.m_Y;
            }

            return *this;
        }

        Vec2& operator=(Vec2&& theVec) {
            if (this != &theVec)
            {
                m_X = theVec.m_X;
                m_Y = theVec.m_Y;
            }

            return *this;
        }


        bool operator==(const Vec2& theVec) {
            if (theVec.m_X == this->m_X && theVec.m_Y == this->m_Y) {
                return true;
            }
            return false;
        }
};
