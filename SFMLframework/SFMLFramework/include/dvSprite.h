#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class dvSprite
{
public:
	dvSprite(std::string filePath, int positionX, int positionY, int width, int height);
	~dvSprite();
	void loadTexture();
	void Update();
	void Render(sf::RenderWindow* renderWindow);

private:
	sf::Texture m_Texture;
	std::string m_TexturePath;
	int m_TextureX;
	int m_TextureY;
	int m_TextureW;
	int m_TextureH;

	sf::Sprite m_Sprite;
	int m_SpriteX;
	int m_SpriteY;
	int m_SpriteW;
	int m_SpriteH;
};

