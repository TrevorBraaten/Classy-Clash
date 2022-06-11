#include "raylib.h"
#include "raymath.h"
#include "character.h"

class Character
{

public:
    Vector2 GetWorldPos() { return worldPos; }
    void SetScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run ={LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // 1 : facing right, -1 facing left
    float rightLeft{1.f};
    // animation variables
    float runningTime{};
    int frame{};
    const int maxFrames{6};
    const float updateTime{1.f / 12.f};
    const float speed{4.f};
};

void Character::SetScreenPos(int winWidth, int winHeight){

    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)
        };
}

void Character::tick(float deltaTime)
{

    Vector2 direction{};

    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
        frame = 0;
    }

    // Draws the character
    Rectangle source{frame * (float)texture.width / 6.f, 0.f, rightLeft * (float)texture.width / 6.f, (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.0f, 4.0f * (float)texture.height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);

}




int main()
{

    // Window Dimensions
    const int windowWidth{384};
    const int windowHeight{384};

    // Initializes the window
    InitWindow(windowWidth, windowHeight, "Retro Game");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");

    Vector2 mapPos{0.0, 0.0};



  

    // Sets the target fps
    SetTargetFPS(60);

    Character knight;
    knight.SetScreenPos(windowWidth, windowHeight);


    // Game While Loop
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.GetWorldPos(), -1.f);



        // Draws the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());
      

        EndDrawing();
    }

    CloseWindow();
}
