#include "MainMenuState.h"
#include "GameplayState.h"

MainMenuState::MainMenuState(GameStateManager *engine) : GameState(engine)
{
}
MainMenuState::~MainMenuState()
{
    SDL_Log("Main menu destroyed");
}
void MainMenuState::initialize()
{
    FontManager *fonts = engine->getFontManager();
    fonts->loadFontWithName("nimbus-sans-bold.ttf", 64);
    fonts->loadFontWithName("nimbus-sans-regular.ttf", 32);

    SDL_Log("Main menu initialized");

    //Play music?
    //engine->getSoundEngine()->playMusic("Cinder.wav", 1);
}

void MainMenuState::pause()
{
    SDL_Log("Main menu paused");
}
void MainMenuState::resume()
{
    SDL_Log("Main menu resumed");
}
void MainMenuState::update(int elapsed)
{
}
void MainMenuState::handleInput()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) 
    {
        SDL_Log("Game exiting due to exit keys");
        //TODO: Fix this.
        engine->cleanUp();
    }
    if(e.type == SDL_KEYDOWN) {
        //We don't use a switch because mutiple keys are pressed
        SDL_Keycode c = e.key.keysym.sym;
        switch(c) {
           case SDLK_q:
                engine->cleanUp();
                break;
           case SDLK_RETURN:
                SDL_Log("Starting the game due to key press");
                //Start the game.
                engine->pushState(new GameplayState(engine));
                break;
        }
       
    }
}
void MainMenuState::render()
{
    Graphics *graphics = engine->getGraphics();
    graphics->clearRenderer();

    SDL_Rect loc = {0, 0, 800, 600};

    TTF_Font *boldFont = engine->getFontManager()->getFontWithName("nimbus-sans-bold.ttf", 64);
    TTF_Font *font = engine->getFontManager()->getFontWithName("nimbus-sans-regular.ttf", 32);

    int w = 0;
    int h = 0;
    TTF_SizeText(boldFont, "INACTION", &w, &h);
    loc = {800/2 - w/2, 40, w, h};
    renderFontAt(boldFont, loc, "INACTION");

    std::string instructions = "Press <Enter> to play, or 'q' to quit.";
    TTF_SizeText(font, instructions.c_str(), &w, &h);
    loc = {800/2 - w/2, 600/2 - h, w, h};
    renderFontAt(font, loc, instructions);

    graphics->render();
}

void MainMenuState::renderFontAt(TTF_Font *font, SDL_Rect &location, const std::string &text)
{
    Graphics *graphics = engine->getGraphics();
    SDL_Color color = {255, 255, 255};
    if(!font) 
    { 
        SDL_Log("Font didn't load %s", TTF_GetError());
    }
    graphics->renderFont(font, text, color, &location);
}
