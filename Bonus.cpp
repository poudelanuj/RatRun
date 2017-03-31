//#include"Bonus.h"
#include<iostream>
//#include "Obstacles.h"
#include"Game.h"
#include<windows.h>
using namespace std;
extern SDL_Renderer* m_pRenderer;
typedef TextureManager TheTextureManager;

Bonus::Bonus(clock_t beginTime)
{
    x_coordinate =Bonus::random2(beginTime);
}

Bonus::~Bonus()
{
    //dtor
}
void Bonus::SetupCoordinate(clock_t t)
{
    x_coordinate=Bonus::random2(t);
}
int Bonus::renderBonus()
{
    //SDL_Delay(100);
   // SDL_RenderClear(m_pRenderer);
   handleEvents();
   process();
    TheTextureManager::Instance()->load("assests/bonus.png","danger1",m_pRenderer);
    TheTextureManager::Instance()->draw("danger1",this-> x_coordinate,y_coordinate,35,35,m_pRenderer);
    y_coordinate+=15;
   /* if(y_coordinate<730)
    {
       // SDL_Delay(2);
        SDL_RenderPresent(m_pRenderer);
        renderBonus();
    }

    else*/
        y_coordinate=20;
}
int Bonus::random2(clock_t bT)
{
    int j;
    float t=float(clock()-bT)/CLOCKS_PER_SEC;
    j+=float(t)*20;
    cout<<j;
    int x=150+12,y=550+12;
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

bool Bonus::ifToEat()
{
    if (y_coordinate>730)
        return true;
    else
        return false;
}

bool Bonus::checkCollision(int mouseX,int mouseY)
{
    if(mouseX-x_coordinate<=10 && mouseY-y_coordinate<=10)
    {
        return true;
    }
    else
        return false;
}
