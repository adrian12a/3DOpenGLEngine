#pragma once
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include "stb_image.h"

using namespace std;

/*!
* \class BitmapHandler
* \brief Klasa sluzaca do wczytywania tekstur z plikow
*
* \param filename nazwa pliku zawierajacego teksture
* \param texture identyfikator tekstury
*/

class BitmapHandler
{
public:
	string filename;
	GLenum texture;
	/**
	 * Konstruktor
	 *
	 * \param texture nazwa pliku zawierajacego teksture
	 * \param filename nazwa pliku zawierajacego teksture
	 */
	BitmapHandler(GLenum texture, string filename);
	/**
	 * Zaladowanie tekstury z pliku
	 *
	 */
	void loadBitmap();
};
