#pragma once
#include "Drawable.h"

class Grill:public Drawable
{
public:
	Grill();
	void set(float width, float length);
	void m_draw(nWindow& window) override;

private:
	float m_width;
	float m_length;
	int m_numberOfLines;
	sf::RectangleShape m_horizontal;
	sf::RectangleShape m_vertical;
};
