#pragma once
#include <SFML/Graphics.hpp>
class nWindow;

class Drawable
{
public:
	Drawable();
	virtual void m_draw(nWindow& window) = 0;
	sf::Vector2f m_getLocation();
protected:
	sf::Vector2f m_location;
	bool willDraw;


};
