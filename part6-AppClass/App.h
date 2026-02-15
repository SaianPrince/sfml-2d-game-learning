#pragma once
#include "nWindow.h"

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


	nWindow window;
	sf::Clock nClock;
	sf::Time frameTime;
	sf::Time elapsedTime;
	
};
