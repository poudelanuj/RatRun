#include"Game1Object.h"
class Enemy : public Game1Object
{
public:
void load(int x, int y, int width, int height, std::string
textureID);
void draw(SDL_Renderer* pRenderer);
void update();
void clean();
};
