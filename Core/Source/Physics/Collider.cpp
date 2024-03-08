#include "Collider.h"
#include <iostream>

Collider::Collider(Vec2 theVelocity, Vec2 thePosition, bool theGravityEnabled, bool theCollisionEnabled, Shape theShape)
	: PhysicsObject(theVelocity, thePosition, theGravityEnabled, theCollisionEnabled), m_Shape(theShape) {}


bool Collider::Intersects(const Collider& theOther) const
{
	if (this->m_Shape.GetType() == Shape::Type::Circle &&
            theOther.m_Shape.GetType() == Shape::Type::Circle)
		return intersectCircleCircle(theOther, theOther);
	return false; // For unsupported type
}

void Collider::ResolveCollision(Collider& theFirst, Collider& theSecond,
        f32 theCoefficientOfRestitution)
{// Assuming unit mass

	if (theFirst.IsCollisionEnabled() && theSecond.IsCollisionEnabled())
	{
		if (theFirst.Intersects(theSecond))
		{
            // v_rel =  v1 - v2
			Vec2 aRelativeVelocity = theFirst.GetVelocity() - theSecond.GetVelocity();
			Vec2 aUnitNormal = theFirst.GetPosition() - theSecond.GetPosition();

			aUnitNormal.Normalize();

            // impulse = -(1 + e) * ((v_rel_x * unit_x) + (v_rel_y * unit_y))/2
			f32 aImpulse = -(1 + theCoefficientOfRestitution) *
				(aRelativeVelocity.GetX() * aUnitNormal.GetX() +
                 aRelativeVelocity.GetY() * aUnitNormal.GetY())/2;


            // v1_x = v1_x + (impulse * unit_x)
            // v1_y = v1_y + (impulse * unit_y)
            theFirst.GetVelocity().SetX((theFirst.GetVelocity().GetX() +
				(aImpulse * aUnitNormal.GetX())));
            theFirst.GetVelocity().SetY((theFirst.GetVelocity().GetY() +
				(aImpulse * aUnitNormal.GetY())));


            // v2_x = v2_x + (impulse * unit_x)
            // v2_y = v2_y + (impulse * unit_y)
            theSecond.GetVelocity().SetX((theSecond.GetVelocity().GetX() -
				(aImpulse * aUnitNormal.GetX())));
            theSecond.GetVelocity().SetY((theSecond.GetVelocity().GetY() -
				(aImpulse * aUnitNormal.GetY())));
		}

	}
}


bool Collider::intersectCircleCircle(const Collider& theFirst, const Collider& theSecond) const
{
    // using distance formula
    f32 dist = SQ(theFirst.GetPosition().GetX() + theSecond.GetPosition().GetX()) +
        SQ(theFirst.GetPosition().GetY() + theSecond.GetPosition().GetY());
	return dist < 100;
}

