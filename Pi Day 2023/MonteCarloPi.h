#pragma once
#include <SFML/Graphics.hpp>

class MonteCarloPi
{
public:
	MonteCarloPi();
	void Update();
	void Render(sf::RenderWindow& window) const;

private:
	sf::RectangleShape m_rectangle;
	sf::CircleShape m_circle;

	std::vector<sf::Vector2f> m_points;
	int m_numPointsInsideCircle;
	int m_totalPoints;

	static int RandomNumber(int min, int max);
};
