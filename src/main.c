#include "raylib.h"

int main() {
    InitWindow(800, 450, "Raylib game");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello", 190, 200, 20, BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}