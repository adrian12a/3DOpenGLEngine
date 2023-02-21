#pragma once
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "Cube.h"
#include "Camera.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle2D.h"
#include "LetterA.h"
#include "BitmapHandler.h"

using namespace std;

/*!
* \class Engine
* \brief Glowna klasa silnika
*
* \param instance instancja silnika
* \param camera obiekt kamery
* \param demoNumber numer aktualnie wyswietlanego dema prezentujacego mozliwosci silnika
* \param TexID identyfikator tekstury
*/

class Engine
{
public:
	static Engine* instance;
	static Camera camera;
	int demoNumber;
	GLuint TexID[1];
	/**
	 * Przygotowanie sceny, przygotowanie oswietlenia
	 */
	void initScene();
	/**
	 * Wyczyszczenie ekranu do zadanego koloru
	 *
	 * \param r	skladowa koloru - kolor czerwony
	 * \param g skladowa koloru - kolor zielony
	 * \param b skladowa koloru - kolor niebieski
	 * \param alpha przezroczystosc
	 */
	void clearToColor(float r, float g, float b, float alpha);
	/**
	 * Odswiezanie sceny
	 */
	void onRenderScene();
	/**
	 * Zmiana perspektywy przy zmianie rozmiaru okna
	 *
	 * \param w szerokosc okna
	 * \param h wysokosc okna
	 */
	void onChangeSize(int w, int h);
	/**
	 * Obsluga nacisniecia przycisku na klawiaturze
	 *
	 * \param key przycisk
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	void onKey(unsigned char key, int x, int y);
	/**
	 * Obsluga ruchu myszki
	 *
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	void onMouseMove(int x, int y);
	/**
	 * Obsluga nacisniecia przycisku myszki
	 *
	 * \param button przycisk
	 * \param state stan (wcisniety, niewcisniety)
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	void onMouseButton(int button, int state, int x, int y);
	/**
	 * Obsluga poruszania kolkiem myszki
	 *
	 * \param button przycisk
	 * \param dir kierunek
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	void onMouseWheel(int button, int dir, int x, int y);
	/**
	 * Animacja
	 *
	 */
	void onIdle();
	/**
	 * Ustawienie kamery
	 *
	 */
	void setDisplayMatricies();
	/**
	 * Wyswietlenie dema prezentujacego silnik
	 *
	 */
	void viewDemo();
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutDisplayFunc
	 *
	 */
	static void onRenderSceneWrapper();
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutReshapeFunc
	 *
	 * \param w szerokosc okna
	 * \param h wysokosc okna
	 */
	static void onChangeSizeWrapper(int w, int h);
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutKeyboardFunc
	 *
	 * \param key przycisk
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	static void onKeyWrapper(unsigned char key, int x, int y);
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutMotionFunc
	 *
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	static void onMouseMoveWrapper(int x, int y);
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutMouseFunc
	 *
	 * \param button przycisk
	 * \param state stan (wcisniety, niewcisniety)
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	static void onMouseButtonWrapper(int button, int state, int x, int y);
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutMouseWheelFunc
	 *
	 * \param button przycisk
	 * \param dir kierunek
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 */
	static void onMouseWheelWrapper(int button, int dir, int x, int y);
	/**
	 * Funkcja umozliwiajaca przekazanie metody klasy jako funkcji glutIdleFunc
	 *
	 */
	static void onIdleWrapper();
	/**
	 * Konstruktor
	 *
	 * \param argc argc
	 * \param argv argv
	 * \param windowName nazwa okna
	 * \param width szerokosc okna
	 * \param height wysokosc okna
	 */
	Engine(int argc, char* argv[], const char* windowName, int width, int height);
};
