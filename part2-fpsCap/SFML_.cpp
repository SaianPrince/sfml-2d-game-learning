#include <SFML/Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Merhaba0"); //create window
	sf::CircleShape circle(100, 40); //create a circle
	sf::RectangleShape rectangle(sf::Vector2f(200, 200)); //create a rectangle
	sf::Vector2f move(10, 10); // create a vector named "move"
	sf::Clock clock; // create a clock

	circle.setFillColor(sf::Color::Yellow); // the circle was painted yellow
	circle.setOutlineThickness(3.0f); // outline thickness of the circle was changed to 3.0f
	circle.setOutlineColor(sf::Color::Red); // outline of the circle was painted red

	rectangle.setPosition(move); // the position of the rectangle was set

	float frameTime = 1 / 144.0f; // time per frame
	while (window.isOpen())  // while window is open
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) { // window will close when X is clicked
				window.close();
			}

		}
		float elapsedTime = clock.getElapsedTime().asSeconds(); // elapsed time is defined
		if (elapsedTime >= frameTime) {
			window.clear();

			circle.setPosition(move); // the position of the circle was set
			window.draw(circle); // a circle was drawn
			window.draw(rectangle);
			window.display();
			move.x += 100 * elapsedTime; // the move vector's x-axis was increased
			int fps = 1.0f / elapsedTime; // frames per second is defined 
			window.setTitle(std::to_string(fps)); // the title of the window was set
			clock.restart(); // the clock was reset
		}
		else
		{
			sf::sleep(sf::seconds(frameTime - elapsedTime)); // downtime
		}
	}

}
