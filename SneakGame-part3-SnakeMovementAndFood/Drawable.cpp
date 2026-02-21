#include "Drawable.h"

Drawable::Drawable()
{
	willDraw = true;
}

sf::Vector2f Drawable::m_getLocation()
{
	return m_location;
}

void Drawable::m_setLocation(const sf::Vector2f& location)
{
	m_location = location;
}
