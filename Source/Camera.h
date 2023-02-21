#pragma once
#include <gl/glut.h>
#include <gl/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

/*!
* \class Camera
* \brief Klasa sluzaca do zarzadzania kamera
*
* \param cameraPosition pozycja kamery
* \param cameraFront kierunek w ktorym skierowana jest kamera
* \param cameraUp pozycja kamery w osi gora-dol
* \param cameraSpeed szybkosc poruszania kamery (sterowanie klawiatura)
* \param mouseSensitivity szybkosc poruszania kamery (sterowanie myszka)
* \param fov pole widzenia
* \param firstClick zmienna pomocnicza (zapobieganie skoku kamery przy pierwszym kliknieciu)
*/

class Camera {
public:
	glm::vec3 cameraPosition;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	float cameraSpeed;
	float mouseSensitivity;
	float fov;
	bool firstClick;
	/**
	 * Konstruktor
	 *
	 */
	Camera();
	/**
	 * Poruszanie kamera, gdy uzytkownik porusza myszka
	 *
	 * \param x wspolrzedna x myszki
	 * \param y wspolrzedna y myszki
	 */
	void mouseMove(int x, int y);
	/**
	 * Ukrycie kursora myszki, gdy uzytkownik nacisnie przycisk myszy
	 *
	 * \param button przycisk
	 * \param state stan przycisku (wcisniety, niewcisniety)
	 * \param x wspolrzedna x myszki
	 * \param y wspolrzedna y myszki
	 */
	void mouseButton(int button, int state, int x, int y);
	/**
	 * Przyblizanie/oddalanie kamery, gdy uzytkownik porusza kolkiem myszki
	 *
	 * \param button przycisk
	 * \param dir kierunek
	 * \param x wspolrzedna x myszki
	 * \param y wspolrzedna y myszki
	 */
	void mouseWheel(int button, int dir, int x, int y);
	/**
	 * Poruszanie kamera, gdy uzytkownik nacisnie przycisk na klawiaturze
	 *
	 * \param key przycisk
	 */
	void keyPress(unsigned char key);
};
