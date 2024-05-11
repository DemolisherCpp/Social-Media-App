#include <iostream>
#include<Phases.h>
#include <SFML/Graphics.hpp>


int main() {


	//test area
	char* pero = new char[15];
	for (int i = 0; i < 15; i++) {
		pero[i] = '\0';
	}


	gui start;
	user** lel=nullptr;
	start.loaddata(lel);
	start.releasedata(lel);
	sf::RenderWindow* Application=new sf::RenderWindow(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);
	//std::cout << Application->getSize().x;
	//std::cout<<Application->getSize().y;

	while (Application->isOpen()) {
		sf::Event* Platform=new sf::Event;
		while (Application->pollEvent(*Platform)) {
			if (Platform->type == Platform->Closed) {
				Application->close();
			}
		}

		//texter lol("Jersey Sharp.ttf","Lel",30,255,255,255,255,303.5,540);
		//Application->clear();
		switch (start.phase) {
		case 0:
			start.mainmenu(Application, Platform);
			break;
		case 1:
			start.selectuser(Application, Platform,pero);
		}

		Application->display();

	}

}





