#include "game.h"
#include "canvas.h"
#include <deque>

#define SIZE 10
#define SPEED 5

using namespace std;

/*
 * Next implementation: The Game object gets a pointer to the Canvas object, then the game ist started and not the canvas.
 * The Game loop is going to be in the game object and calls the drawing and not the other way around.
 */

int main(int argc, char *argv[])
{
    Game game(SIZE, SIZE, SPEED);
    Canvas canvas(&game, SIZE, SIZE);
    canvas.init();

    return 0;
}
