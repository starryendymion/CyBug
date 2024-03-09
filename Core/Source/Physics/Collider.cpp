#include "Collider.h"
#include <cmath>

Collider::Collider(Vec2 theVelocity, Vec2 thePosition,
                    bool theGravityEnabled, bool theCollisionEnabled, Shape theShape)
  : PhysicsObject(theVelocity, thePosition, theGravityEnabled, theCollisionEnabled), m_Shape(theShape) {}

bool Collider::Intersects(const Collider& theOther) const
{
  // Delegate to specific collision check based on shape types
  return m_Shape.Intersects(theOther.m_Shape);
}

void Collider::ResolveCollision(Collider& theFirst, Collider& theSecond, f32 theCoefficientOfRestitution)
{
  // ... (implementation for resolving collisions)
}

bool Collider::intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const
{
  // Distance between centers
  Vec2 distance = theFirst.GetPosition() - theSecond.GetPosition();

  // Squared radius sum (assuming both shapes are circles)
  float radiusSum = theFirst.m_Shape.GetRadius() + theSecond.m_Shape.GetRadius();

  // Actual distance check
  return distance.GetX() * distance.GetX() + distance.GetY() * distance.GetY() < radiusSum * radiusSum;
}
