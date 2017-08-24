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

    this->snakePosition = new GLfloat[width * height * 3];
    this->foodPosition = new GLfloat[3];
    counter = 0;
//    calcFoodPosition();
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
    GLuint VectorIDColorSnake = glGetUniformLocation(programID, "CS");
    GLuint VectorIDColorFood = glGetUniformLocation(programID, "CF");

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

    glm::vec3 CS = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 CF = glm::vec3(0.0f, 0.0f, 1.0f);

    GLuint snakePositionBuffer;
    glGenBuffers(1, &snakePositionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, snakePositionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * width * height * 3, snakePosition, GL_STATIC_DRAW);

    GLint maxUniformBlockSize, maxUniformBlocksVertex, maxUniformAlignment;
    // maximum size of uniform block
    glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &maxUniformBlockSize);
    // maximum number of uniform blocks in each shader (vertex, frag, etc)
    glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, &maxUniformBlocksVertex);
    // alignment for multiple uniform blocks in one UBO - glBindBufferRange()
    glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &maxUniformAlignment);

    cout << maxUniformBlockSize << endl;
    cout << maxUniformBlocksVertex << endl;
    cout << maxUniformAlignment << endl;

    float counter = 0;
    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
        glUniform3fv(VectorIDColorSnake, 1, &CS[0]);
        glUniform3fv(VectorIDColorFood, 1, &CF[0]);

        calcFoodPosition();
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * width * height * 3, snakePosition, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, snakePositionBuffer);
        glVertexAttribPointer(
                    0,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, snakePositionBuffer);
        glVertexAttribPointer(
                    1,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);


        glDrawArrays(GL_POINTS, 0, width*height);
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

void Canvas::calcFoodPosition()
{
    int range = width;
    cout << width << endl;
    for (int i = 0; i < width*height*3; i++) {
        snakePosition[i] = (float) (rand() % width - width/2);
    }
}
