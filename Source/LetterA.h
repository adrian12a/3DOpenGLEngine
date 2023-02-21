#pragma once
#include "Engine.h"

/*!
* \class LetterA
* \brief Klasa sluzaca do tworzenia litery A
*
* \param x wspolrzedna x
* \param y wspolrzedna y
* \param size wielkosc (szerokosc linii)
* \param r skladowa koloru - kolor czerwony
* \param g skladowa koloru - kolor zielonu
* \param b skladowa koloru - kolor niebieski
*/

class LetterA
{
public:
	float x, y;
	float size;
	float r, g, b;
	/**
	 * Konstruktor
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 * \param size wielkosc (szerokosc linii)
	 * \param r skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielonu
	 * \param b skladowa koloru - kolor niebieski
	 */
	LetterA(float x, float y, float size, float r, float g, float b);
	/**
	 * Wyswietlenie litery
	 *
	 */
	void draw();
};
