#include "raylib.h"

int main()
{
    InitWindow(1920 , 1080, "jiujiji");
    SetTargetFPS(144);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
    
}