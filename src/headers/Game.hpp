#pragma once

#include <iostream>
#include <memory>

#include "Gui.hpp"
#include "Controller.hpp"

class Game {
    public:
        Game();
        ~Game();

        void start();

    private:
        std::shared_ptr<Gui> m_gui = nullptr;
        std::shared_ptr<Controller> m_controller = nullptr;

};
