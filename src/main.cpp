#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "app.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int SPACE_WIDTH = 800;
const int SPACE_HEIGHT = 600;

static void error_callback (int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback (GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
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

    App application(SPACE_WIDTH, SPACE_HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, SPACE_WIDTH, 0, SPACE_HEIGHT, 0.1f, 1000);

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

