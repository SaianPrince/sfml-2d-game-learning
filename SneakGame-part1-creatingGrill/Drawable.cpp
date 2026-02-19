#include "Drawable.h"

Drawable::Drawable()
{
	willDraw = true;
}

sf::Vector2f Drawable::m_getLocation()
{
	return m_location;
}
