#pragma once
#include "Framework/GameObject.h"
#include <iostream>

class Enemy : public GameObject
{
public:
	void update(float deltaTime) override;

private:
	sf::Vector2f enemyDirection_ = sf::Vector2f(23, 23);

};

