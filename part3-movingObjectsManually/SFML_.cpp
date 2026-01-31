#include <SFML/Graphics.hpp>


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
	sf::Clock clock; // create a clock

	

	circle.setFillColor(sf::Color::Yellow); // the circle was painted yellow
	circle.setOutlineThickness(3.0f); // outline thickness of the circle was changed to 3.0f
	circle.setOutlineColor(sf::Color::Red); // outline of the circle was painted red

	directions direction = directions::RIGHT;

	float frameTime = 1 / 144.0f; // time per frame
	while (window.isOpen())  // while window is open
	{
		sf::Event event;
		while (window.pollEvent(event)) {
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

		}
		float elapsedTime = clock.getElapsedTime().asSeconds(); // elapsed time is defined
		if (elapsedTime >= frameTime) {
			window.clear();
			
			movement(direction, move);
			circle.setPosition(move); // the position of the circle was set
			window.draw(circle); // a circle was drawn

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
