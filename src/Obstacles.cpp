#include "Obstacles.h"
extern SDL_Renderer* m_pRenderer;
extern typedef TextureManager TheTextureManager;
extern static TextureManager m_textureManager;

Obstacles::Obstacles(clock_t bt)
{
    x_coordinate = random(bt);
}

Obstacles::~Obstacles()
{
    //dtor
}

void Obstacles::renderObstacles()
{
        TheTextureManager::Instance()->load("assests/death.png","danger1",m_pRenderer);
        TheTextureManager::Instance()->draw("danger1", x_coordinate,y_coordinate,35,35,m_pRenderer);
        y_coordinate+=5;
}

int Obstacles::random(clock_t bT)
{
    float t=float(clock()-bT)/CLOCKS_PER_SEC;
    j+=float(t)*20;
    cout<<j;
    int x=150+12,y=550+12;
    if(j%2==0)
    {
        int v1 = rand() % 100;

        if(v1>=0&&v1<25)
            x=150;
        else if(v1>=25&&v1<50)
            x=350;
    }
    reuturn x;
}

bool Obstacles::ifToDestroy()
{
    if (y>730)
        return true;
    else
        return false;
}

bool Game::checkCollision(int mouseX,int mouseY)
{
            if(mouseX-x_coordinate<=10 && mouseY-y_coordinate<=10)
            {
                return true;
            }
            else
                return false;
}
