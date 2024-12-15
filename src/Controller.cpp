#include "Controller.hpp"

Controller::Controller() {
    
}

void Controller::update() {
    this->listener();
}

void Controller::attachObserver(Observer* observer) {
    m_observers.push_back(observer);
}

void Controller::notifyEvent(const SDL_Event& event) {
    for (auto observer : m_observers) {
        observer->onEvent(event);
    }
}

void Controller::listener() {
    while(SDL_PollEvent(&m_event)) {
        notifyEvent(m_event);
    }
}