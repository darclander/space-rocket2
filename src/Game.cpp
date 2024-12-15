#include "Game.hpp"

Game::Game() {
    m_controller = std::make_shared<Controller>();

    m_gui = std::make_shared<Gui>("Space Rocket 2.0", 1280, 720, 0);

    m_controller->attachObserver(m_gui.get());
}

void Game::start() {

    bool m_running = true;
    while(m_gui->getWindowClose() && m_running) {

        m_controller->update();

        m_gui->clearRenderer();
        m_gui->update();
        

        m_gui->render();
    }

}

Game::~Game() {

}
