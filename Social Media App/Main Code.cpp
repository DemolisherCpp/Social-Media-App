#include <iostream>
#include <Drawer.h>
#include <SFML/Graphics.hpp>


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


		//Application.clear();
		texter test;
		Application.draw(test.data());
		Application.display();
		//std::cout << "test";

	}

}





