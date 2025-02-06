#include "Level.h"
#include "Player.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	window->setMouseCursorVisible(false);

	mario_.loadFromFile("gfx/mario.png");
	mushroom_.loadFromFile("gfx/Mushroom.png");
	mushroomTrans_.loadFromFile("gfx/MushroomTrans.png");
	cursorTexture_.loadFromFile("gfx/cursor.png");

	player_ = createPlayer();
	auto enemy1 = createEnemy(sf::Vector2f(50, 50), mushroomTrans_);
	auto enemy2 = createEnemy(sf::Vector2f(100, 100), mushroom_);

	enemies_.push_back(enemy1);
	enemies_.push_back(enemy2);


	background_ = createBackground({ 11038, 675});
	camera_ = createCamera();
	cursor_ = createCursor();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	camera_->handleInput(dt);
	player_->handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

}

// Update game objects
void Level::update(float dt)
{
	cursor_->update(dt);
	player_->update(dt);
	camera_->update(dt);

	for (auto& enemy : enemies_)
		enemy->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(*background_);

	for (auto& enemy : enemies_)
		window->draw(*enemy);

	window->draw(*player_);

	window->draw(*cursor_);

	endDraw();
}

Player* Level::createPlayer()
{
	Player* player = new Player();

	player->setTexture(&mario_);
	player->setSize(sf::Vector2f(100, 100));
	player->setPosition(100, 100);
	player->setInput(input);

	return player;
}

Enemy* Level::createEnemy(sf::Vector2f position, sf::Texture& texture)
{
	Enemy* enemy = new Enemy();
	
	enemy->setTexture(&texture);
	enemy->setSize(sf::Vector2f(50, 50));
	enemy->setPosition(position);
	enemy->setWindow(window);

	return enemy;
}

Background* Level::createBackground(sf::Vector2f size)
{
	Background* background = new Background();
	background->setSize(size);
	background->setFillColor(sf::Color::Green);

	return background;
}

Camera* Level::createCamera()
{
	Camera* camera = new Camera(window->getView());
	camera->setInput(input);
	camera->setWindow(window);

	return camera;
}

Cursor* Level::createCursor()
{
	Cursor* cursor = new Cursor();
	cursor->setSize(sf::Vector2f(15, 15));
	cursor->setTexture(&cursorTexture_);
	cursor->setInput(input);
	
	return cursor;
}
