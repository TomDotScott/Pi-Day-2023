#include "MonteCarloPi.h"

#include "Constants.h"

MonteCarloPi::MonteCarloPi()
{
	// Set up rectangle
	m_rectangle.setFillColor(sf::Color::Red);
	m_rectangle.setSize(sf::Vector2f(constants::WINDOW_SIZE, constants::WINDOW_SIZE));
	m_rectangle.setPosition(0.f, 0.f);


	// Set up circle
	m_circle.setFillColor(sf::Color::Blue);
	m_circle.setRadius(static_cast<float>(constants::WINDOW_SIZE) / 2);
	m_circle.setPosition(0.f, 0.f);
}

void MonteCarloPi::Update()
{

}

void MonteCarloPi::Render(sf::RenderWindow& window)
{
	window.draw(m_rectangle);
	window.draw(m_circle);
}
