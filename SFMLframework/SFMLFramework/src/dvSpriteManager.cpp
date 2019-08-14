#include "dvSpriteManager.h"



dvSpriteManager::dvSpriteManager()
{
}


dvSpriteManager::~dvSpriteManager()
{
}

void dvSpriteManager::AddSprite(std::string filePath, int positionX, int positionY, int width, int height)
{
	dvSprite* newSprite = new dvSprite(filePath, positionX, positionY, width, height);
	m_Sprites.push_back(newSprite);
}

void dvSpriteManager::Update()
{
	for (auto sprite : m_Sprites)
	{
		sprite->Update();
	}
}

void dvSpriteManager::Render(sf::RenderWindow* renderWindow)
{
	for (auto sprite : m_Sprites)
	{
		sprite->Render(renderWindow);
	}
}