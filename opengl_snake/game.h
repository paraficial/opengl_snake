#ifndef GAME_H
#define GAME_H

#include <tuple>
#include <vector>

using namespace std;
class Game
{
public:
    Game();

    tuple<int, int> startposition;
    tuple<int, int> startfood;

    vector<tuple<int, int>> *snake;
};

#endif // GAME_H
