#include <iostream>
//#include <Drawer.h>
#include<Phases.h>
#include <SFML/Graphics.hpp>


int main() {
	//std::cout << sf::VideoMode::getDesktopMode().width;
	//std::cout << sf::VideoMode::getDesktopMode().height;
	//std::cout << 0.5625 * sf::VideoMode::getDesktopMode().height;


	//test area


	sf::RenderWindow* Application=new sf::RenderWindow(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);
	std::cout << Application->getSize().x;
	std::cout<<Application->getSize().y;
	//sf::Mouse::setPosition();

	while (Application->isOpen()) {
		sf::Event* Platform=new sf::Event;
		while (Application->pollEvent(*Platform)) {
			if (Platform->type == Platform->Closed) {
				Application->close();
			}
		}

		//texter lol("Jersey Sharp.ttf","Lel",30,255,255,255,255,303.5,540);
		//button lel;

		//Application->clear();
		//Application->draw(lol.data());
		//lel > Application;
		mainmenu(Application, Platform);

		//button userbutton("user.png", sf::VideoMode::getDesktopMode().height / 14.4, sf::VideoMode::getDesktopMode().height / 14.4, sf::VideoMode::getDesktopMode().width - ((sf::VideoMode::getDesktopMode().height / 14.4) / 2), 0 + ((sf::VideoMode::getDesktopMode().height / 14.4) / 2));
		//userbutton > Application;

		Application->display();
		//std::cout << "test";

	}

}





