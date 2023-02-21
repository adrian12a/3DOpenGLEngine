#include "Point2D.h"

Point2D::Point2D(float x, float y, float size, float r, float g, float b)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Point2D::draw()
{
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void Point2D::drawPointsCollection(std::vector<Point2D> v, float size, float r, float g, float b) {
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_POINTS);
	for (int i = 0; i < v.size(); i++)
		glVertex2d(v[i].x, v[i].y);
	glEnd();
}