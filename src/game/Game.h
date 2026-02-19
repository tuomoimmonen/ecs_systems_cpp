#pragma once
#include "managers/EntityManager.h"
#include "systems/RenderSystem.h"
#include "systems/InputSystem.h"
#include "systems/MovementSystem.h"
#include "screenbuffer/ScreenBuffer.h"
#include "map/Map.h"
#include "utilities/GameState.h"

class Texture;

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
    void create_enemy();
    void create_enemies();

private:
    int m_screen_width = 20;
    int m_screen_height = 10;
    
    GameState m_state = GameState::NONE;
    EntityManager m_entity_manager;
    RenderSystem m_render;
    InputSystem m_input;
    MomeventSystem m_movement;
    ScreenBuffer m_buffer;

    std::shared_ptr<Texture> m_enemy_texture;
    Map test_map;
};