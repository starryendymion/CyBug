#pragma once

#include "PhysicsObject.h"
#include "Shape.h"
#include "Vec2.h"

class Collider : public PhysicsObject
{
public:
  Collider(Vec2 theVelocity, Vec2 thePosition,
          bool theGravityEnabled, bool theCollisionEnabled, Shape theShape);
  /**
   * Check if the collider objects intersect
   * @param  Collider theOther
   * @return bool
   */
  bool Intersects(const Collider& theOther) const;
  /**
   * Updates the velocity of the collider objects on collision
   * @param  Collider theFirst
   * @param  Collider theSecond
   * @param  f32 theCoefficientOfRestitution
   */
  void ResolveCollision(Collider& theFirst, Collider& theSecond, f32 theCoefficientOfRestitution = 1.0f);

private:
  Shape m_Shape;

  bool intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const;
};
