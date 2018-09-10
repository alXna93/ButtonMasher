//included libraries

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


//entry point for program
int main()
{
	//Make a variable called gameWindow for type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf ::Style::Titlebar | sf::Style::Close);

	//----------------------------------------------------------
	//Game Setup
	//----------------------------------------------------------
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	buttonSprite.setPosition(gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);

	//Audio
	sf::Music gameMusic;

	//load audio from file
	gameMusic.openFromFile("audio/music.ogg");
	//play music
	gameMusic.play();

	//Title text
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(34);
	titleText.setFillColor(sf::Color::Cyan);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 150);

	//Author Text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("by Alana McDowall!");
	authorText.setCharacterSize(24);
	authorText.setFillColor(sf::Color::Cyan);
	authorText.setStyle(sf::Text::Bold);
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 250);

	//score text
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);

	//timer text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);

	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	//click sound effect
	sf::SoundBuffer clickBuffer;
	//tell the click sound buffer where file is
	clickBuffer.loadFromFile("audio/buttonclick.ogg");

	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//track whether player is playing
	bool playing = false;

	//----------------------------------------------------------
	//Game Loop
	//Runs every frame until the game window is closed
	//----------------------------------------------------------
	while (gameWindow.isOpen())
	{
		//-----------------------------------------------------
		//Check for input
		//-----------------------------------------------------

		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//process events

			//check if player clicked mouse
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				//did player click on the button
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y));
				{
					clickSound.play();



					if (playing == true)
					{
						score = score + 1;
					}
					else
					{
						playing = true;
					}
				}
			}
			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}
			

		//TODO: Update game state

		//score
		scoreText.setString("Score: " + std::to_string(score));

		//timer
		sf::Time frameTime = gameClock.restart();
		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;

			if (timeRemaining.asSeconds() <= 0)
			{
				//set playing to false
				playing = false;
			}
		}
				//update prompt
		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));

		//Draw graphics

		//Clear the window to a single colour
		gameWindow.clear(sf::Color(128, 128, 128));

		//Draw everything to the window
		gameWindow.draw(buttonSprite);

		//draw text
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);

		//Display the window contents on the screen
		gameWindow.display();

		

		//TODO: Draw more stuff


	}

	//exit point for program
	return 0;
}