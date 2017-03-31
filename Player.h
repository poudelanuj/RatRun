
#ifndef PLAYER_H
#define PLAYER_H

#include "Game1Object.h"

#include<iostream>
#include<SDL_image.h>
//#include"Game1Object.h"
//#include"Player.h"
#include"TextureManager.h"
#include<SDL.h>
class Player : public Game1Object
{
    public:
        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* pRenderer);

        void update();
       // void clean();
    protected:
    private:
};

#endif // PLAYER_H
