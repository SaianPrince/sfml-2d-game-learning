#include "Grill.h"
#include "nWindow.h"
Grill::Grill()
{
	set(100, 10);
	m_horizontal.setFillColor(sf::Color::Green);
	m_vertical.setFillColor(sf::Color::Green);


}

void Grill::set(float width, float length)
{
	m_length = length;
	m_width = width;
	m_numberOfLines = width / length;

	m_vertical.setSize(sf::Vector2f(1.0f, m_width));
	m_horizontal.setSize(sf::Vector2f(m_width, 1.0f));

}

void Grill::m_draw(nWindow& window)
{
	sf::Vector2f location;
	for(int i = 0; i<= m_numberOfLines; i++)
	{
		location.x = 0.0f;
		location.y = i * m_length;
		m_horizontal.setPosition(location);
		window.nDraw(m_horizontal);
	
		location.y = 0.0f;
		location.x = i * m_length;
		m_vertical.setPosition(location);
		window.nDraw(m_vertical);
	}

	
}



