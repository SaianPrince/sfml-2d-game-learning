#pragma once
#include "Cell.h"

class Snake : public Drawable
{
public:
	Snake();
	void set(float m_cellSize, float m_width, float m_length);
	void m_draw(nWindow &window) override;
	void addTail();
	void snakeMove();
	void m_setDirection(cellDirection newDirection);
	void checkFood();
private:
	std::vector<Cell>	s_cells;
	float				m_cellSize;
	float				m_width;
	float				m_length;
	float				m_distance;
	void				refreshFood();
	Cell				m_food;
	cellDirection		m_newDirection;
		

};
