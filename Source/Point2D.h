#pragma once
#include "Engine.h"

/*!
* \class Point2D
* \brief Klasa sluzaca do tworzenia punktu 2D
*
* \param x wspolrzedna x punktu
* \param y wspolrzedna y punktu
* \param size wielkosc punktu
* \param r skladowa koloru - kolor czerwony
* \param g skladowa koloru - kolor zielonu
* \param b skladowa koloru - kolor niebieski

*/

class Point2D
{
public:
	float x;
	float y;
	float size;
	float r;
	float g;
	float b;
	/**
	 * Konstruktor
	 *
	 * \param x wspolrzedna x punktu
	 * \param y wspolrzedna y punktu
	 * \param size wielkosc punktu
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	Point2D(float x, float y, float size, float r, float g, float b);
	/**
	 * Wyswietlenie punktu
	 *
	 */
	void draw();
	/**
	 * Wyswietlenie kolekcji punktow
	 *
	 * \param v kolekcja punktow
	 * \param size wielkosc punktow
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	static void drawPointsCollection(std::vector<Point2D> v, float size, float r, float g, float b);
};
