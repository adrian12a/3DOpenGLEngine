#pragma once
#include "Engine.h"

/*!
* \class Rectangle2D
* \brief Klasa sluzaca do tworzenia prostokata
*
* \param x1 wspolrzedna x pierwszego punktu
* \param y1 wspolrzedna y pierwszego punktu
* \param x2 wspolrzedna x drugiego punktu
* \param y2 wspolrzedna y drugiego punktu
* \param x3 wspolrzedna x trzeciego punktu
* \param y3 wspolrzedna y trzeciego punktu
* \param x4 wspolrzedna x czwartego punktu
* \param y4 wspolrzedna y czwartego punktu
* \param size wielkosc
* \param r skladowa koloru - kolor czerwony
* \param g skladowa koloru - kolor zielonu
* \param b skladowa koloru - kolor niebieski
*/

class Rectangle2D
{
public:
	float x1, y1;
	float x2, y2;
	float x3, y3;
	float x4, y4;
	float size;
	float r, g, b;
	/**
	 * Konstruktor
	 *
	 * \param x1 wspolrzedna x pierwszego punktu
	 * \param y1 wspolrzedna y pierwszego punktu
	 * \param x2 wspolrzedna x drugiego punktu
	 * \param y2 wspolrzedna y drugiego punktu
	 * \param x3 wspolrzedna x trzeciego punktu
	 * \param y3 wspolrzedna y trzeciego punktu
	 * \param x4 wspolrzedna x czwartego punktu
	 * \param y4 wspolrzedna y czwartego punktu
	 * \param size wielkosc
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	Rectangle2D(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float size, float r, float g, float b);
	/**
	 * Wyswietlenie prostokata
	 *
	 */
	void draw();
};
