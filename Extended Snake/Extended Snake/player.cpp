#include "pch.h"
#include "player.h"


player::player()
{
	this->playerSpeed = 400;
	this->texture.loadFromFile("C:\\Users\\johnm\\Desktop\VisualStudioRepo\\Extended-Snake\\Extended Snake\\Extended Snake\\images\\bob.png");
	this->playerPosition.x = 500;
	this->playerPosition.y = 800;
}

sf::Sprite player::getSprite() {
	return this->playerSprite;
}
player::~player()
{
}
void player::moveLeft()
{
	this->playerLeft = true;
}

void player::moveRight()
{
	this->playerRight = true;
}

void player::stopLeft()
{
	this->playerLeft = false;
}

void player::stopRight()
{
	this->playerRight = false;
}

void player::update(float elapsedTime)
{
	if (playerRight)
	{
		playerPosition.x += playerSpeed * elapsedTime;
	}

	if (playerLeft)
	{
		playerPosition.x -= playerSpeed * elapsedTime;
	}

	// Now move the sprite to its new position
	this->playerSprite.setPosition(playerPosition);

}