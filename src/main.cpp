#include <iostream>
#include "raylib.h"

using namespace std;
int main() {

    // Setup
    const int screenWidth = 800;
    const int screenHeight = 450;

    bool isPlayerFalling = true;
    bool isPlayerSprinting = false;
    bool isHoldingL = false;
    bool isHoldingR = false;
    int playerVelocityX = 0;
    int playerVelocityY = 0;
    int playerPosX = 100;
    int playerPosY = 100;
    int playerSpeed = 10;
    int FallSpeed = 10;

    InitWindow(screenWidth, screenHeight, "My Game");
    SetTargetFPS(60);

    Texture2D Player = LoadTexture("../src/assets/Player.png");

    while (!WindowShouldClose())
    {
        //Drawing
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(2,2);
            DrawTexture(Player, playerPosX, playerPosY, RAYWHITE);
        EndDrawing();

        //Movement
        if (isPlayerFalling){
            playerVelocityY += FallSpeed;
        }
        else{
            playerVelocityY = 0;
        }
        playerPosY += playerVelocityY;

        if (isPlayerSprinting){
            playerSpeed *= 2;
        }
        if (isHoldingL){
            playerVelocityX += playerSpeed;
        }
        if (isHoldingR){
            playerVelocityX += -playerSpeed;
        }
        playerVelocityX = 0;
        playerSpeed = 10;
    }

    CloseWindow();
    return 0;
}
