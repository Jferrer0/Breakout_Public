#pragma once
#include <vector>
#include "dvSprite.h"

class dvSpriteManager
{
public:
	dvSpriteManager();
	~dvSpriteManager();
	void AddSprite(std::string filePath, int positionX, int positionY, int width, int height);
	void Update();
	void Render(sf::RenderWindow* renderWindow);
	
private:
	std::vector<dvSprite*> m_Sprites;
};

