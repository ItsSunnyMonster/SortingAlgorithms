#include "Window.hpp"

#include "ErrorHandling.hpp"

static GLFWwindow *pGlfwWindow;

static void windowResize(GLFWwindow *pWindow, int width, int height) {
  glViewport(0, 0, width, height);
}

void AV::Window::showWindow(WindowProps props) {
  if (pGlfwWindow == nullptr) {
    AV_ASSERT(glfwInit(), "Unable to create window!");

    AV_ASSERT(false, "BRUH");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    pGlfwWindow = glfwCreateWindow(props.width, props.height, props.pszTitle,
                                   nullptr, nullptr);
    AV_ASSERT(pGlfwWindow != nullptr, "Unable to create window!");

    glfwSetWindowSizeCallback(pGlfwWindow, windowResize);

    int width;
    int height;

    glfwGetWindowSize(pGlfwWindow, &width, &height);
    const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwSetWindowPos(pGlfwWindow, (vidmode->width - width) / 2,
                     (vidmode->height - height) / 2);

    glfwMakeContextCurrent(pGlfwWindow);

    int version = gladLoadGL(glfwGetProcAddress);
    AV_ASSERT(version, "Unable to initialize OpenGL context!");

    std::cout << "Loaded OpenGL " << GLAD_VERSION_MAJOR(version) << "."
              << GLAD_VERSION_MINOR(version) << "\n";

    glfwSwapInterval(1);
    glfwShowWindow(pGlfwWindow);
  }
}

void AV::Window::destroyWindow() {
  if (!pGlfwWindow)
    return;
  glfwDestroyWindow(pGlfwWindow);
  pGlfwWindow = nullptr;
  glfwTerminate();
}

GLFWwindow *AV::Window::getGlfwWindow() { return pGlfwWindow; }

void AV::Window::update() {
  if (!pGlfwWindow)
    return;
  glfwSwapBuffers(pGlfwWindow);
  glfwPollEvents();
}

bool AV::Window::windowShouldClose() {
  if (!pGlfwWindow)
    return true;
  return glfwWindowShouldClose(pGlfwWindow);
}
