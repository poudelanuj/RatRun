#include<iostream>
//#include "Obstacles.h"
#include<SDL.h>
#include"TextureManager.h"
#include"Game.h"
using namespace std;
extern SDL_Renderer* m_pRenderer;
typedef TextureManager TheTextureManager;

Obstacles::Obstacles(clock_t beginTime)
{
    x_coordinate =Obstacles::random2(beginTime);
}

 void Obstacles::SetupCoordinate(clock_t t)
 {
     x_coordinate=Obstacles::random2(t);
 }
Obstacles::~Obstacles()
{
    //dtor
}

int Obstacles::renderObstacles()
{
    //SDL_RenderClear(m_pRenderer);
   handleEvents();
    process();
    TheTextureManager::Instance()->load("assests/death.png","danger1",m_pRenderer);
    TheTextureManager::Instance()->draw("danger1", this->x_coordinate,y_coordinate,35,35,m_pRenderer);
    if(y_coordinate>730)
    // if(!leftMidAnimation)
    {
        if(checkCollision(this->left+150,550));
            cout<<"left collision"<<endl;
        if(checkCollision(this->right+150,550));

            cout<<"right collision"<<endl;
    }
    y_coordinate+=15;

    /*if(y_coordinate<730)
    {
       //handleEvents();
        //process();
        //SDL_Delay(2);
        SDL_RenderPresent(m_pRenderer);
        renderObstacles();
    }*/
    //else
        y_coordinate=20;

}
int Obstacles::random2(clock_t bT)
{
    int j;
    float t=float(clock()-bT)/CLOCKS_PER_SEC;
    j+=float(t)*20;
    cout<<j;
    int x;
    if(j%2==0)
    {
        int v1 = rand() % 100;

        if(v1>=0&&v1<25)
            x=150+12;
        else if(v1>=25&&v1<50)
            x=350+12;
        else if(v1>=50 && v1<75)
            x=550+12;
        else if(v1>=50 && v1 <100)
            x=750+12;
    }
    return x;
}

bool Obstacles::ifToDestroy()
{
    if (y_coordinate>730)
        return true;
    else
        return false;
}

bool Obstacles::checkCollision(int mouseX,int mouseY)
{
    if(mouseX-x_coordinate<=10 && mouseY-y_coordinate<=10)
    {
        return true;
    }
    else
        return false;
}
