#include <iostream>
#include "game/Game.h"

int main()
{
    Game game;

    while (game.is_running())
    {
        game.update();
    }

    std::cout << "\nPROGRAM ENDING\n";
    return 0;
}