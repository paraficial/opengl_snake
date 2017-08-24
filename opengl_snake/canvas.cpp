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
    for (int i = 0; i < 10; i++) {
        cout << foodSnakePosition[i] << endl;
    }
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

    glPointSize(PIXELSIZE);

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

//    GLint maxUniformBlockSize, maxUniformBlocksVertex, maxUniformAlignment;
//    // maximum size of uniform block
//    glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &maxUniformBlockSize);
//    // maximum number of uniform blocks in each shader (vertex, frag, etc)
//    glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, &maxUniformBlocksVertex);
//    // alignment for multiple uniform blocks in one UBO - glBindBufferRange()
//    glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &maxUniformAlignment);

//    cout << maxUniformBlockSize << endl;
//    cout << maxUniformBlocksVertex << endl;
//    cout << maxUniformAlignment << endl;

    do {
        recalcBuffers();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, foodSnakePositionBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * (width * height + 1) , foodSnakePosition, GL_STATIC_DRAW);
        glVertexAttribPointer(
                    0,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, foodSnakeColorBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * (width * height + 1), foodSnakeColor, GL_STATIC_DRAW);
        glVertexAttribPointer(
                    1,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);
        glDrawArrays(GL_POINTS, 0, game->snake->size()+1);

        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && get<1>(game->snake->at(0)) < height/2 - 1) {
            get<1>(game->snake->at(0))++;
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            get<1>(game->snake->at(0))--;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            get<0>(game->snake->at(0))--;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            get<0>(game->snake->at(0))++;
        }
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

void Canvas::recalcBuffers()
{
    float CS[3] = {0.0f, 1.0f, 0.0f};
    float CF[3] = {0.0f, 0.0f, 1.0f};

    // The first vertex is always the food position.
    foodSnakePosition[0] = get<0>(game->startfood);
    foodSnakePosition[1] = get<1>(game->startfood);
    foodSnakePosition[2] = 0;

    foodSnakeColor[0] = CF[0];
    foodSnakeColor[1] = CF[1];
    foodSnakeColor[2] = CF[2];

    // Fill with snake vertices.
    int offset = 3;
    for (int i = 0; i < game->snake->size(); i+=3) {
        foodSnakePosition[offset + i + 0] = get<0>(game->snake->at(i));
        foodSnakePosition[offset + i + 1] = get<1>(game->snake->at(i));
        foodSnakePosition[offset + i + 2] = 0;

        foodSnakeColor[offset + i + 0] = CS[0];
        foodSnakeColor[offset + i + 1] = CS[1];
        foodSnakeColor[offset + i + 2] = CS[2];
    }
}
