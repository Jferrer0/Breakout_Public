#include "dvSprite.h"



dvSprite::dvSprite(std::string filePath, int positionX, int positionY, int width, int height)
	:m_TexturePath(filePath), m_TextureX(positionX), m_TextureY(positionY), m_TextureW(width), m_TextureH(height)
{
	loadTexture();
	m_Sprite.setTexture(m_Texture);
}


dvSprite::~dvSprite()
{
}

void dvSprite::Update()
{
	
}

void dvSprite::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(m_Sprite);
}

void dvSprite::loadTexture()
{
	if (!m_Texture.loadFromFile(m_TexturePath, sf::IntRect(m_TextureX,m_TextureY,m_TextureW,m_TextureH)))
	{
		std::cout << "Error loading texture file" << std::endl;
	}
}

