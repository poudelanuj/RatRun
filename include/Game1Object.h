#ifndef GAME1OBJECT_H
#define GAME1OBJECT_H
#include<iostream>
#include<SDL.h>
class Game1Object
{
    public:
        Game1Object();
        virtual ~Game1Object();
        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* pRenderer);
        void update();

    protected:
        std::string m_textureID;
        int m_currentFrame;
        int m_currentRow;
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    private:
};

#endif // GAME1OBJECT_H
