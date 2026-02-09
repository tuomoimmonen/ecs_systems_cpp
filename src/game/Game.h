#pragma once
#include "managers/EntityManager.h"

enum class GameState
{
    NONE = 0, RUNNING
};

class Game
{
public:
    Game();
    ~Game();

    void update();
    const bool is_running() const { return m_state == GameState::RUNNING; }

private:
    void init();

    void create_player();

private:
    int m_screen_width = 20;
    int m_screen_height = 10;
    
    GameState m_state = GameState::NONE;
    EntityManager m_entity_manager;

};