#include <iostream>
#include "raylib.h"

using namespace std;
int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    Rectangle rectangle = {200,200,100,100};
    Vector2 recOrigin = {50,50};
    float recRot = 45.0;

    InitWindow(screenWidth, screenHeight, "My Game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        recRot += 0.5;
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(2,2);
            DrawRectanglePro(rectangle, recOrigin, recRot, GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
