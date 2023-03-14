#pragma once
#include <SFML/Graphics.hpp>

class MonteCarloPi
{
public:
	MonteCarloPi();
	void Update();
	void Render(sf::RenderWindow& window);

private:
	sf::RectangleShape m_rectangle;
	sf::CircleShape m_circle;
};
