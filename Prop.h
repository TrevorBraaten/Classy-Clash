#include "raylib.h"
#include "raymath.h"


class Prop
{
    public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knightPos);

    private:
    Texture2D texture{};
    Vector2 worldPos{};
    Vector2 knightPos{};
    float scale{4.f};
};