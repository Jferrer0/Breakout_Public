#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

///La base de los componentes, de aquí heredaran sus componentes.
class dvComponent
{
public:
	//Inicializa lo que debe para funcionar.
	virtual void Init() = 0;
	//Actualiza lo que tiene que actualizar en ese frame.
	virtual void Update(float deltaTime) = 0;
	//Dibuja lo que pueda dibujar en ese frame.
	virtual void Render(sf::RenderWindow* window) = 0;
	//Limpia todo lo que creo, para que no se quede basura.
	virtual void Destroy();

private:

};