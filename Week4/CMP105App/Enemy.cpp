#include "Enemy.h"

void Enemy::update(float deltaTime)
{
	sf::Vector2f position = getPosition();

	float speed = 5 * deltaTime;
	position += enemyDirection_ * speed;

	float radius = getSize().x / 2;

	if (position.y + 2 * radius > window->getSize().y || position.y < 0) {
		enemyDirection_.y *= -1;
	}

	if (position.x + 2 * radius > window->getSize().x || position.x < 0) {
		enemyDirection_.x *= -1;
	}


	position.x = std::min(position.x, window->getSize().x - radius);
	position.y = std::min(position.y, window->getSize().y - radius);

	position.x = std::max(position.x, 0.0f);
	position.y = std::max(position.y, 0.0f);

	setPosition(position);
}
