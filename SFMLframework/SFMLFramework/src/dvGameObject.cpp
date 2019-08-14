#pragma once
#include "dvGameObject.h"
#include "dvComponent.h"

void dvGameObject::Init(std::string name)
{
	m_Name = name;
}

void dvGameObject::Update(float deltaTime)
{
	//Update all the components
	for (auto component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void dvGameObject::Render(sf::RenderWindow* renderWindow)
{
	//Render all the components
	for (auto component : m_Components)
	{
		component->Render(renderWindow);
	}
}

void dvGameObject::Destroy()
{
	//Destroy all the components
	for (auto component : m_Components)
	{
		component->Destroy();
		delete component;
	}
}

void dvGameObject::AddComponent(dvComponent * component)
{
	m_Components.push_back(component);
}
