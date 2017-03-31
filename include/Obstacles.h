#ifndef OBSTACLES_H
#define OBSTACLES_H
#include<ctime>
#include"TextureManager.h"
extern
class Obstacles
{
    private:
        int x_coordinate, y_coordinate=0;

    public:
        Obstacles(clock_t bt);
        virtual ~Obstacles();
        bool ifToDestroy();
        int random(clock_t bT);
        void renderObstacles();
        bool checkCollision(int mouseX,int mouseY);
};

#endif // OBSTACLES_H
