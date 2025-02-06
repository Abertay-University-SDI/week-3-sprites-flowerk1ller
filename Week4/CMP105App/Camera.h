#pragma once
#include "Framework/GameObject.h"
#include <SFML/Graphics/View.hpp>

class Camera : public GameObject {

public:
	Camera(sf::View view);
	void update(float dt) override;
	void handleInput(float dt) override;

private:
	sf::View view_;

	float horizontal_ = 0;
	float vertical_ = 0;
};