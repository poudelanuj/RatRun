#ifndef GAME_H
#define GAME_H
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"Game1Object.h"
#include"Player.h"
//TextureManager m_textureManager;
Game1Object m_go;
Player m_player;
class Game
{
    public:
        Game();
        virtual ~Game();
        // simply set the running variable to true
        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();
// a function to access the private running variable
        bool running() { return m_bRunning; }
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        bool m_bRunning;

};
#endif // GAME_H

