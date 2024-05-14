#include <iostream>
#include <Guifilehandlers.h>
#include <AdderCode.h>
#include <Feeds.h>
#include <Graphicsloader.h>
#include<vector>
#include <SFML/Graphics.hpp>


int main() {
	std::vector<button*> mainmenuinterface;
	std::vector<texter*> mainmenutext;
	std::vector<button*> selectinterface;
	std::vector<texter*> selectusertext;
	std::vector<button*> feedinterface;
	std::vector<texter*> feedtext;
	//std::vector<std::vector<texter*>*> feedtextperuser;
	//button* selectuseradd=nullptr;
	std::vector<button*> homeinterface;
	std::vector<texter*> hometext;
	std::vector<button*> pagefeedinterface;
	std::vector<texter*> pagefeedtext;


	//test area
	std::string a; std::string b; std::string c; std::string d; std::string e; std::string f; std::string g; std::string h;
	char* pero = new char[50];
	for (int i = 0; i < 50; i++) {
		pero[i] = '\0';
	}


	gui start;
	std::vector<user*> people;
	std::vector<page*> elites;
	//user** people=nullptr;
	start.loaddata(people,elites);
	sf::RenderWindow* Application=new sf::RenderWindow(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);
	Application->setFramerateLimit(240);
	start.loadstats(people,Application,mainmenuinterface, mainmenutext, selectinterface, selectusertext, feedinterface, feedtext, homeinterface, hometext, pagefeedinterface, pagefeedtext);
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
			start.mainmenu(Application, Platform, mainmenuinterface, mainmenutext,pero);
			break;
		case 1:
			start.selectuser(Application, Platform,people, selectinterface, selectusertext,pero);
			break;
		case 2:
			start.friendspage(Application, Platform);
			break;
		case 3:
			start.feed(Application, Platform,feedinterface,feedtext,pero);
			break;
		case 4:
			start.home(Application, Platform,homeinterface,hometext,pero);
			break;
		case 5:
			start.searchfriend(Application, Platform,people, pero,f);
			break;
		case 6:
			start.pageadder(Application, Platform, elites, pero, f);
			break;
		case 7:
			start.pagefeed(Application, Platform ,pagefeedinterface, pagefeedtext, pero);
			break;
		case 8:
			start.loadstats(people, Application, mainmenuinterface, mainmenutext, selectinterface, selectusertext, feedinterface, feedtext, homeinterface, hometext, pagefeedinterface, pagefeedtext);
			start.phase = 0;
			break;
		case 9:
			start.newuser(Application, Platform, pero, people, a, b);
			break;
		case 10:
			start.newcomment(Application, Platform, pero, c);
			break;
		case 11:
			start.postadder(Application, Platform, pero, d,e);
			break;
		case 12:
			start.pagecomment(Application, Platform, pero,h);
			break;
		}

		Application->display();

	}
	start.releasedata(people,elites);

}





