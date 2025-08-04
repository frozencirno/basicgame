#include "raylib.h"

typedef enum {
    TITLE,
    LEVEL0,
    LEVEL1
} GameState;

void drawTitleScreen() {
    BeginDrawing();

    ClearBackground(RED);
    DrawText(TextFormat("Game Title"), 400, 225, 40, BLACK);
    DrawText(TextFormat("Press enter to play"), 420, 265, 25, BLACK);

    EndDrawing();
}

int main() {
    InitWindow(800, 450, "Raylib game");

    Camera3D cam = {0};
    cam.fovy = 90.0f;
    cam.projection = CAMERA_PERSPECTIVE;
    cam.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    cam.target = (Vector3){ 0.0f, 0.0f, 0.0f };     
    cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };

    DisableCursor();

    GameState gamestate = TITLE;
    
    while (!WindowShouldClose()) {
        switch (gamestate)
        {
        case TITLE:
            drawTitleScreen();
            break;

        case LEVEL0:
            UpdateCamera(&cam, CAMERA_FREE);
            BeginDrawing();
            ClearBackground(BLUE);
            DrawText("Game", 10, 10, 20, BLACK);
            BeginMode3D(cam);

            DrawPlane((Vector3){0, -1, 0}, (Vector2){10, 10}, GRAY);

            EndMode3D();
            EndDrawing();
        
        default:
            break;
        }
    }
    
    CloseWindow();
    return 0;
}