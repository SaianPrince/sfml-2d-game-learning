#include "Snake.h"

Snake::Snake()
{
	addTail();
	addTail();
	addTail();
	addTail();
}

void Snake::m_draw(nWindow& window)
{
	for (auto& next : s_cells)
	{
		next.m_draw(window);
	}
}

void Snake::addTail()
{
	if (s_cells.size())
	{
		Cell newCell = s_cells.back().createCell();
		s_cells.push_back(newCell);
	}
	else
	{
		s_cells.push_back(Cell());
	}
}

void Snake::snakeMove()
{
	for (auto& next : s_cells)
	{
		next.m_move();
	}
}


void Snake::m_setDirection(cellDirection newDirection)
{
	for(auto& next: s_cells)
		next.m_setDirection(newDirection);
}	
