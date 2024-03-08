#include "Physics/PhysicsEngine.h"
#include "PhysicsEngine.h"
#include "Physics/Collider.h"
#include <iostream>


PhysicsEngine::PhysicsEngine() {
}


PhysicsEngine* PhysicsEngine::GetInstance() {
    if (m_Instance == nullptr) {
        m_Instance = new PhysicsEngine();
    }
    return m_Instance;
}

PhysicsObject* PhysicsEngine::GetPhysicsObject(i32 theIndex) {
    return this->m_Objs[theIndex];
}

void PhysicsEngine::PushPhyObject(PhysicsObject* theObject) {
    m_Objs.PushBack(theObject);
}

PhysicsObject* PhysicsEngine::PopPhyObject() {
    m_Objs.Pop();
    return m_Objs.Last();
}

void PhysicsEngine::UpdateObjects() {
    Vec2 vel;
    Vec2 pos;

    for (int i = 0; i < m_Objs.GetSize(); i++) {
        pos = m_Objs[i]->GetPosition();
        if (m_Objs[i]->IsGravityEnabled() &&
                (pos.GetY() <= SCREEN_HEIGHT && pos.GetY() > 0)) {
            vel = m_Objs[i]->GetVelocity() + GetGravity();
            pos = m_Objs[i]->GetPosition() + GetGravity();
        }
        else {
            vel = m_Objs[i]->GetVelocity();
        }

        if (pos.GetX() > SCREEN_WIDTH || pos.GetX() < 0) {
            vel.SetX(-SIGN(pos.GetX())*ABS(vel.GetX()));
        }
        if (pos.GetY() > SCREEN_HEIGHT || pos.GetY() < 0) {
            vel.SetY(-SIGN(pos.GetY())*ABS(vel.GetY()));
        }

        pos = pos + (vel * ((float)FPS/CURR_FPS)) ;
        m_Objs[i]->SetPosition(vel);
        m_Objs[i]->SetVelocity(pos);
    }
}

void PhysicsEngine::Simulate() {
    for (i32 i = 0; i < m_Objs.GetSize(); i++) {
        for (i32 j = 0; j < m_Objs.GetSize(); j++) {
                Collider* collider1 = static_cast<Collider*>(m_Objs[i]);
                Collider* collider2 = static_cast<Collider*>(m_Objs[j]);

                Collider::ResolveCollision(*collider1, *collider2, 1);
        }
    }
    UpdateObjects();
}

void PhysicsEngine::SetGravity(f32 a, f32 b) {
    m_Gravity.SetX(a);
    m_Gravity.SetY(b);
}

