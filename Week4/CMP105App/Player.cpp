#include "Player.h"

Player::Player()
{
}

void Player::handleInput(float  dt)
{
	horizontal_ = input->isKeyDown(sf::Keyboard::D) - input->isKeyDown(sf::Keyboard::A);
	vertical_ = input->isKeyDown(sf::Keyboard::S) - input->isKeyDown(sf::Keyboard::W);
}

void Player::update(float deltaTime)
{

	sf::Vector2f direction = sf::Vector2f(horizontal_, vertical_) * (deltaTime * 100);
	setPosition(getPosition() + direction);
}


