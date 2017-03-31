#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include"Game1Object.h"
#include"Player.h"
#include <ctime>
#include"TextureManager.h"
#include <cstdlib>
//#include"Obstacles.h"
//#include"Bonus.h"
#include <vector>
#include<iostream>


#define CLICKED 1
#define NEWSCREEN 0

const int FRAMES_PER_SECOND=120;

using namespace std;

class menu;
class Game
{
    public:
        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
        void initializeTextures();
        void run();
        int random1(clock_t);
        void handleEvents();
        void clean();
        void process();
        bool running() { return m_bRunning; }
        SDL_Window* m_pWindow;
        SDL_Event e;


    private:
        bool m_bRunning;
        int leftMidAnimationTimer = 0, rightMidAnimationTimer=0;
        SDL_Rect currentRectangle;
        char rope_id[4][10]={"r_one","r_two","r_three","r_four"};
        int mouseEvent;
        int left=0,right=0;
        bool leftMidAnimation = false, rightMidAnimation = false;
        friend class menu;
        friend class Bonus;
        friend class Obstacles;
        int chance,count1=0,count2=0;
};

class menu
{
    public:
        void loadMenu(int,char*);
        const int h=50;
        const int w=200;
        int x,y;
        char name[4][30]={"assests/a.png","assests/b.png","assests/c.png","assests/d.png"};
        friend class Game;

};
class Bonus:public Game
{
     private:
        int x_coordinate, y_coordinate=10;

    public:
        Bonus(clock_t beginTime);
        ~Bonus();
        void SetupCoordinate(clock_t);
        bool ifToEat();
        int random2(clock_t bt);
        int renderBonus();
        bool checkCollision(int mouseX,int mouseY);
       // friend class Game;

};
class Obstacles:public Game
{
     private:
        int x_coordinate, y_coordinate=10;

    public:
        Obstacles(clock_t beginTime);
        ~Obstacles();
        void SetupCoordinate(clock_t);
        bool ifToDestroy();
        int random2(clock_t bt);
        int renderObstacles();
        bool checkCollision(int mouseX,int mouseY);

};
#endif // GAME_H
