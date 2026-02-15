#include "App.h"

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
	window.nDraw(rectangular);
	window.show();
}

void Application::updateScene()
{
}

void Application::keyPressed(sf::Keyboard::Key key)
{
		auto pos = rectangular.getPosition();
		if (key==(sf::Keyboard::Left)) // the circle will go to left when pressed left button
		{
			pos.x -= 10;
		}
		if (key==sf::Keyboard::Right) // the circle will go to right when pressed right button
		{
			pos.x += 10;
		}
		if (key==sf::Keyboard::Up) // the circle will go to up when pressed up button
		{
			pos.y -= 10;
		}
		if (key==sf::Keyboard::Down) // the circle will go to down when pressed down button
		{
			pos.y += 10;
		}
		rectangular.setPosition(pos);

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
