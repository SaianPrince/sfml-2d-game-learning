#include "Snake.h"
#include "Cell.h"
#include <random>




Snake::Snake()
{
	srand(time(NULL));
	m_distance = 0.0f;
	m_newDirection = cellDirection::Right;
	
	
}

void Snake::set(float m_cellSize, float m_width, float m_length)
{
	this->m_cellSize = m_cellSize;
	this->m_width = m_width;
	this->m_length = m_length;
	refreshFood();

	addTail();
	addTail();
	addTail();
	addTail();
}

void Snake::m_draw(nWindow& window)
{
	m_food.m_draw(window);
	for (auto& next : s_cells)
	{
		next.m_draw(window);
	}
}

void Snake::addTail()
{
	Cell newCell;
	if (s_cells.size())
	{
		newCell = s_cells.back().createCell();
	}
	newCell.m_setSize(m_cellSize);

	s_cells.push_back(newCell);

}

void Snake::snakeMove()
{
	if (!isInInside())
		return;

		for (auto& next : s_cells)
		{
			next.m_move();
		}
		m_distance += s_cells[0].m_getSpeed();
		if (m_distance == s_cells[0].m_getSize())
		{
			checkFood();
			for (int i = s_cells.size() - 1; i > 0; i--)
			{
				s_cells[i].m_setDirection(s_cells[i - 1].m_getDirection());

			}
			s_cells[0].m_setDirection(m_newDirection);
			m_distance = 0.0f;
		
	}

}

void Snake::m_setDirection(cellDirection newDirection)
{
	if (m_newDirection == cellDirection::Right && newDirection == cellDirection::Left) return;
	if (m_newDirection == cellDirection::Left && newDirection == cellDirection::Right) return;
	if (m_newDirection == cellDirection::Up && newDirection == cellDirection::Down)	 return;
	if (m_newDirection == cellDirection::Down && newDirection == cellDirection::Up)	 return;
	m_newDirection = newDirection;
		
}
void Snake::checkFood()
{
	if(s_cells[0].m_getLocation() == m_food.m_getLocation())
	{
		addTail();
		refreshFood();

		bool onsnake;
		do 
		{
			onsnake = false;
			for (auto& next : s_cells)
			{
				if (next.m_getLocation() == m_food.m_getLocation())
				{
					refreshFood();
					onsnake = true;
					break;
				}

			}
		} while (onsnake);
	}
		
}
bool Snake::isInInside()
{
	if(s_cells[0].m_getLocation().x < 0 || 
	   s_cells[0].m_getLocation().x+ m_cellSize > m_width ||
	   s_cells[0].m_getLocation().y < 0 ||
	   s_cells[0].m_getLocation().y + m_cellSize > m_length)
	{
		return false;
	}

	else
	return true;
}
void Snake::refreshFood()
{
	int columns = m_width / m_cellSize;
	int rows = m_length / m_cellSize;
	float x = (rand()%columns) * m_cellSize;
	float y = (rand() % rows) * m_cellSize;
	m_food.m_setLocation(sf::Vector2f(x,y));
	m_food.m_setSize(m_cellSize);
	m_food.m_setColor(sf::Color::Black);
	m_food.m_setOutlineColor(sf::Color::Red);
}
