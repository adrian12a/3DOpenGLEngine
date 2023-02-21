#include "Line.h"
#include "Engine.h"

Line::Line(float x1, float y1, float x2, float y2, float size, float r, float g, float b)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Line::draw()
{
	glColor3f(r, g, b);
	glPointSize(size);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

void Line::drawLineStrip(std::vector<Line> v, float size, float r, float g, float b)
{
	drawLines(v, size, r, g, b, false);
}

void Line::drawLineLoop(std::vector<Line> v, float size, float r, float g, float b)
{
	drawLines(v, size, r, g, b, true);
}

void Line::drawLines(std::vector<Line> v, float size, float r, float g, float b, bool closed)
{
	glColor3f(r, g, b);
	glPointSize(size);
	if (closed)
		glBegin(GL_LINE_LOOP);
	else
		glBegin(GL_LINE_STRIP);
	for (int i = 0; i < v.size(); i++) {
		glVertex2d(v[i].x1, v[i].y1);
		glVertex2d(v[i].x2, v[i].y2);
	}
	glEnd();
}