#include "nWindow.h"
#include "FuncTypes.h"


void nWindow::nCreate(unsigned int width, unsigned int length, const sf::String& text)
{
	newWindow.create(sf::VideoMode(width, length), text);
}

void nWindow::nDraw(const sf::Drawable& shape)
{
	newWindow.draw(shape);
}

void nWindow::eventManage() 
{
	sf::Event nEvent;
	while (newWindow.pollEvent(nEvent)) 
	{
		if (nEvent.type == sf::Event::Closed) 
		{
			newWindow.close();
		}
		if (nEvent.type == sf::Event::KeyPressed) 
		{
			for (auto next : nKeyPressFuncList) 
			{
				next(nEvent.key.code);
			}
		}
		if (nEvent.type == sf::Event::MouseMoved) 
		{
			for (auto next : nMouseMoveFuncList)
			{
				next(nEvent.mouseMove);
			}
		}
		if (nEvent.type == sf::Event::MouseButtonPressed) 
		{
			for (auto next : nMouseClickList)
			{
				next(nEvent.mouseButton);
			}
		}
	}
}

bool nWindow::isWindowOpen()
{
	return newWindow.isOpen();
}

void nWindow::nClear() 
{
	newWindow.clear(sf::Color::White);
}

void nWindow::show() 
{
	newWindow.display();
}

void nWindow::addKeyPressFunc(keyboardFunc newFunc)
{
	nKeyPressFuncList.push_back(newFunc);
}

void nWindow::addMouseMoveFunc(mouseMoveFunc mouseMove)
{
	nMouseMoveFuncList.push_back(mouseMove);
}

void nWindow::addMouseClickFunc(mouseClick click)
{
	nMouseClickList.push_back(click);
}
