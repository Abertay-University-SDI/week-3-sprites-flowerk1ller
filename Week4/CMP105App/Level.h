#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Player.h"
#include <string.h>
#include <iostream>
#include "Enemy.h"
#include "Background.h"
#include "Camera.h"
#include "Cursor.h"


class Level : BaseLevel {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

	Player* createPlayer();

	Enemy* createEnemy(sf::Vector2f position, sf::Texture& texture);

	Background* createBackground(sf::Vector2f size);

	Camera* createCamera();

	Cursor* createCursor();

private:
	sf::Texture mushroom_;
	sf::Texture mushroomTrans_;
	sf::Texture mario_;
	sf::Texture cursorTexture_;

	Background* background_;

	Player* player_;

	sf::View* view_;

	Camera* camera_;
	Cursor* cursor_;

	std::vector<Enemy*> enemies_;

};