#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "app.h"

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

    // user actions:
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
            case GLFW_KEY_UP:
                application.send_up();
                break;
            case GLFW_KEY_DOWN:
                application.send_down();
                break;
            case GLFW_KEY_LEFT:
                application.send_left();
                break;
            case GLFW_KEY_RIGHT:
                application.send_right();
                break;
            case GLFW_KEY_SPACE:
                application.send_space();
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

