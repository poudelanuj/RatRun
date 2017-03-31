#include"Player.h"
#include"Game1Object.h"
#include<SDL.h>
#include"Game.h"
#include<iostream>
void Player::load(int x, int y, int width, int height, std::string textureID)
{
     Game1Object::load(x, y, width, height, textureID);
}
void Player::draw(SDL_Renderer* pRenderer)
{
    Game1Object::draw(pRenderer);
}
void Player::update()
{
//std::cout << "update player";
    m_x-=1;
}


