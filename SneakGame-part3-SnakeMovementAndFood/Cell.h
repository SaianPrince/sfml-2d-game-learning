#pragma once
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "nWindow.h"

enum class cellDirection 
{
	Up,
	Down,
	Right,
	Left,
};

class Cell : public Drawable 
{
public:
	Cell();
	Cell	createCell();
	void	m_draw(nWindow& window) override;
	void	m_setDirection(cellDirection direction);
	cellDirection	const m_getDirection();
	void	m_setSize(float size);
	float	const m_getSize();
	void	m_setSpeed(float speed);
	float	const m_getSpeed();
	void	m_setColor(sf::Color color);
	void	m_setOutlineColor(sf::Color color);
	void m_move();

protected:
	sf::Color		   m_outlineColor;
	sf::Color		   m_color;
	cellDirection	   m_direction;
	sf::RectangleShape m_rectangle;
	float			   m_size;
	float			   m_speed;
};
