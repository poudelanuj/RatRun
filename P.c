#ifndef PLAYER_H
#define PLAYER_H

#include "Game1Object.h"


class Player : public Game1Object
{
    public:
        Player();
        virtual ~Player();
         void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* pRenderer);
        void update();

    protected:
    private:
};

#endif // PLAYER_H

