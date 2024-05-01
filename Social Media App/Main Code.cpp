#include <iostream>
#include <SFML/Graphics.hpp>



sf::Font fontloader(std::string addpath= "Jersey Sharp.ttf") {
	std::string path="Resources\\Fonts\\";
	path += addpath;
	sf::Font font;
	if (!font.loadFromFile(path)) {
		std::cout << "The font of one of the texts could not be loaded" << std::endl;
		exit(0);
	}
	return font;
}


	int main() {
		//std::cout << sf::VideoMode::getDesktopMode().width;
		//std::cout << sf::VideoMode::getDesktopMode().height;
		//std::cout << 0.5625 * sf::VideoMode::getDesktopMode().height;


		//test area


		sf::RenderWindow Application(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);


		while (Application.isOpen()) {
			sf::Event Platform;
			while (Application.pollEvent(Platform)) {
				if (Platform.type == Platform.Closed) {
					Application.close();
				}
			}

			//sf::Font font;
			//font.loadFromFile("Resources\\Fonts\\Jersey Sharp.ttf");
			//test.setFont(font);
			//test.setString("test");
			//texter(lol, "Jersey Sharp.ttf");
			Application.clear();
			//Application.draw(test);
			//sf::Text lol("Test", fontloader(), 30);
			//Application.draw(lol);
			Application.display();
			std::cout << "test";
			
		}






		sf::RenderWindow test(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);


		while (test.isOpen()) {
			sf::Event Platform;
			while (test.pollEvent(Platform)) {
				if (Platform.type == Platform.Closed) {
					test.close();
				}
			}

			//sf::Font font;
			//font.loadFromFile("Resources\\Fonts\\Jersey Sharp.ttf");
			//test.setFont(font);
			//test.setString("test");
			//texter(lol, "Jersey Sharp.ttf");
			test.clear();
			//Application.draw(test);
			//sf::Text lol("Test", fontloader(), 30);
			//Application.draw(lol);
			test.display();
			std::cout << "test";

		}
	}
