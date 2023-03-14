#include <SFML/Window.hpp>

#include "Constants.h"
#include "MonteCarloPi.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(constants::WINDOW_SIZE, constants::WINDOW_SIZE), "Pi Day 2023");

	window.setFramerateLimit(constants::FPS);

	MonteCarloPi piEstimator;

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		piEstimator.Update();

		window.clear(sf::Color::Black);
		piEstimator.Render(window);
		window.display();
	}

	return 0;
}

