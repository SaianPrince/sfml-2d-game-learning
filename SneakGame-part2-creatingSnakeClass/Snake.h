#pragma once
#include "Cell.h"

class Snake : public Drawable
{
public:
	Snake();
	void m_draw(nWindow &window) override;
	void addTail();
	void snakeMove();
	void m_setDirection(cellDirection newDirection);

private:
	std::vector<Cell> s_cells;


};
