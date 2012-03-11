#pragma once
#include <SDL\SDL.h>
#include <string>
#include "GameActions.h"
#include "vec.h"
#include "Timer.h"
#include "Input.h"
#include "Accumulator.h"
#include "Level.h"

class cTextureManager;
class cSoundBufferManager;
class cSoundSourceManager;

class Game
{
public:
    static Game* GetSingleton();
    static void Release();
    
    cTextureManager     *GetTextureManager() const { return m_TextureManager; }
    cSoundBufferManager *GetSoundBufferManager() const { return m_SoundBufferManager; }
    cSoundSourceManager *GetSoundSourceManager() const { return m_SoundSourceManager; }

    int  OnExecute(int argc, char *argv[]);
    void OnInputGameAction(EGameAction::TYPE type);
    void OnSDLEvent(SDL_Event *event);
    void OnExit();
    
    const cInput *GetInput() { return &m_Input; }

    SDL_Surface *GetSDLMainSurface() const { return m_MainSurface; }

protected:

    Game();
    ~Game();

    bool Initialize();

    void MainLoop();

    void UpdateSDLEvents();

    void Update(float dt);
    
    // drawing, move it
    void Draw();

    // SDL, move it
    bool InitSDL();
    void ClearSDL();

    cTimer m_GameTimer;
    
    bool m_Running;
    cInput m_Input;
    Accumulator<float> m_Accumulator;

    static float s_LogicStep;

    // sdl, move it
    SDL_Surface *m_MainSurface;

    bool InitManagers();
    void ReleaseManagers();

    Level m_CurrentLevel;

    cTextureManager     *m_TextureManager;
    cSoundBufferManager *m_SoundBufferManager;
    cSoundSourceManager *m_SoundSourceManager;
};