#include "Game.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include "components/AIComponent.h"
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
    // create assets
    m_enemy_texture = std::make_shared<Texture>('d');

    // spawn objects
    create_player();
    create_enemies();

    // draw map first time
    system("cls");
    m_buffer.clear_buffer();
    m_render.render(m_entity_manager, m_buffer);

    // set states
    m_state = GameState::RUNNING;
}

void Game::update()
{
    // 1. INPUT
    m_input.update(m_entity_manager, m_state);
    
    // 2. UPDATE
    m_entity_manager.update();
    m_movement.update(m_entity_manager, test_map);
    
    // 3. RENDER
    system("cls");
    m_buffer.clear_buffer();
    m_render.render(m_entity_manager, m_buffer);
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

void Game::create_enemy()
{
    std::unique_ptr<Entity> enemy = std::make_unique<Entity>();
    std::unique_ptr<TransformComponent> transform = std::make_unique<TransformComponent>(rand() % m_screen_width, rand() % m_screen_height);
    std::unique_ptr<SpriteComponent> sprite = std::make_unique<SpriteComponent>('E');
    sprite->set_texture(m_enemy_texture);
    std::unique_ptr<AIComponent> ai = std::make_unique<AIComponent>();
    enemy->add_component(std::move(transform));
    enemy->add_component(std::move(sprite));
    enemy->add_component(std::move(ai));

    m_entity_manager.add_entity(std::move(enemy));
}

void Game::create_enemies()
{
    for (int i = 0; i < 5; i++) {
        create_enemy();
    }
}


