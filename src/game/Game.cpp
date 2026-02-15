#include "Game.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"

#include <iostream>

Game::Game()
{
    init();
}

Game::~Game()
{
    std::cout << "\033[31m" << "Game destructor called" << "\033[0m\n";
}

void Game::init()
{
    create_player();
    m_state = GameState::RUNNING;
}

void Game::create_player()
{
    std::unique_ptr<Entity> player = std::make_unique<Entity>();
    std::unique_ptr<TransformComponent> transform = std::make_unique<TransformComponent>(m_screen_width / 2, m_screen_height / 2);
    player->add_component(std::move(transform));
    std::unique_ptr<SpriteComponent> sprite = std::make_unique<SpriteComponent>('@');
    player->add_component(std::move(sprite));
    std::unique_ptr<InputComponent> input = std::make_unique<InputComponent>();
    player->add_component(std::move(input));

    m_entity_manager.add_entity(std::move(player));
}

void Game::update()
{
    // 1. INPUT
    m_input.update(m_entity_manager);
    
    // 2. UPDATE

    // 3. RENDER
    m_buffer.clear_buffer();
    m_render.render(m_entity_manager, m_buffer);

    m_entity_manager.print();
    std::cin.get();
    m_state = GameState::NONE;
}

