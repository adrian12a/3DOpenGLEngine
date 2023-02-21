#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float size, float r, float g, float b)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Rectangle2D::draw()
{
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_QUADS);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
	glVertex2d(x4, y4);
	glEnd();
}