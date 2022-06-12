#include "raylib.h"
#include "raymath.h"


class Prop
{
    public:
    Prop(Vector2 pos, Texture2D tex);
    Vector2 Render(Vector2 np);

    private:
    Texture2D texture{};
    Vector2 worldPos{};
    Vector2 np{};
    float scale{4.f};
};