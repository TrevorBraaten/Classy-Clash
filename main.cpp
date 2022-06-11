#include "raylib.h"
#include "raymath.h"
#include "Character.h"



int main()
{

    // Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initializes the window
    InitWindow(windowWidth, windowHeight, "Retro Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPos{0.0, 0.0};

    const float mapScale{4.0f};

    Character knight;
    knight.SetScreenPos(windowWidth, windowHeight);

//  Sets Target FPS
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.GetWorldPos(),  -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
        knight.tick(GetFrameTime());
        // Check map bounds
        if (knight.GetWorldPos().x < 0.f ||
        knight.GetWorldPos().y < 0.f ||
        knight.GetWorldPos().x + windowHeight > map.width * mapScale ||
        knight.GetWorldPos().y + windowHeight > map.height *  mapScale)
        {
            knight.undoMovement();
        }
        
        EndDrawing();
    }
    CloseWindow();
}