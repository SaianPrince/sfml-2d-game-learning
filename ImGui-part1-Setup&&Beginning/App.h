#pragma once
#include "nWindow.h"
#include "Grill.h"
#include "Snake.h"

class Application 
{

public:
	Application();
	void create(int width, int length);
	void start(int fps = 60);


private:

	void createFrame();
	void drawFunc();
	void updateScene();
	void keyPressed(sf::Keyboard::Key);
	void keyReleased(sf::Keyboard::Key);
	void mouseMovement(sf::Event::MouseMoveEvent);
	void mouseClick(sf::Event::MouseButtonEvent);
	Grill m_grill;
	Snake m_snake;
	nWindow window;
	sf::Clock nClock;
	sf::Time frameTime;
	sf::Time elapsedTime;
	
};
