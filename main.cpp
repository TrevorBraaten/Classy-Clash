#include "raylib.h"
#include "raymath.h"

int main()
{

    // Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initializes the window
    InitWindow(windowWidth, windowHeight, "Retro Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPos{0.0, 0.0};
    
    // Movement Speed
    float speed {4.0};
    
    // Sets the target fps
    SetTargetFPS(60);
    

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f), 
        windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };

    // Game While Loop
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};


        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
        // Set mapPos = mapPos - direction
        mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // Draws the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // Draws the character
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);











        EndDrawing();
    }

    CloseWindow();

}
