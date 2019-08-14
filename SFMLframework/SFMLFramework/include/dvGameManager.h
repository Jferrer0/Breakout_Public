#pragma once
#include "SFML/Graphics.hpp" //Esto es una inclusión, es lo mismo que el import en python, es decirle que quieres conocer en este archivo, todo lo que está en ese otro archivo.

#include <vector>
#include <iostream>
#include "dvGameObject.h"
#include "dvSpriteManager.h"

class dvGameManager
{
public:
	static dvGameManager& Instance(); //Con esta función estatica pueden acceder al dvGameManager desde cualquier lado, haciendo "dvGameManager::Instance" Necesitan tener el "dvGameManager.h" incluido.

	void InitGame(int screenWidth, int screenHeight);
	void RunGame();
	
	void UpdateGame();
	void DrawGame();
	void HandleGameEvents();

	dvGameObject* CreateGameObject(std::string name);
	void DeleteGameObject(std::string name);

	//Aquí debe existir el objeto de la clase del sistema en el que están trabajando.
	//AudioManager Audio;
	//SpriteManager Sprites;
	dvSpriteManager m_Sprites;
	//FontManager Fonts;

private:
	void CleanObjects();

	sf::RenderWindow m_Window;

	std::map<std::string, dvGameObject*> m_GameObjectsMap;
	std::vector<std::string> m_ObjectsToRemove;

	sf::Clock m_Time;
};