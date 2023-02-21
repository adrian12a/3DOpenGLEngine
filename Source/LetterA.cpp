#include "LetterA.h"

LetterA::LetterA(float x, float y, float size, float r, float g, float b)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

void LetterA::draw()
{
	glColor3f(r, g, b);
	glPointSize(3.0);
	glBegin(GL_LINES);
	glVertex2d(x, y);
	glVertex2d(x + size / 4, y + size);
	glVertex2d(x + size / 4, y + size);
	glVertex2d(x + size / 2, y);
	glVertex2d(x + size / 8, y + size * 2 / 4);
	glVertex2d(x + size / 2 - size / 8, y + size * 2 / 4);
	glEnd();
}