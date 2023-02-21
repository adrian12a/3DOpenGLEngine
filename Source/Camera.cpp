#include "Camera.h"

Camera::Camera() {
	cameraPosition = glm::vec3(0.0f, 4.0f, -10.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	cameraSpeed = 4.0f;
	mouseSensitivity = 0.4f;
	fov = 60.0f;
	firstClick = true;
}

void Camera::mouseMove(int x, int y)
{
	if (firstClick) {
		glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
		firstClick = false;
	}

	float rotX = cameraSpeed * (float)(y - (glutGet(GLUT_WINDOW_HEIGHT) / 2)) / glutGet(GLUT_WINDOW_HEIGHT);
	float rotY = cameraSpeed * (float)(x - (glutGet(GLUT_WINDOW_WIDTH) / 2)) / glutGet(GLUT_WINDOW_WIDTH);

	glm::vec3 newOrientation = glm::rotate(cameraPosition, glm::radians(-rotX), glm::normalize(glm::cross(cameraPosition, cameraUp)));
	cameraPosition = newOrientation;
	cameraPosition = glm::rotate(cameraPosition, glm::radians(-rotY), cameraUp);

	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
}

void Camera::mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN)
			glutSetCursor(GLUT_CURSOR_NONE);
		else
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
	else
		firstClick = true;
}

void Camera::mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
		fov -= 1.0;
	else
		fov += 1.0;
}

void Camera::keyPress(unsigned char key)
{
	switch (key) {
	case 'w':
		cameraPosition -= cameraSpeed * cameraFront;
		break;
	case 's':
		cameraPosition += cameraSpeed * cameraFront;
		break;
	case 'a':
		cameraPosition += cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
		break;
	case 'd':
		cameraPosition -= cameraSpeed * glm::normalize(glm::cross(cameraFront, cameraUp));
		break;
	case 'r':
		cameraPosition += cameraSpeed * cameraUp;
		break;
	case 'f':
		cameraPosition += cameraSpeed * -cameraUp;
		break;
	}
}