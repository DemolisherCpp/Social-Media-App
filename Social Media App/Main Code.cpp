#include <iostream>
#include<Phases.h>
#include<vector>
#include <SFML/Graphics.hpp>


int main() {


	//test area
	std::string a; std::string b;
	char* pero = new char[50];
	for (int i = 0; i < 50; i++) {
		pero[i] = '\0';
	}


	gui start;
	std::vector<user*> people;
	//user** people=nullptr;
	start.loaddata(people);
	sf::RenderWindow* Application=new sf::RenderWindow(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);
	Application->setFramerateLimit(240);
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
			start.selectuser(Application, Platform,people);
			break;
		case 2:
			start.newuser(Application, Platform, pero,people,a,b);
			break;
		case 3:
			start.friendspage(Application, Platform);
			break;
		case 4:
			start.feed(Application, Platform);
			break;
		}

		Application->display();

	}
	start.releasedata(people);

}





