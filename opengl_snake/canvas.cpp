#include "canvas.h"

Canvas::Canvas(Game *game, int width, int height)
{
    this->game = game;
    this->board = new int*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new int[width];
    }
    this->width = width;
    this->height = height;

    this->foodSnakePosition = new GLfloat[(width * height + 1) * 3];
    this->foodSnakeColor= new GLfloat[(width * height + 1) * 3];

    recalcBuffers();

    lastTime = currentTime = high_resolution_clock::now();
    fpsCounter = 0;
}

void Canvas::init()
{
    if (!glfwInit()) {
        cout << "Failed to initialize GLFW" << endl;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width * PIXELSIZE, height * PIXELSIZE, "OpenGL Snake", NULL, NULL);

    if (window == NULL) {
        cout << "Failed to open GLFW window" << endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;

    if (glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW" << endl;
        glfwTerminate();
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    glPointSize(PIXELSIZE-0.4f);

    // Set up buffers
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    GLuint programID = LoadShaders("../shader.vert", "../shader.frag");
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

    float size = (float) width;
    glm::mat4 Projection = glm::ortho(-size/2, size/2, -size/2, size/2, 0.0f, 100.0f);
    glm::mat4 View       = glm::lookAt(
                glm::vec3(0,0,10),
                glm::vec3(0,0,0),
                glm::vec3(0,1,0)
                );
    glm::mat4 Model      = glm::mat4(1.0f);
    Model = glm::translate(Model, glm::vec3(0.5, 0.5, 0));
    glm::mat4 MVP        = Projection * View * Model;

    GLuint foodSnakePositionBuffer;
    glGenBuffers(1, &foodSnakePositionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, foodSnakePositionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * (width * height + 1) , foodSnakePosition, GL_STATIC_DRAW);

    GLuint foodSnakeColorBuffer;
    glGenBuffers(1, &foodSnakeColorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, foodSnakeColorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * (width * height + 1), foodSnakeColor, GL_STATIC_DRAW);

    do {
        recalcBuffers();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, foodSnakePositionBuffer);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 3 * (game->snake()->size() + 1), foodSnakePosition);
        glVertexAttribPointer(
                    0,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, foodSnakeColorBuffer);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat) * 3 * (game->snake()->size() + 1), foodSnakeColor);
        glVertexAttribPointer(
                    1,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);
        glDrawArrays(GL_POINTS, 0, game->snake()->size()+1);

        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
        calcInput();

        currentTime = high_resolution_clock::now();
        dur = currentTime - lastTime;
        if (dur.count() >= 1000/game->speed()) {
            if (!(get<0>(direction) + get<0>(game->direction()) == 0 && get<1>(direction) + get<1>(game->direction()) == 0))
                game->setDirection(direction);
            game->step();
            lastTime = high_resolution_clock::now();
        }
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

void Canvas::recalcBuffers()
{
    float CS[3] = {0.0f, 1.0f, 0.0f};
    float CF[3] = {0.0f, 0.0f, 1.0f};

    // The first vertex is always the food position.
    foodSnakePosition[0] = get<0>(game->food());
    foodSnakePosition[1] = get<1>(game->food());
    foodSnakePosition[2] = 0;

    foodSnakeColor[0] = CF[0];
    foodSnakeColor[1] = CF[1];
    foodSnakeColor[2] = CF[2];

    // Fill with snake vertices.
    int offset = 3;
    for (int i = 0; i < game->snake()->size(); i++) {
        foodSnakePosition[offset + i*3 + 0] = get<0>(game->snake()->at(i));
        foodSnakePosition[offset + i*3 + 1] = get<1>(game->snake()->at(i));
        foodSnakePosition[offset + i*3 + 2] = 0;

        foodSnakeColor[offset + i*3 + 0] = CS[0];
        foodSnakeColor[offset + i*3 + 1] = CS[1];
        foodSnakeColor[offset + i*3 + 2] = CS[2];
    }
}

void Canvas::calcInput()
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        direction = tuple<int, int>(0, 1);
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        direction = tuple<int, int>(0, -1);
    }
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        direction = tuple<int, int>(-1, 0);
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        direction = tuple<int, int>(1, 0);
    }
}
