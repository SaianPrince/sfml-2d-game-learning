#include "App.h"
#include "Cell.h"
#include "Grill.h"

Cell cell1;
Grill grill;

sf::RectangleShape rectangular;

Application::Application()
{
	rectangular.setSize(sf::Vector2f(100, 100));
}

void Application::create(int width, int length)
{
	window.nCreate(width, length);
	window.addMouseMoveFunc(std::bind(&Application::mouseMovement, this, std::placeholders::_1));
	window.addMouseClickFunc(std::bind(&Application::mouseClick, this, std::placeholders::_1));
	window.addKeyPressFunc(std::bind(&Application::keyPressed, this, std::placeholders::_1));
	grill.set(width,20);

}

void Application::start(int fps)
{
	float nFPS = 1.0f / fps;
	frameTime = sf::seconds(nFPS);

	elapsedTime = nClock.restart();

	while(window.isWindowOpen())
	{
		window.eventManage();
		
		elapsedTime = nClock.getElapsedTime();

		if (elapsedTime >= frameTime)
		{
			createFrame();
			elapsedTime = elapsedTime - frameTime;
		}
		else
		{
			sf::sleep(elapsedTime - frameTime);
		}
	}
}

void Application::createFrame()
{
	updateScene();
	drawFunc();
}

void Application::drawFunc()
{
	window.nClear();
	cell1.m_draw(window);
	grill.m_draw(window);
	window.show();
}

void Application::updateScene()
{
	cell1.m_move();
	
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
		cell1.m_setDirection(cellDirection::Left);
	if (key == sf::Keyboard::Right)
		cell1.m_setDirection(cellDirection::Right);
	if (key == sf::Keyboard::Up)
		cell1.m_setDirection(cellDirection::Up);
	if (key == sf::Keyboard::Down)
		cell1.m_setDirection(cellDirection::Down);
}

void Application::keyReleased(sf::Keyboard::Key)
{
}

void Application::mouseMovement(sf::Event::MouseMoveEvent)
{
}

void Application::mouseClick(sf::Event::MouseButtonEvent)
{
}
