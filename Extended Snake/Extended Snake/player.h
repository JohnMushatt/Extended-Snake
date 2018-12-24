#pragma once
#include "SFML/Graphics.hpp"
class player
{
private:
	sf::Vector2f playerPosition;
	sf::Sprite playerSprite;

	sf::Texture texture;
	bool playerLeft;
	bool playerRight;
	float playerSpeed;
public:
	player();

	sf::Sprite getSprite();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(float elapastedTime);
	virtual ~player();
};

