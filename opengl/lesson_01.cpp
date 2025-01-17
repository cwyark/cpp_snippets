#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    std::exit(-1);
  }
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window;
  window = glfwCreateWindow(1024, 768, "Tutorial 001", NULL, NULL);
  if (window == NULL) {
    std::cerr << "Failed to open GLFW window" << std::endl;
    glfwTerminate();
    std::exit(-1);
  }
  glfwMakeContextCurrent(window);
  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW" << std::endl;
    std::exit(-1);
  }

  std::exit(0);
}
