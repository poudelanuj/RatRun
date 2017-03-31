#include "Game1Object.h"
#include "TextureManager.h"
Game1Object::Game1Object()
{
    //ctor
}

Game1Object::~Game1Object()
{
    //dtor
}
void Game1Object::load(int x, int y, int width, int height, std::string textureID)
{
m_x = x;
m_y = y;
m_width = width;
m_height = height;
m_textureID = textureID;
m_currentRow = 1;
m_currentFrame = 1;
}
void Game1Object::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}
void Game1Object::update()
{
    m_x += 1;
}
