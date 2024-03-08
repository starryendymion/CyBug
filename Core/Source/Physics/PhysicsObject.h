#pragma once
#include "defines.h"

#include "Physics/Vec2.h"

class PhysicsObject
{
	PhysicsObject(Vec2 theVelocity, Vec2 thePosition,
            bool theGravityEnabled, bool theCollisionEnabled)
		: m_Velocity(theVelocity), m_Position(thePosition), m_GravityEnabled(theGravityEnabled), m_CollisionEnabled(theCollisionEnabled) {}
	/**
	 * 
	 * @param  Vec2 theVelocity 
	 */
	inline void SetVelocity(Vec2 theVelocity) { m_Velocity = theVelocity; }
	/**
	 * 
	 * @param  Vec2 thePosition
	 */
	inline void SetPosition(Vec2 thePosition) { m_Position = thePosition; }
	/**
	 * 
	 * @param float theX 
	 * @param float theY 
	 */
	inline void SetVelocity(f32 theX, f32 theY) { m_Velocity = Vec2(theX, theY); }
	/**
	 * 
	 * @param float theX
	 * @param float theY 
	 */
	inline void SetPosition(f32 theX, f32 theY) { m_Position = Vec2(theX, theY); }
	/**
	 * 
	 * @return Vec2 
	 */
	inline Vec2 GetVelocity() const { return m_Velocity; }
	/**
	 * 
	 * @return Vec2 
	 */
	inline Vec2 GetPosition() const { return m_Position; }
	/**
	 * 
	 * @return bool
	 */
	inline bool IsGravityEnabled() const { return m_GravityEnabled; }
	/**
	 * 
	 * @return bool 
	 */
	inline bool IsCollisionEnabled() const { return m_CollisionEnabled; }

protected:
	Vec2 m_Velocity;
	Vec2 m_Position;

	bool m_GravityEnabled;
	bool m_CollisionEnabled;
};

