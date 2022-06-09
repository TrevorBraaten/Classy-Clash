#include "raylib.h"









int main()
{

    // Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initializes the window
    InitWindow(windowWidth, windowHeight, "Retro Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    
    // Sets the target fps
    SetTargetFPS(60);
    
    // Game While Loop
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
    


        EndDrawing();
    }

    CloseWindow();

}
