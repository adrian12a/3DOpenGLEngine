#pragma once
#include "Engine.h"

/*!
* \class Triangle
* \brief Klasa sluzaca do tworzenia trojkata
*
* \param x1 wspolrzedna x pierwszego punktu
* \param y1 wspolrzedna y pierwszego punktu
* \param x2 wspolrzedna x drugiego punktu
* \param y2 wspolrzedna y drugiego punktu
* \param x3 wspolrzedna x trzeciego punktu
* \param y3 wspolrzedna y trzeciego punktu
* \param size wielkosc
* \param r skladowa koloru - kolor czerwony
* \param g skladowa koloru - kolor zielonu
* \param b skladowa koloru - kolor niebieski
*/

class Triangle
{
public:
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float size;
	float r;
	float g;
	float b;
	/**
	 * Konstruktor
	 *
	 * \param x1 wspolrzedna x pierwszego punktu
	 * \param y1 wspolrzedna y pierwszego punktu
	 * \param x2 wspolrzedna x drugiego punktu
	 * \param y2 wspolrzedna y drugiego punktu
	 * \param x3 wspolrzedna x trzeciego punktu
	 * \param y3 wspolrzedna y trzeciego punktu
	 * \param size wielkosc
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float size, float r, float g, float b);
	/**
	 * Wyswietlenie trojkata
	 *
	 */
	void draw();
	/**
	 * Wyswietlenie paska trojkatow
	 *
	 * \param v kolekcja trojkatow
	 * \param size wielkosc
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	static void drawTriangleStrip(std::vector<Triangle> v, float size, float r, float g, float b);
	/**
	 * Wyswietlenie wachlarza trojkatow
	 *
	 * \param v kolekcja trojkatow
	 * \param size wielkosc
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	static void drawTriangleFan(std::vector<Triangle> v, float size, float r, float g, float b);
private:
	/**
	 * Wyswietlenie kolekcji trojkatow
	 *
	 * \param v kolekcja trojkatow
	 * \param size wielkosc
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 * \param strip true - pasek, false - wachlarz
	 */
	static void drawTriangles(std::vector<Triangle> v, float size, float r, float g, float b, bool strip);
};
