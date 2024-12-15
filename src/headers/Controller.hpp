#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "Observer.hpp"

class Controller {
    public:
        Controller();

        void attachObserver(Observer* observer);
        void notifyEvent(const SDL_Event& event);

        void update();

    private:
        void listener();

        std::vector<Observer*> m_observers;
        SDL_Event m_event;

};


