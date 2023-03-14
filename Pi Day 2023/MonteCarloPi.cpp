#include "MonteCarloPi.h"

#include "Constants.h"

MonteCarloPi::MonteCarloPi() :
	m_rectangle(sf::Vector2f(constants::WINDOW_SIZE, constants::WINDOW_SIZE)),
	m_circle(static_cast<float>(constants::WINDOW_SIZE) / 2.f, 80),
	m_numPointsInsideCircle(0),
	m_numPointsOutsideCircle(0)
{
	// Set up rectangle
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setPosition(0.f, 0.f);


	// Set up circle
	m_circle.setFillColor(sf::Color::Blue);
	m_circle.setPosition(0.f, 0.f);
}

void MonteCarloPi::Update()
{
	const sf::Vector2f randomPoint{
		static_cast<float>(RandomNumber(0, constants::WINDOW_SIZE)),
		static_cast<float>(RandomNumber(0, constants::WINDOW_SIZE))
	};

	m_points.emplace_back(randomPoint);

	constexpr float circleRadius = static_cast<float>(constants::WINDOW_SIZE) / 2.f;

	// Get the centre of the circle
	const sf::Vector2f circleCentre{
		m_circle.getPosition().x + circleRadius,
		m_circle.getPosition().y + circleRadius
	};

	const sf::Vector2f distance = circleCentre - randomPoint;
	if (distance.x * distance.x + distance.y * distance.y < circleRadius)
	{
		m_numPointsInsideCircle++;
	}
	else
	{
		m_numPointsOutsideCircle++;
	}
}

void MonteCarloPi::Render(sf::RenderWindow& window) const
{
	window.draw(m_rectangle);
	window.draw(m_circle);

	for (const auto& point : m_points)
	{
		sf::CircleShape pointCircle{ static_cast<float>(constants::POINT_SIZE) / 2, 10 };
		pointCircle.setFillColor(sf::Color::White);
		pointCircle.setPosition(point);

		window.draw(pointCircle);
	}
}

int MonteCarloPi::RandomNumber(const int min, const int max)
{
	static bool first = true;
	if (first)
	{
		srand(time(nullptr));
		first = false;
	}

	const int range = max - min + 1;
	return rand() % range + min;
}
