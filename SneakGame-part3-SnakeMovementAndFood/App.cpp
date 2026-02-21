#include "App.h"
#include "Cell.h"
#include "Grill.h"
#include "Snake.h"

sf::RectangleShape rectangular;

Application::Application()
{

}

void Application::create(int width, int length)
{
	window.nCreate(width, length);
	window.addMouseMoveFunc(std::bind(&Application::mouseMovement, this, std::placeholders::_1));
	window.addMouseClickFunc(std::bind(&Application::mouseClick, this, std::placeholders::_1));
	window.addKeyPressFunc(std::bind(&Application::keyPressed, this, std::placeholders::_1));
	m_grill.set(width,50);
	m_snake.set(50, width, length);

}

void Application::start(int fps)
{
	frameTime = sf::seconds(1.0f / fps);

	while (window.isWindowOpen())
	{
		window.eventManage();

		sf::Time delta = nClock.restart();

		if (delta < frameTime)
		{
			sf::sleep(frameTime - delta);
		}

		createFrame();
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
	m_grill.m_draw(window);
	m_snake.m_draw(window);
	window.show();
}

void Application::updateScene()
{
	m_snake.snakeMove();
	
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left)
		m_snake.m_setDirection(cellDirection::Left);
	if (key == sf::Keyboard::Right)
		m_snake.m_setDirection(cellDirection::Right);
	if (key == sf::Keyboard::Up)
		m_snake.m_setDirection(cellDirection::Up);
	if (key == sf::Keyboard::Down)
		m_snake.m_setDirection(cellDirection::Down);
	if (key == sf::Keyboard::Space)
		m_snake.addTail();
	/*
if (key == sf::Keyboard::LControl)
		m_snake.food(window);
		*/
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
