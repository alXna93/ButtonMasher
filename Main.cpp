//included libraries

#include <SFML/Graphics.hpp>


//entry point for program
int main()
{
	//Make a variable called gameWindow for type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf ::Style::Titlebar | sf::Style::Close);


	//Game Loop
	//Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		
		//Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//process events

			//check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}
			

		//TODO: Update game state

		//TODO: Draw graphics
	}

	//exit point for program
	return 0;
}