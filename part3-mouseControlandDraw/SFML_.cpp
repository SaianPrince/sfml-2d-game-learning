#include <SFML/Graphics.hpp>
#include <iostream>

enum class directions {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

void movement(directions d, sf::Vector2f& move) {
	switch (d) {
		case directions::UP:
			move.y -= 5;
			break;
		case directions::DOWN:
			move.y += 5;
			break;
		case directions::LEFT:
			move.x -= 5;
			break;
		case directions::RIGHT:
			move.x += 5;
			break;
		default:
			break;
	}
}
int main()
{

	sf::RenderWindow window(sf::VideoMode(600, 600), "Merhaba0"); //create window
	sf::CircleShape circle(100, 40); //create a circle
	sf::Vector2f move(10, 10); // create a vector named "move"
	sf::Vector2f first;
	sf::Vector2f last;
	sf::Clock clock; // create a clock
	sf::RectangleShape rectangle;

	

	circle.setFillColor(sf::Color::Yellow); // the circle was painted yellow
	circle.setOutlineThickness(3.0f); // outline thickness of the circle was changed to 3.0f
	circle.setOutlineColor(sf::Color::Red); // outline of the circle was painted red

	directions direction = directions::RIGHT;
	
	

	float frameTime = 1 / 60.0f; // time per frame
	while (window.isOpen())  // while window is open
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			bool isDrawDone = false;

			if (event.type == sf::Event::Closed) { // window will close when X is clicked
				window.close();
			}
			if(event.type == sf::Event::KeyPressed) // keyboard control
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // the circle will go to left when pressed left button
				{
					direction = directions::LEFT;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // the circle will go to right when pressed right button
				{
					direction = directions::RIGHT;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // the circle will go to up when pressed up button
				{
					direction = directions::UP;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // the circle will go to down when pressed down button
				{
					direction = directions::DOWN;
				}
				
			}
			if (event.type == sf::Event::MouseButtonPressed) 
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					isDrawDone = false;
					first = sf::Vector2f(event.mouseButton.x, event.mouseButton.y); // its location when the left mouse button is pressed
					rectangle.setPosition(first);
				}
				
			}
			if (event.type == sf::Event::MouseButtonReleased) 
			{
				if (event.mouseButton.button == sf::Mouse::Left) 
				{
					isDrawDone = true;

				}
			}
			if (event.type == sf::Event::MouseMoved) 
			{
				if(!isDrawDone && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					last = sf::Vector2f(event.mouseMove.x, event.mouseMove.y); // its location when the left mouse button is released
					float width = last.x - first.x; // its the rectangle was drawn when time between the left mouse button pressed and released
					float length = last.y - first.y;
					rectangle.setSize(sf::Vector2f(width, length)); // width and length of the rectangle
				}
			}
			
		
		}
		float elapsedTime = clock.getElapsedTime().asSeconds(); // elapsed time is defined
		if (elapsedTime >= frameTime) {
			window.clear();
			
			movement(direction, move);
			circle.setPosition(move); // the position of the circle was set
			window.draw(circle); // a circle was drawn
			window.draw(rectangle); // a rectangle was drawn

			window.display();
			

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
