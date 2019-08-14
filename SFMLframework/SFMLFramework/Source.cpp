// SFMLFramework.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	// Declare and create a new render-window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	// Limit the framerate to 60 frames per second (this step is optional)
	window.setFramerateLimit(60);

	sf::RectangleShape leftBorder(sf::Vector2f(15, 600));
	sf::FloatRect leftBound = leftBorder.getGlobalBounds();

	sf::RectangleShape rightBorder(sf::Vector2f(15, 600));
	rightBorder.setPosition(785, 0);
	sf::FloatRect rightBound = rightBorder.getGlobalBounds();

	sf::RectangleShape topBorder(sf::Vector2f(770, 60));
	topBorder.setPosition(15, 0);
	sf::FloatRect topBound = topBorder.getGlobalBounds();

	sf::RectangleShape bottomBorder(sf::Vector2f(770, 20));
	bottomBorder.setPosition(15, 580);
	bottomBorder.setFillColor(sf::Color::Red);
	sf::FloatRect bottomBound = bottomBorder.getGlobalBounds();

	sf::RectangleShape player(sf::Vector2f(50, 10));
	player.setPosition(375, 560);
	player.setFillColor(sf::Color::Blue);

	sf::RectangleShape blockArea(sf::Vector2f(770, 120));
	blockArea.setPosition(15, 60);
	sf::FloatRect blockBound = blockArea.getGlobalBounds();

	sf::RectangleShape resetArea(sf::Vector2f(770, 10));
	resetArea.setPosition(15, 120);
	sf::FloatRect resetBound = resetArea.getGlobalBounds();

	sf::CircleShape ball(5);
	ball.setPosition(395, 550);

	vector<sf::RectangleShape> blocks;
	vector<int> scores;
	vector<sf::FloatRect> blockHitbox;
	vector<sf::Color> colors = { sf::Color(255,0,255), sf::Color(255,0,0), sf::Color(255,164,032), sf::Color(255,255,0), sf::Color(0,255,0), sf::Color(0,255,255) };

	for (float i = 0; i <= 5; i++) {
		float blockY = 60;
		float p = 20 * i;
		blockY = blockY + p;
		int revolutions = 1;
		int value = -2;
		revolutions++;
		if (revolutions == 2) {
			value = value + 3;
			revolutions = 0;
		}
		for (float t = 0; t <= 21; t++) {
			float blockX = 15;
			float o = 35 * t;
			blockX = blockX + o;
			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(35, 20));
			rect.setPosition(blockX, blockY);
			rect.setFillColor(colors[i]);
			blocks.push_back(rect);
			sf::FloatRect rectHit = rect.getGlobalBounds();
			blockHitbox.push_back(rectHit);
			scores.push_back(value);
		}
	}

	bool gameStart = false;

	int score = 00000;
	int highScore = 00000;

	float ballX = 4.f;
	float ballY = -4.f;
	float tempX = 0.f;
	float tempY = 0.f;
	float a = 0.f;
	float b = 0.f;
	float c = 0.f;
	vector<float> tempHold = { tempX, tempY };

	vector<float> ballMovement = { ballX, ballY };

	vector<float> nRight = { -1.f, 0.f };

	vector<float> nLeft = { 1.f, 0.f };

	vector<float> nTop = { 0.f, -1.f };

	vector<float> nBottom = { 0.f, 1.f };

	bool collideLeft = false;
	bool collideRight = false;
	bool can_hit = true;

	sf::Text display_score;

	sf::Text display_highScore;

	sf::Font font;

	if (!font.loadFromFile("Resources/PressStart2P.ttf")) {
		cout << "Could not load for some damn reason" << endl;
	}

	display_score.setFont(font);
	display_highScore.setFont(font);

	display_score.setCharacterSize(30);
	display_highScore.setCharacterSize(30);

	display_score.setFillColor(sf::Color::Black);
	display_highScore.setFillColor(sf::Color::Black);

	display_score.setPosition(20, 10);
	display_highScore.setPosition(620, 10);

	// The main loop - ends as soon as the window is closed
	while (window.isOpen())
	{
		sf::FloatRect playerBound = player.getGlobalBounds();
		sf::FloatRect ballBound = ball.getGlobalBounds();
		collideLeft = false;
		collideRight = false;

		// Event processing
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (playerBound.intersects(leftBound)) {
			collideLeft = true;
		}

		if (playerBound.intersects(rightBound)) {
			collideRight = true;
		}

		if (ballBound.intersects(playerBound)) {

			a = ((ballMovement[0] * nBottom[0]) + (ballMovement[1] * nBottom[1]));
			b = -2 * a;
			tempHold[0] = nBottom[0] * b;
			tempHold[1] = nBottom[1] * b;

			ballMovement[0] = ballMovement[0] + tempHold[0];
			ballMovement[1] = ballMovement[1] + tempHold[1];

			can_hit = true;
		}

		if (ballBound.intersects(rightBound)) {

			a = ((ballMovement[0] * nRight[0]) + (ballMovement[1] * nRight[1]));
			b = -2 * a;
			tempHold[0] = nRight[0] * b;
			tempHold[1] = nRight[1] * b;

			ballMovement[0] = ballMovement[0] + tempHold[0];
			ballMovement[1] = ballMovement[1] + tempHold[1];
		}

		if (ballBound.intersects(leftBound)) {

			a = ((ballMovement[0] * nLeft[0]) + (ballMovement[1] * nLeft[1]));
			b = -2 * a;
			tempHold[0] = nLeft[0] * b;
			tempHold[1] = nLeft[1] * b;

			ballMovement[0] = ballMovement[0] + tempHold[0];
			ballMovement[1] = ballMovement[1] + tempHold[1];
		}

		if (ballBound.intersects(topBound)) {

			a = ((ballMovement[0] * nTop[0]) + (ballMovement[1] * nTop[1]));
			b = -2 * a;
			tempHold[0] = nTop[0] * b;
			tempHold[1] = nTop[1] * b;

			ballMovement[0] = ballMovement[0] + tempHold[0];
			ballMovement[1] = ballMovement[1] + tempHold[1];
		}

		if (ballBound.intersects(blockBound)) {
			for (int i = 0; i <= blockHitbox.size(); i++) {
				if (ballBound.intersects(blockHitbox[i]) && can_hit == true) {
					a = ((ballMovement[0] * nTop[0]) + (ballMovement[1] * nTop[1]));
					b = -2 * a;
					tempHold[0] = nTop[0] * b;
					tempHold[1] = nTop[1] * b;

					ballMovement[0] = ballMovement[0] + tempHold[0];
					ballMovement[1] = ballMovement[1] + tempHold[1];
					can_hit = false;
					score = score + scores[i];
					blockHitbox.erase(blockHitbox.begin() + i);
					scores.erase(scores.begin() + i);
					blocks.erase(blocks.begin() + i);
					break;
				}
			}
		}

		if (ballBound.intersects(bottomBound)) {
			for (int i = 0; i <= blocks.size(); i++) {
				blockHitbox.clear();
				blocks.clear();
				scores.clear();
			}
			player.setPosition(375, 560);
			ball.setPosition(395, 550);
			ballMovement[0] = 4.f;
			ballMovement[1] = -4.f;
			if (score > highScore) {
				highScore = score;
				score = 0;
			}
			for (float i = 0; i <= 5; i++) {
				float blockY = 60;
				float p = 20 * i;
				blockY = blockY + p;
				int revolutions = 1;
				int value = -2;
				revolutions++;
				if (revolutions == 2) {
					value = value + 3;
					revolutions = 0;
				}
				for (float t = 0; t <= 21; t++) {
					float blockX = 15;
					float o = 35 * t;
					blockX = blockX + o;
					sf::RectangleShape rect;
					rect.setSize(sf::Vector2f(35, 20));
					rect.setPosition(blockX, blockY);
					rect.setFillColor(colors[i]);
					blocks.push_back(rect);
					sf::FloatRect rectHit = rect.getGlobalBounds();
					blockHitbox.push_back(rectHit);
					scores.push_back(value);
				}
			}
			gameStart = false;
		}

		if (ballBound.intersects(resetBound)) {
			can_hit = true;
		}

		if (gameStart == true) {
			ball.move(ballMovement[0], ballMovement[1]);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gameStart = true;
			can_hit = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && collideRight == false)
		{
			player.move(5, 0);
			if (gameStart == false) {
				ball.move(5, 0);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && collideLeft == false)
		{
			player.move(-5, 0);
			if (gameStart == false) {
				ball.move(-5, 0);
			}
		}

		stringstream ss;

		ss << score;

		display_score.setString(ss.str());

		stringstream sd;

		sd << highScore;

		display_highScore.setString(sd.str());

		// Clear the whole window before rendering a new frame
		window.clear();
		// Draw some graphical entities
		window.draw(player);
		window.draw(ball);
		window.draw(topBorder);
		window.draw(leftBorder);
		window.draw(rightBorder);
		window.draw(bottomBorder);
		window.draw(display_score);
		window.draw(display_highScore);
		for (std::vector<sf::RectangleShape>::iterator it = blocks.begin(); it != blocks.end(); it++) {
			window.draw(*it);
		}
		// End the current frame and display its contents on screen
		window.display();
	}
	return 0;
}