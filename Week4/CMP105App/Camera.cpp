#include "Camera.h"
#include <iostream>

Camera::Camera(sf::View view)
{
	view_ = view;
	view_.zoom(1 / 1.5f);

	std::cout << view.getCenter().x - view.getSize().x / 2;
}

void Camera::update(float dt)
{
	float speed = dt * 150;
	view_.move(sf::Vector2f(horizontal_, vertical_) * speed);

	sf::Vector2f windowSize = sf::Vector2f(11038, 675);

	sf::Vector2f center = view_.getCenter();
	sf::Vector2f viewSize = view_.getSize();

	
	float dx = 0;
	float dy = 0;

	if (center.x - viewSize.x / 2.0 <= 0) {
		dx = -(center.x - viewSize.x / 2.0);
	}
	else if (center.x + viewSize.x / 2.0 > 11038) {
		dx = 11038 - (center.x + viewSize.x / 2.0);
	}

	if (center.y - viewSize.y / 2.0 <= 0) {
		dy = -(center.y - viewSize.y / 2.0);
	}

	if (center.y + viewSize.y / 2.0 > 675) {
		dy = 675 - (center.y + viewSize.y / 2.0);
	}


	view_.move(sf::Vector2f(dx, dy));
	window->setView(view_);
}


void Camera::handleInput(float dt)
{
	horizontal_ = input->isKeyDown(sf::Keyboard::Right) - input->isKeyDown(sf::Keyboard::Left);
	vertical_ = input->isKeyDown(sf::Keyboard::Down) - input->isKeyDown(sf::Keyboard::Up);
}

