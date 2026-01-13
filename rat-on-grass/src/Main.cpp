#include <iostream>

#include "header-files/Window.h"

int main() {

	Window window(840, 600, "A fat rat on grass");

	while (!window.ShouldClose()) {

		glClearColor(0.3f, 0.2f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffer();
		window.pollEvents();
	}

	glfwTerminate();
	return 0;
}