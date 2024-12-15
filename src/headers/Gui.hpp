#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Controller.hpp"

namespace color {
    const SDL_Color RED     = {255, 0,   0,   255};
    const SDL_Color GREEN   = {0,   255, 0,   255};
    const SDL_Color BLUE    = {0,   0,   255, 255};
    const SDL_Color WHITE   = {255, 255, 255, 255};
}


class Gui : public Observer {
    public:
        Gui(const char *title, int windowWidth, int windowHeight, bool fullscreen);
        ~Gui();

        TTF_Font *getFont();
        
        SDL_Renderer *getRenderer();

        void clearRenderer();
        void render();
        void onEvent(const SDL_Event &event);
        void update();

        bool getWindowClose();

    private:

        int m_windowWidth; 
        int m_windowHeight;
        
        bool m_windowClose;

        SDL_Event m_event;
        SDL_Renderer *m_renderer;
        SDL_Window *m_window;

        TTF_Font *m_font;
};

