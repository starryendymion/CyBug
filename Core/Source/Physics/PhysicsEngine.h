#pragma once

#include "Linear/Vector.h"
#include "Physics/Vec2.h"
#include "Physics/PhysicsObject.h"

class PhysicsEngine {
    private:
        Vec2 m_Gravity;
        Vector<PhysicsObject*> m_Objs;
        PhysicsEngine();

    public:
        /**
         * Sets gravity for the engine
         * @param  f32
         * @param  f32
         */
        void SetGravity(f32, f32);
        /**
         * Returns the Gravity Vec2
         * @return {Vec2}  : 
         */
        inline Vec2 GetGravity() {return m_Gravity;}
        /**
         * Since PhysicsEngine follows Singleton pattern, this returns the
         * single static instance of the PhysicsEngine
         * @return {PhysicsEngine*}  : 
         */
        static PhysicsEngine* GetInstance();
        /**
         * Returns the PhysicsObject at i index from the Vector<PhysicsObject*>
         * @param  i32
         * @return PhysicsObject*
         */
        PhysicsObject* GetPhysicsObject(i32);
        /**
         * Push the param into the Vector<PhysicsObject*>
         * @param  PhysicsObject*
         */
        void PushPhyObject(PhysicsObject*);
        /**
         * Pop the param out of the Vector<PhysicsObject*>
         * @return {PhysicsObject*}  : 
         */
        PhysicsObject* PopPhyObject();
        /**
         * Returns the current size of the Vector<PhysicsObject*>
         * @return {u32}  : 
         */
        inline u32 GetSize() const {return m_Objs.GetSize();}
        /**
         * Update all  the tranformations done to the Physics Object in the 
         * Vector<PhysicsObject*>
         */
        void UpdateObjects();
        /**
         * Check and Resolve collisions among all the PhysicsObject in the Engine
         */
        void Simulate();

    private:
        static PhysicsEngine* m_Instance;
};


PhysicsEngine* PhysicsEngine::m_Instance = nullptr;
