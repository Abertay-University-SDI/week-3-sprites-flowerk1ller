#pragma once
#include "Framework/GameObject.h"

class Player : public GameObject
{
public:
	Player();
	void handleInput(float deltaTime) override;
	void update(float deltaTime) override;


private:
	float horizontal_;
	float vertical_;

};

