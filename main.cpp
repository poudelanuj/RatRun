#include "Game.h"
#include"TextureManager.h"
//#include"Obstacles.h"
#include<iostream>
#include<ctime>
Game* g_game = 0;
int main(int argc, char* argv[])
{
    g_game = new Game();
    g_game->init("Rat-Run", 150, 25, 1000, 730, 0);
    while(g_game->running())
    {
        g_game->run();
    }
    g_game->clean();
    return 0;
}


