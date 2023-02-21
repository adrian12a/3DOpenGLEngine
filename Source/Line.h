#pragma once
#include "Engine.h"

/*!
* \class Line
* \brief Klasa sluzaca do tworzenia linii
*
* \param x1 wspolrzedna x poczatku linii
* \param y1 wspolrzedna y poczatku linii
* \param x2 wspolrzedna x konca linii
* \param y2 wspolrzedna y konca linii
* \param size wielkosc (szerokosc linii)
* \param r skladowa koloru - kolor czerwony
* \param g skladowa koloru - kolor zielonu
* \param b skladowa koloru - kolor niebieski
*/

class Line
{
public:
	float x1;
	float y1;
	float x2;
	float y2;
	float size;
	float r;
	float g;
	float b;
	/**
	 * Konstruktor
	 *
	 * \param x1 wspolrzedna x poczatku linii
	 * \param y1 wspolrzedna y poczatku linii
	 * \param x2 wspolrzedna x konca linii
	 * \param y2 wspolrzedna y konca linii
	 * \param size wielkosc (szerokosc linii)
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	Line(float x1, float y1, float x2, float y2, float size, float r, float g, float b);
	/**
	 * Wyswietlenie linii
	 *
	 */
	void draw();
	/**
	 * Wyswietlenie lini lamanej otwartej
	 *
	 * \param v kolekcja linii
	 * \param size wielkosc (szerokosc linii)
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	static void drawLineStrip(std::vector<Line> v, float size, float r, float g, float b);
	/**
	 * Wyswietlenie lini lamanej zamknietej
	 *
	 * \param v kolekcja linii
	 * \param size wielkosc (szerokosc linii)
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	static void drawLineLoop(std::vector<Line> v, float size, float r, float g, float b);
private:
	/**
	 * Wyswietlenie kolekcji linii
	 *
	 * \param v kolekcja linii
	 * \param size wielkosc (szerokosc linii)
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 * \param closed true - zamknieta, false - otwarta
	 */
	static void drawLines(std::vector<Line> v, float size, float r, float g, float b, bool closed);
};
