#pragma once
#include "dvGameManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

dvGameManager & dvGameManager::Instance()
{
	static dvGameManager instance;
	return instance;
}

void dvGameManager::InitGame(int screenWidth, int screenHeight)
{
	m_Window.create(sf::VideoMode(screenWidth, screenHeight), "SFML Framework");

	m_Time.restart();

	RunGame();
}

void dvGameManager::RunGame()
{
	m_Sprites.AddSprite("imagen.jpg", 0, 0, 300, 250);
	while (m_Window.isOpen())
	{
		HandleGameEvents();
		UpdateGame();
		DrawGame();
	}
}

void dvGameManager::UpdateGame()
{
	//Todo lo que tengan que actualizar del juego va en esta función.
	m_Sprites.Update();

	//Calcular el tiempo desde el cuadro anterior.
	float deltaTime = m_Time.getElapsedTime().asMilliseconds() / 1000.0f;

	for (auto obj : m_GameObjectsMap)
	{
		obj.second->Update(deltaTime);
	}

	//Resetear el timer, para ver cuando tiempo pasa hasta que se vuelva a llamar esta función.
	m_Time.restart();

	if (Keyboard::isKeyPressed(Keyboard::A)) //Así pueden saber si algo está presionado o no. Te regresa cierto o falso.
	{
		std::cout << "Key A Pressed" << std::endl;
	}
}

void dvGameManager::DrawGame()
{
	m_Window.clear();

	//Todo el dibujado va entre estas dos lineas.

	for (auto obj : m_GameObjectsMap)
	{
		obj.second->Render(&m_Window);
	}

	m_Sprites.Render(&m_Window);

	m_Window.display();
}

void dvGameManager::HandleGameEvents()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::EventType::Closed:
			m_Window.close();
			break;
		}
	}
}

dvGameObject * dvGameManager::CreateGameObject(std::string name)
{
	dvGameObject* newObject = new dvGameObject(); //Crearlo en memoria dinamica.
	newObject->Init(name);//Inicializarlo.

	//Agregarlo al mapa de objetos.
	m_GameObjectsMap.insert(std::pair<std::string, dvGameObject*>(name, newObject));

	//Regresar el puntero al objeto para poder usarlo si quieren.
	return newObject;
}

void dvGameManager::DeleteGameObject(std::string name)
{
	m_ObjectsToRemove.push_back(name); //Agregar el nombre a los objetos que se eliminaran al final del frame. Despues de que todos se hayan actualizado.

	return;
}

void dvGameManager::CleanObjects()
{
	for (auto objNames : m_ObjectsToRemove)
	{
		m_GameObjectsMap[objNames]->Destroy(); //Decirle al gameobject que se destruya y todo lo que tiene adentro.
		delete m_GameObjectsMap[objNames]; //Borrarlo de la memoria.
		m_GameObjectsMap.erase(objNames); //Quitarlo del mapa de objetos.
	}
}
