#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();
	sf::Text posText;
	sf::Font posFont;
	std::string stringToDisplayPos;
	sf::CircleShape circle;
	sf::Vector2f circlePos;
private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;



	// Add your object here

};