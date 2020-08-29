#include <iostream>
#include "raylib.h"

using namespace std;
int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    int RectPos[4] = {screenWidth/2, screenHeight/2, screenWidth/4, screenHeight/4};

    InitWindow(screenWidth, screenHeight, "My Game");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
            ClearBackground(BROWN);
            DrawFPS(2,2);
            DrawRectangle(RectPos[0],RectPos[1],RectPos[2],RectPos[3], BLUE);
            DrawRectanglePro(Rectangle{200, 200, 100, 100}, Vector2{0,0}, 45.00f, GREEN);
            DrawText("TEXT text", 100, 100, 50, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
