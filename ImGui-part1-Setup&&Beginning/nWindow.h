#pragma once
#include <SFML/Graphics.hpp>
#include "FuncTypes.h"

class nWindow {
public:
	void nCreate(unsigned int width, unsigned int length, const sf::String& text = "SFML");
	void nDraw(const sf::Drawable& shape);
	void eventManage();
	bool isWindowOpen();
	void nClear();
	void show();
	void update(const sf::Time& time);
	void addKeyPressFunc(keyboardFunc newFunc);
	void addMouseMoveFunc(mouseMoveFunc mouseMove);
	void addMouseClickFunc(mouseClick click);
	void shutDown();
private:

	sf::RenderWindow newWindow;
	keyboardFuncList nKeyPressFuncList;
	mouseMoveFuncList nMouseMoveFuncList;
	mouseClickList nMouseClickList;
};
