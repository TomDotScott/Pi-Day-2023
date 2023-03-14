#include <SFML/Window.hpp>

#include "Constants.h"


int main()
{
	sf::Window window(sf::VideoMode(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT), "Pi Day 2023");

	window.setFramerateLimit(constants::FPS);

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
	}

	return 0;
}

