#include "BaseCharacter.h"
#include "raylib.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
   
    void tick(float deltaTime);

 
private:
 


};