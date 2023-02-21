#include "Engine.h"

Engine* Engine::instance = NULL;
Camera Engine::camera = Camera();
GLfloat angle;

Engine::Engine(int argc, char* argv[], const char* windowName, int width, int height) {
	demoNumber = 0;
	instance = this;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow(windowName);

	glutDisplayFunc(onRenderSceneWrapper);
	glutReshapeFunc(onChangeSizeWrapper);
	glutKeyboardFunc(onKeyWrapper);
	glutMouseFunc(onMouseButtonWrapper);
	glutMotionFunc(onMouseMoveWrapper);
	glutMouseWheelFunc(onMouseWheelWrapper);
	glutIdleFunc(onIdleWrapper);

	initScene();
	glutMainLoop();
}

void Engine::initScene()
{
	GLfloat LightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat LightDif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat LightSpec[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat LightPos[] = { 10.0f, 20.0f, 0.0f, 1.0f };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glBindTexture(GL_TEXTURE_2D, TexID[0]);
	BitmapHandler bitmap1 = BitmapHandler(TexID[0], "texture.png");
	bitmap1.loadBitmap();

	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpec);
	glMateriali(GL_FRONT, GL_SHININESS, 256);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	clearToColor(0.90, 0.98, 0.90, 1.0);
}

void Engine::clearToColor(float r, float g, float b, float alpha)
{
	glClearColor(r, g, b, alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::setDisplayMatricies() {
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	float aspectRatio = width / height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(camera.fov, aspectRatio, 1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.cameraPosition.x, camera.cameraPosition.y, camera.cameraPosition.z,
		camera.cameraPosition.x * camera.cameraFront.x, camera.cameraPosition.y * camera.cameraFront.y, camera.cameraPosition.z * camera.cameraFront.z,
		camera.cameraPosition.x * camera.cameraUp.x, camera.cameraPosition.y * camera.cameraUp.y, camera.cameraPosition.z * camera.cameraUp.z);
}

void Engine::onRenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setDisplayMatricies();
	viewDemo();
	glutSwapBuffers();
}

void Engine::viewDemo() {
	glRotatef(angle, 0, 1, 0);

	Triangle triangle = Triangle(-2, 0, 2, 0, 0, 5, 2, 1, 0, 1);
	Rectangle2D rectangle = Rectangle2D(-2, 0, -2, 5, 2, 5, 2, 0, 2, 0, 1, 0);
	Line line = Line(0, 0, 2, 5, 2, 1, 0, 0);
	LetterA letter = LetterA(0, 0, 4, 0.5, 1, 0);
	Cube cube = Cube(0, 0, 0, 5);
	vector<Line> l1;
	vector<Line> l2;
	vector<Triangle> t1;
	vector<Triangle> t2;

	switch (demoNumber) {
	case 0:
		triangle.draw();
		break;
	case 1:
		rectangle.draw();
		break;
	case 2:
		line.draw();
		break;
	case 3:
		letter.draw();
		break;
	case 4:
		l1.push_back(Line(3, 3, 0, 0, 2, 1, 0, 0));
		l1.push_back(Line(0, 0, -2, 0, 2, 1, 0, 0));
		l1.push_back(Line(-2, 0, 2, -1, 2, 1, 0, 0));
		Line::drawLineLoop(l1, 2, 1, 0, 1);
		break;
	case 5:
		l2.push_back(Line(0, 0, 2, 2, 2, 1, 0, 0));
		l2.push_back(Line(2, 2, 0, 2, 2, 1, 0, 0));
		l2.push_back(Line(0, 2, 4, 4, 2, 1, 0, 0));
		Line::drawLineStrip(l2, 2, 1, 1, 0);
		break;
	case 6:
		t1.push_back(Triangle(-2, 0, 2, 0, 0, 2, 2, 1, 0, 1));
		t1.push_back(Triangle(-3, 0, 3, 0, 0, 3, 2, 1, 0, 1));
		t1.push_back(Triangle(-2, 0, 1, 0, 0, 6, 2, 1, 0, 1));
		Triangle::drawTriangleFan(t1, 2, 0.5, 1, 0.9);
		break;
	case 7:
		t2.push_back(Triangle(-2, 0, 2, 4, 0, 2, 2, 1, 0, 1));
		t2.push_back(Triangle(-2, 0, -2, 3, 0, 3, 2, 1, 0, 1));
		t2.push_back(Triangle(-2, 0, 1, 5, 0, 6, 2, 1, 0, 1));
		Triangle::drawTriangleStrip(t2, 2, 0, 0, 1);
		break;
	case 8:
		glColor3f(1, 0, 1);
		glutSolidCube(3);
		break;
	case 9:
		cube.draw();
		break;
	case 10:
		glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, TexID[0]);
		glutSolidTeapot(3);
		break;
	}

	glTranslatef(0, -1000, 0);
	glutSolidCylinder(10, 10, 1, 1);

	glTranslatef(0, 1000, 0);
	glutSolidCylinder(10, 10, 1, 1);
}

void Engine::onChangeSize(int w, int h) {
	if (h == 0)	h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glm::mat4 MatP = glm::perspective<float>(glm::radians(50.0f), (float)w / h, 130, 470);
	glLoadMatrixf(glm::value_ptr(MatP));
}

void Engine::onKey(unsigned char key, int x, int y) {
	camera.keyPress(key);
	if (key == 27)
		exit(0);
	if (key == 'm')
		demoNumber++;
	if (key == 'n')
		demoNumber--;
	if (demoNumber > 10)
		demoNumber = 0;
	if (demoNumber < 0)
		demoNumber = 10;
}

void Engine::onMouseMove(int x, int y) {
	camera.mouseMove(x, y);
}

void Engine::onMouseButton(int button, int state, int x, int y) {
	camera.mouseButton(button, state, x, y);
}

void Engine::onMouseWheel(int button, int dir, int x, int y) {
	camera.mouseWheel(button, dir, x, y);
}

void Engine::onIdle() {
	static int last_time;
	int now_time = glutGet(GLUT_ELAPSED_TIME);
	if (last_time > 0) {
		float times = (now_time - last_time) / 1000.0f;
		angle += times * 25;
		if (angle >= 360)	angle -= 360;
	}
	last_time = now_time;
	glutPostRedisplay();
}

void Engine::onRenderSceneWrapper() {
	instance->onRenderScene();
}

void Engine::onChangeSizeWrapper(int w, int h) {
	instance->onChangeSize(w, h);
}

void Engine::onKeyWrapper(unsigned char key, int x, int y) {
	instance->onKey(key, x, y);
}

void Engine::onMouseMoveWrapper(int x, int y) {
	instance->onMouseMove(x, y);
}

void Engine::onMouseButtonWrapper(int button, int state, int x, int y) {
	instance->onMouseButton(button, state, x, y);
}

void Engine::onMouseWheelWrapper(int button, int dir, int x, int y) {
	instance->onMouseWheel(button, dir, x, y);
}

void Engine::onIdleWrapper() {
	instance->onIdle();
}