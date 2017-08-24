#include <iostream>
#include "game.h"
#include "canvas.h"
#include <random>
#include "time.h"

#define SIZE 20

using namespace std;

int main(int argc, char *argv[])
{
    srand(NULL);
    cout << "This is snake." << endl;

    Game game;

    Canvas canvas(&game, SIZE, SIZE);
    canvas.init();

    return 0;
}
