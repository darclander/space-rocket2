#include "Gui.hpp"

Gui::Gui(const char *title, int windowWidth, int windowHeight, bool fullscreen) {
    int flags = 0;
    this->m_windowWidth = windowWidth;
    this->m_windowHeight = windowHeight;
    this->m_windowClose = false;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }

    if (SDL_Init(SDL_INIT_AUDIO || SDL_INIT_VIDEO) == 0) {
        m_window = SDL_CreateWindow(
                                    title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    this->m_windowWidth,
                                    this->m_windowHeight,
                                    flags | SDL_WINDOW_RESIZABLE  
        );

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

        if(m_renderer) {
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        }
    }

    // m_font = TTF_OpenFont("./font.ttf", 28);

    // if (!m_font) {
    //     std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
    // }
}

void Gui::update() {

}

bool Gui::getWindowClose() {
    return !m_windowClose;
}

void Gui::onEvent(const SDL_Event& event) {
    if(event.type == SDL_QUIT) {
        m_windowClose = true;
    }
}

void Gui::render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_renderer);
}

void Gui::clearRenderer() {
    SDL_RenderClear(m_renderer);
}

SDL_Renderer *Gui::getRenderer() {
    return m_renderer;
}

TTF_Font *Gui::getFont() {
    return m_font;
}

Gui::~Gui() {
    TTF_CloseFont(m_font);
    TTF_Quit();
    SDL_Quit();
}