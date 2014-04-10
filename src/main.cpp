#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "app.h"

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
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(800, 600, "Azteroids", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    App application;

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        double timeNow, timeLast = 0;

        glfwGetFramebufferSize(window, &width, &height);

        timeNow = glfwGetTime();
        application.update(timeNow - timeLast);
        timeLast = timeNow;

        application.draw(width, height);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

