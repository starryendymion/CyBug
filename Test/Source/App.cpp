#include "raylib.h"

#include "Linear/Matrix.h"
#include "Linear/Vector.h"

#include "Physics/Vec2.h"
#include "Physics/PhysicsEngine.h"
#include "Physics/PhysicsObject.h"
#include "Physics/Collider.h"

using std::cout, std::endl;

void WarmupTest();

class App {
        PhysicsEngine* m_Engine;
        static i32 m_Fps;
    public:
        App() {
            InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TITLE");
            SetTargetFPS(m_Fps);
            m_Engine = PhysicsEngine::GetInstance();
        }

        void Add(Collider* theCollider) {
            m_Engine->PushPhyObject(theCollider);
        }

        void Update() {
            while (!WindowShouldClose()) {
                m_Engine->Simulate();
                BeginDrawing();
                DrawFPS(0, 0);
                ClearBackground(BLACK);
                for (size_t i = 1; i < m_Engine->GetSize(); i++) {
                    DrawCircle((int)m_Engine->GetPhysicsObject(i)->GetPosition().GetX(),
                            (int)m_Engine->GetPhysicsObject(i)->GetPosition().GetY(),
                            10.0f,
                            Color{(unsigned char)(10 * (i * 10)), 0, 255, 255});
                }
                EndDrawing();
            }
            CloseWindow();
        }


};
i32 App::m_Fps = CURR_FPS;

i32 main(void)
{
    WarmupTest();

    Collider a(Vec2(4, 0), Vec2(100, 100), false, true, Shape::Type::Circle);
    Collider b(Vec2(-1, 1), Vec2(200, 100), false, true, Shape::Type::Circle);
    Collider c(Vec2(-1, 1), Vec2(300, 300), false, true, Shape::Type::Circle);
    Collider d(Vec2(-1, 1), Vec2(300, 400), false, true, Shape::Type::Circle);
    Collider e(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);

    App app;

    for (int i  = 0; i < 85; i++) {
        Collider* A = new Collider(Vec2(2, 2), Vec2(i * 20, i * 10), false, true,
                                    Shape::Type::Circle);
        app.Add(A);
    }
    app.Add(&a);
    app.Add(&b);
    app.Add(&c);
    app.Add(&d);
    app.Add(&e);

    app.Update();

    return 0;
}

void WarmupTest() {
    Vector<Vec2> vec;
    vec.PushBack(Vec2(1, 1));
    vec.PushBack(Vec2(1, 2));
    vec.PushBack(Vec2(1, 3));

    vec.Clear();
    vec.EmplaceBack(1, 2);


    Cybug::Matrix<f32> mat(2, 2);
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[1][0] = 3;
    mat[1][1] = 4;

    mat.Trace();
}

