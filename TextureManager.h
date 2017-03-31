
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include<iostream>
#include<map>
#include<SDL.h>
class TextureManager{

    private:
//       TextureManager(){}
    public:

        bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer);
// draw
        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
// drawframe
        void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
        std::map<std::string, SDL_Texture*> m_textureMap;
   // static TextureManager* Instance();/
        static TextureManager* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new TextureManager();
                return s_pInstance;
            }
            return s_pInstance;
        }


        static TextureManager* s_pInstance;
        SDL_Texture* loadDirect(std::string fileName, SDL_Renderer* pRenderer);
        void renderObtacles();

};

#endif // TEXTUREMANAGER_H



