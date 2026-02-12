cmake_minimum_required(VERSION 3.16)
project(ecs_systems_cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_SOURCES
    src/main.cpp
    src/components/Component.cpp
    src/entity/Entity.cpp
    src/managers/EntityManager.cpp
    src/game/Game.cpp
    src/components/SpriteComponent.cpp
    src/components/TransformComponent.cpp
    src/screenbuffer/ScreenBuffer.cpp
    src/systems/RenderSystem.cpp
    src/systems/InputSystem.cpp
    src/components/InputComponent.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# ---------------------------------------------------------------------------
# Link Libraries
# ---------------------------------------------------------------------------

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE

    )
    
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    "src"
)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
    
)

endif()


