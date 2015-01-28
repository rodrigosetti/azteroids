#include <GLFW/glfw3.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include <app.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int SPACE_WIDTH = 800;
const int SPACE_HEIGHT = 600;

App application(SPACE_WIDTH, SPACE_HEIGHT);

static void error_callback (int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        return;
    }

    // set keys
    if (action == GLFW_PRESS || action == GLFW_RELEASE) {
        bool key_pressed = action == GLFW_PRESS;
        switch (key) {
            case GLFW_KEY_UP:
                application.keys_pressed.up    = key_pressed;
                break;
            case GLFW_KEY_DOWN:
                application.keys_pressed.down   = key_pressed;
                break;
            case GLFW_KEY_LEFT:
                application.keys_pressed.left  = key_pressed;
                break;
            case GLFW_KEY_RIGHT:
                application.keys_pressed.right = key_pressed;
                break;
            case GLFW_KEY_SPACE:
                application.keys_pressed.space = key_pressed;
                break;
        }
    }
}

int main (void) {
    GLFWwindow* window;
    float lastTime = 0;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Azteroids", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    application.initialize();

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double time = glfwGetTime();
        application.step(time - lastTime);
        lastTime = time;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

