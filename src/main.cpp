#include <iostream>
#include "raylib.h"

using namespace std;
int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My Game");
    SetTargetFPS(60);

    Texture2D Player = LoadTexture("../src/assets/Player.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(2,2);
            DrawTexture(Player, 100, 100, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
