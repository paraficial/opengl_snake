#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"
#include "shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define PIXELSIZE 20

using namespace std;

class Canvas
{
public:
    Canvas(Game *game, int width, int height);
    void init();
    void calcFoodPosition();

    Game *game;
    int **board;

private:
    GLFWwindow *window;

    int width, height;

    GLfloat *snakePosition;
    GLfloat *foodPosition;
    int counter;
};

#endif // CANVAS_H
