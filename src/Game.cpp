#include "Game.h"
#include"TextureManager.h"
typedef TextureManager TheTextureManager;
//TextureManager m_textureManager;

int m_currentFrame;

bool Game::init(const char* title, int xpos, int ypos, int width,int height, int flags)
{
// attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
// init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,0,0,0,0);
                m_go.load(100, 100, 128, 82, "animate");
                m_player.load(300, 300, 128, 82, "animate");
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop
    return true;
}
void Game::render()
{
    SDL_RenderClear(m_pRenderer);// clear the renderer to the draw color
    //SDL_RenderCopyEx(m_pRenderer, m_pTexture,&m_sourceRectangle, &m_destinationRectangle,0, 0, SDL_FLIP_HORIZONTAL); // pass in the horizontal flip
    //m_textureManager.load("assests/new_game.png","animate", m_pRenderer);
    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);
    //TheTextureManager::Instance()->load("assests/three.png","animate", m_pRenderer);
    //TheTextureManager::Instance()->draw("animate", 0,0, 110, 65,m_pRenderer);
   // m_textureManager.draw("animate", 0,0, 110, 65,m_pRenderer);
   // m_textureManager.drawFrame("animate", 110,110, 700, 300,1, m_currentFrame, m_pRenderer);
    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }


    }
}
/*void Game::update()
{
    //m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}*/
void Game::update()
{
    m_go.update();
    m_player.update();
}
/*static TextureManager* Instance()
{
    if(s_pInstance == 0)
    {
        s_pInstance = new TextureManager();
        return s_pInstance;
    }
    return s_pInstance;
}
*/
