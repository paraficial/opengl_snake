#include "game.h"

Game::Game()
{
    startposition = tuple<int, int>(1, 1);
    startfood = tuple<int, int>(3, 3);

    snake = new vector<tuple<int, int>>();
    snake->push_back(startposition);
}
