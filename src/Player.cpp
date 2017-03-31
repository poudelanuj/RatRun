#include "Player.h"
#include<iostream>
Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}
void Player::load(int x, int y, int width, int height,std:: string textureID)
{
    Game1Object::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    Game1Object::draw(pRenderer);
}

void Player::update()
{
    m_x -= 1;
}
