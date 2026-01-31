#include <SFML/Graphics.hpp>

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(600, 600), "Merhaba0"); //create window
	sf::CircleShape circle(100,40); //create a circle
	sf::RectangleShape rectangle(sf::Vector2f(200, 200)); //create a rectangle
	sf::Vector2f move(10, 10); // create a vector named "move"
	sf::Vector2f move2(150, 100); // create a vector named "move2"

	circle.setFillColor(sf::Color::Yellow); // the circle was painted yellow
	circle.setOutlineThickness(3.0f); // outline thickness of the circle was changed to 3.0f
	circle.setOutlineColor(sf::Color::Red); // outline of the circle was painted red
	rectangle.setFillColor(sf::Color::Red); // the rectangle was painted red
	rectangle.setOutlineThickness(4.0f); // outline thickness of the rectangle was changed to 4.0f
	rectangle.setOutlineColor(sf::Color::Blue); // outline of the rectangle was painted blue

	while (window.isOpen())  // while window is open
	{
		sf::Event event; // event is defined
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{ // window will close when X is clicked
				window.close();
			}
		}
			window.clear();

			rectangle.setPosition(move2); // the position of the rectangle was set
			circle.setPosition(move); // the position of the circle was set
			window.draw(circle); // a circle was drawn
			window.draw(rectangle);
			move.x += 0.1f; // the move vector's x-axis was increased
			move2.x-= 0.1f; // the move2 vector's x-axis was decrased

			move.y += 0.1f; // the move vector's y-axis was increased
			move2.y -= 0.1f; // the move2 vector's y-axis was decrased

			window.display();
			
	}
	
}