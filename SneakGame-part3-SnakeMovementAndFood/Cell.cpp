#include "Cell.h"
#include "nWindow.h"
#include "Snake.h"

Cell::Cell()
{
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setOutlineColor(sf::Color::Black);
	m_rectangle.setOutlineThickness(1);
	m_setSpeed(2);
	m_setDirection(cellDirection::Right);

}

Cell Cell::createCell()
{
	sf::Vector2f newLocation = m_location;
	switch (m_direction)
	{
	case(cellDirection::Up):
		newLocation.y += m_size;
		break;
	case(cellDirection::Down):
		newLocation.y -= m_size;
		break;
	case(cellDirection::Left):
		newLocation.x += m_size;
		break;
	case(cellDirection::Right):
		newLocation.x -= m_size;
		break;

	}
	Cell newCell;
	newCell.m_setDirection(m_direction);
	newCell.m_setLocation(newLocation);
	return newCell;
}

void Cell::m_draw(nWindow& window) 
{
	m_rectangle.setPosition(m_location);
	window.nDraw(m_rectangle);

}

void Cell::m_setDirection(cellDirection direction)
{
	
	m_direction = direction;
}

cellDirection const  Cell::m_getDirection()
{
	return m_direction;
}

void Cell::m_setSize(float size)
{
	m_size = size;
	m_rectangle.setSize(sf::Vector2f(m_size, m_size));
}

float const Cell::m_getSize()
{
	return m_size;
}

void Cell::m_setSpeed(float speed)
{
	m_speed = speed;
}

float const Cell::m_getSpeed()
{
	return m_speed;
}

void Cell::m_setColor(sf::Color color)
{
	m_color = color;
	m_rectangle.setFillColor(m_color);
}

void Cell::m_setOutlineColor(sf::Color color)
{
	m_outlineColor = color;
	m_rectangle.setOutlineColor(m_outlineColor);
}

void Cell::m_move()
{
	switch(m_direction)
	{
	case(cellDirection::Up):
		m_location.y -= m_speed;
			break;
	case(cellDirection::Down):
		m_location.y += m_speed;
			break;
	case(cellDirection::Left):
		m_location.x -= m_speed;
			break;
	case(cellDirection::Right):
		m_location.x += m_speed;
			break;

	}
}
