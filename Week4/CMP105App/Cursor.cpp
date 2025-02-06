#include "Cursor.h"

void Cursor::update(float dt)
{
	sf::Vector2f position = sf::Vector2f(input->getMouseX(), input->getMouseY());
	setPosition(position);
}

void Cursor::handleInput(float dt)
{
}
