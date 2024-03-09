#pragma once
#include "defines.h"
#include "Physics/Vec2.h"

class PhysicsObject
{
public:
    PhysicsObject(Vec2 theVelocity, Vec2 thePosition,
                  bool theGravityEnabled, bool theCollisionEnabled)
        : m_Velocity(theVelocity), m_Position(thePosition),
          m_GravityEnabled(theGravityEnabled), m_CollisionEnabled(theCollisionEnabled) {}

    inline void SetVelocity(const Vec2& theVelocity) { m_Velocity = theVelocity; }
    inline void SetPosition(const Vec2& thePosition) { m_Position = thePosition; }

    inline void SetVelocity(f32 theX, f32 theY) { m_Velocity = Vec2(theX, theY); }
    inline void SetPosition(f32 theX, f32 theY) { m_Position = Vec2(theX, theY); }

    inline Vec2 GetVelocity() const { return m_Velocity; }
    inline Vec2 GetPosition() const { return m_Position; }

    inline bool IsGravityEnabled() const { return m_GravityEnabled; }
    inline bool IsCollisionEnabled() const { return m_CollisionEnabled; }

protected:
    Vec2 m_Velocity;
    Vec2 m_Position;

    bool m_GravityEnabled;
    bool m_CollisionEnabled;
};
