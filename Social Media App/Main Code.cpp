#include <iostream>
#include<Phases.h>
#include<vector>
#include <SFML/Graphics.hpp>


int main() {
	std::vector<button*> mainmenuinterface;
	std::vector<texter*> mainmenutext;
	std::vector<button*> selectinterface;
	std::vector<texter*> selectusertext;
	std::vector<button*> feedinterface;
	std::vector<texter*> feedtext;
	std::vector<std::vector<texter*>*> feedtextperuser;
	//button* selectuseradd=nullptr;

	//test area
	std::string a; std::string b; std :: string c;
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
	start.loadstats(people,Application,mainmenuinterface, mainmenutext, selectinterface, selectusertext, feedinterface, feedtext);
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
			start.mainmenu(Application, Platform, mainmenuinterface, mainmenutext);
			break;
		case 1:
			start.selectuser(Application, Platform,people, selectinterface, selectusertext);
			break;
		case 4:
			start.newuser(Application, Platform, pero,people,a,b);
			break;
		case 2:
			start.friendspage(Application, Platform);
			break;
		case 3:
			start.feed(Application, Platform,feedinterface,feedtext);
			break;
		case 10:
			start.newcomment(Application, Platform, pero, c);
			break;
		}

		Application->display();

	}
	start.releasedata(people);

}





