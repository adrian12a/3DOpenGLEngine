#include "Triangle.h"

Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float size, float r, float g, float b)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Triangle::draw()
{
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_TRIANGLES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
	glEnd();
}

void Triangle::drawTriangleStrip(std::vector<Triangle> v, float size, float r, float g, float b)
{
	drawTriangles(v, size, r, g, b, true);
}

void Triangle::drawTriangleFan(std::vector<Triangle> v, float size, float r, float g, float b)
{
	drawTriangles(v, size, r, g, b, false);
}

void Triangle::drawTriangles(std::vector<Triangle> v, float size, float r, float g, float b, bool strip)
{
	glColor3f(r, g, b);
	glPointSize(size);
	if (strip)
		glBegin(GL_TRIANGLE_STRIP);
	else
		glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < v.size(); i++) {
		glVertex2d(v[i].x1, v[i].y1);
		glVertex2d(v[i].x2, v[i].y2);
		glVertex2d(v[i].x3, v[i].y3);
	}
	glEnd();
}