#pragma once
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*!
* \class Cube
* \brief Klasa sluzaca do tworzenia szescianu
*
* \param centerPosX wspolrzedna x srodka szescianu
* \param centerPosY wspolrzedna y srodka szescianu
* \param centerPosZ wspolrzedna x srodka szescianu
* \param edgeLength dlugosc boku szescianu
*/

class Cube {
public:
	GLfloat centerPosX;
	GLfloat centerPosY;
	GLfloat centerPosZ;
	GLfloat edgeLength;
	/**
	 * Konstruktor
	 *
	 * \param centerPosX wspolrzedna x srodka szescianu
	 * \param centerPosY wspolrzedna y srodka szescianu
	 * \param centerPosZ wspolrzedna x srodka szescianu
	 * \param edgeLength dlugosc boku szescianu
	 */
	Cube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
	/**
	 * Rysowanie szescianu
	 *
	 */
	void draw();
};
