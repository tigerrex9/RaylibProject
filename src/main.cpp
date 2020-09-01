#include <iostream>
#include "raylib.h"

using namespace std;
int main() {

    // Setup
    const int screenWidth = 800;
    const int screenHeight = 450;


    class Object{
    public:
        int Height;
        int Width;
        bool isFalling = false;
        bool isSprinting = false;
        int VelocityX = 0;
        int VelocityY = 0;
        int PosX;
        int PosY;
        int Speed;
        int FallSpeed = 10;
        Texture2D Sprite;
    };

    Object player;
    player.Height = 100;
    player.Width = 60;
    player.isFalling = false;
    player.isSprinting = false;
    player.VelocityX = 0;
    player.VelocityY = 0;
    player.PosX = 10;
    player.PosY = 10;
    player.Speed = 10;
    player.FallSpeed = 1;
    player.Sprite = LoadTexture("../src/assets/Player.png");

    Rectangle floor0 = {10, 400, 720, 40};


    bool isHoldingL = false;
    bool isHoldingR = false;

    InitWindow(screenWidth, screenHeight, "My Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Drawing
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(player.Sprite, player.PosX, player.PosY, RAYWHITE);
            DrawRectangleRec(floor0, RED);
        EndDrawing();

        //Collision  !!!!!! NEEEDS WORK !!!!!!!
        if (player.PosY + player.Height == floor0.y){
            player.isFalling = false;
        }else{
            player.isFalling = true;
        }

        //Movement
        if (player.isFalling){
            player.VelocityY += player.FallSpeed;
        }
        else{
            player.VelocityY = 0;
        }
        player.PosY += player.VelocityY;

        if (player.isSprinting){
            player.Speed *= 2;
        }
        if (isHoldingL){
            player.VelocityX += player.Speed;
        }
        if (isHoldingR){
            player.VelocityX += -player.Speed;
        }
        player.PosX += player.VelocityX;

        player.VelocityX = 0;
        player.Speed = 10;
    }

    CloseWindow();
    return 0;
}
