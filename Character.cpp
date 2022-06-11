#include "Character.h"
#include "raymath.h"



Character::Character()
{
    width = texture.width/maxFrames;
    height = texture.height;
}


void Character::SetScreenPos(int winWidth, int winHeight){

    screenPos = {(float)winWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)height)
        };
}

void Character::tick(float deltaTime)
{

    worldPosLastFrame = worldPos;

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
    Rectangle source{frame * width / 6.f, 0.f, rightLeft * width / 6.f, height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * width / 6.0f, 4.0f * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);

}

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}