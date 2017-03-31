#include"Game.h"
#include<vector>
#include<windows.h>

int j=0;
SDL_Renderer* m_pRenderer;
using namespace std;
typedef TextureManager TheTextureManager;
menu item[4];
clock_t beginTime=clock();
vector<Obstacles> o(2,Obstacles(clock()));
vector <Bonus> b(2,Bonus(clock()));
Uint32 start;

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
            m_pRenderer = SDL_CreateRenderer(m_pWindow,-1 , 0);
            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,0,0,20,0);
                run();
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
    this->m_bRunning = true; // everything inited successfully, start the main loop
    clock_t beginTime=clock();
    start=SDL_GetTicks();
    //Obstacles o(beginTime);
    mouseEvent = false;
}

void Game::process()
{
    SDL_RenderClear(m_pRenderer);// clear the renderer to the draw color
    //render wire
    for (int i =0;i<800;i=i+200)
    {
        TheTextureManager::Instance()->load("assests/rope.png",rope_id[i], m_pRenderer);
        TheTextureManager::Instance()->draw(rope_id[i], i+150,0, 70,800,m_pRenderer);
    }
    //render mouse
    if(!leftMidAnimation)
    {
        TheTextureManager::Instance()->load("assests/rat_st.png","rat_st",m_pRenderer);
        TheTextureManager::Instance()->draw("rat_st", this->left+95,550, 200,200,m_pRenderer);
    }
    else
    {
        if(this->left == 200)
        {
            TheTextureManager::Instance()->load("assests/rat_right.png","rat_rt",m_pRenderer);
            TheTextureManager::Instance()->draw("rat_rt",this->leftMidAnimationTimer+95,500, 200,200,m_pRenderer);
            this->leftMidAnimationTimer += 100;
            if(leftMidAnimationTimer == 200)
            {
                this->leftMidAnimation = false;
            }
        }
        else if (this->left == 0)
        {
            TheTextureManager::Instance()->load("assests/rat_left.png","rat_lf",m_pRenderer);
            TheTextureManager::Instance()->draw("rat_lf",this->leftMidAnimationTimer+95,500, 200,200,m_pRenderer);
            this->leftMidAnimationTimer -= 100;
            if(leftMidAnimationTimer == 0)
            {
                this->leftMidAnimation = false;
            }
        }
    }
    if(!rightMidAnimation)
    {
        TheTextureManager::Instance()->load("assests/rat_st.png","rat_st",m_pRenderer);
        TheTextureManager::Instance()->draw("rat_st", this->right+400+95,550, 200,200,m_pRenderer);
    }
    else
    {
        if(this->right == 200)
        {
            TheTextureManager::Instance()->load("assests/rat_right.png","rat_rt",m_pRenderer);
            TheTextureManager::Instance()->draw("rat_rt",this->rightMidAnimationTimer+95+400,500, 200,200,m_pRenderer);
            this->rightMidAnimationTimer += 100;
            if(rightMidAnimationTimer == 200)
            {
                this->rightMidAnimation = false;
            }
        }
        else if (this->right == 0)
        {
            TheTextureManager::Instance()->load("assests/rat_left.png","rat_lf",m_pRenderer);
            TheTextureManager::Instance()->draw("rat_lf",this->rightMidAnimationTimer+95+400,500, 200,200,m_pRenderer);
            this->rightMidAnimationTimer -= 100;
            if(rightMidAnimationTimer == 0)
            {
                this->rightMidAnimation = false;
            }
        }
    }


}

void Game::run()
{
            //Handle events on queue
    handleEvents();
            //User requests quit
    if(mouseEvent!=CLICKED)
    {
        for(int i=0;i<4;i++)
        {
            item[i].loadMenu(i,item[i].name[i]);
            SDL_RenderPresent(m_pRenderer);
        }
    }
    else
    {
                //process();
        int v1=this->Game::random1(clock());
        if(count1<2)
        {

            o.push_back(clock());
            if(v1%10==0)
            {
                o[count1].SetupCoordinate(clock());
               // process();
               //for (int i = 0; i<=count1;i++)
                o[count1].renderObstacles();
                count1++;
            }
        }
        else
        {
           count1=0;
           o.pop_back();
        }
        if(count2<2)
        {
            if(v1%11==0)
            {
                b.push_back(clock());
                process();
                b[count2].SetupCoordinate(clock());
                b[count2].renderBonus();
                count2++;
            }
        }
        else
        {
            count2=0;
            b.pop_back();
        }
    }
    SDL_RenderPresent(m_pRenderer);
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
        SDL_PollEvent( &event );

        switch (event.type)//random(beginTime);//if (this->mouseEvent== NEWSCREEN
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->mouseEvent = CLICKED;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        {
                            if(this->left == 200)
                                this->left = 0;
                            else if (this->left == 0)
                                this->left = 200;
                            this->leftMidAnimation = true;
                            break;
                        }
                    case SDLK_RIGHT:
                        {
                            if(this->right == 200)
                                this->right = 0;
                            else
                                this->right = 200;
                            this->rightMidAnimation = true;
                            break;
                        }
                    default:
                        break;
                }
            default:
            break;
        }
}

void menu::loadMenu(int a,char *name)
{
    TheTextureManager::Instance()->load(name,"animate",m_pRenderer);
    TheTextureManager::Instance()->draw("animate",400,a*100+50, w,h,m_pRenderer);
}

int Game::random1(clock_t bT)
{
    int j,v1 ;
    float t=float(clock()-bT)/CLOCKS_PER_SEC;
    j+=float(t);
    if (j %5==0)
    {
        v1 = rand() % 100;
        return v1;
    }
}

