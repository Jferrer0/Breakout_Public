#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "dvComponent.h" //Incluyo el componente para conocerlo en el dvGameObject y poderlo usar.

class dvGameObject
{
public:
	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* renderWindow);
	void Destroy();

	void AddComponent(dvComponent* component);

private:
	std::vector<dvComponent*> m_Components;
	std::string m_Name;

};