#include <iostream>
#include <Drawer.h>
#include <SFML/Graphics.hpp>


int main() {
	//std::cout << sf::VideoMode::getDesktopMode().width;
	//std::cout << sf::VideoMode::getDesktopMode().height;
	//std::cout << 0.5625 * sf::VideoMode::getDesktopMode().height;


	//test area


	sf::RenderWindow* Application=new sf::RenderWindow(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);
	std::cout << Application->getSize().x;
	std::cout<<Application->getSize().y;

	while (Application->isOpen()) {
		sf::Event Platform;
		while (Application->pollEvent(Platform)) {
			if (Platform.type == Platform.Closed) {
				Application->close();
			}
		}

		texter lol("Jersey Sharp.ttf","Lel",30,255,255,255,255);
		//Application->clear();
		//Application->draw();
		//Application->display();
		//std::cout << "test";

	}

}





