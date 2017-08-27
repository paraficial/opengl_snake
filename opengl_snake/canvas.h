#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <tuple>
#include <chrono>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"
#include "shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define PIXELSIZE 20

using namespace std;
using namespace std::chrono;

class Canvas
{
public:
    Canvas(Game *game, int width, int height);
    void init();
    void recalcBuffers();
    void calcInput();

    Game *game;
    int **board;

private:
    GLFWwindow *window;

    int width, height;

    GLfloat *foodSnakePosition;
    GLfloat *foodSnakeColor;

    high_resolution_clock::time_point lastTime;
    high_resolution_clock::time_point currentTime;
    duration<double, milli> dur;
    int fpsCounter;

    tuple<int, int> direction;
};

#endif // CANVAS_H
