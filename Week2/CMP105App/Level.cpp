#include "Level.h"
#include <cmath>

sf::Vector2f startOfDragPos= sf::Vector2f(0, 0);
sf::Vector2f endOfDragPos= sf::Vector2f(0, 0);
bool dragging = false;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	if (!posFont.loadFromFile("arial.ttf"))
	{
		std::cout << "Couldnt find font\n";
	}
	
	// initialise game objects
	posText.setFont(posFont);
	posText.setCharacterSize(25);
	posText.setFillColor(sf::Color::Red);
	posText.setPosition(sf::Vector2f(0, 0));

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		std::cout << "W is being pressed\n";
		input->setKeyUp(sf::Keyboard::W);
	}
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		std::cout << "You are pressing J,K And L\n";
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	if (input->isMouseLDown() && !dragging)
	{
		dragging = true;
		startOfDragPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
	}
	else if (!input->isMouseLDown() && dragging)
	{
		dragging = false;
		endOfDragPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		int diffInX = startOfDragPos.x - endOfDragPos.x;
		int diffInY = startOfDragPos.y - endOfDragPos.y;
		double difference = sqrt((diffInX * diffInX) + (diffInY * diffInY));
		std::cout << "The mouse drag distance was " << difference << std::endl;
	}
}

// Update game objects
void Level::update()
{
	stringToDisplayPos = std::string("Mouse's X: ") + std::to_string(input->getMouseX()) + std::string(" Mouse's Y: ") + std::to_string(input->getMouseY());
	posText.setString(stringToDisplayPos);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(posText);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}