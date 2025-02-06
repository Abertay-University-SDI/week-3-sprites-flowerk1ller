#pragma once
#include "Framework/GameObject.h"
class Cursor : public GameObject
{
public:
	void update(float dt) override;
	void handleInput(float dt);
};

