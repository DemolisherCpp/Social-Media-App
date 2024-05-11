#ifndef PHASES_H
#define PHASES_H

#include<iostream>
#include<Drawer.h>
#include<Structure.h>
#include <SFML/Graphics.hpp>
#include<fstream>
class gui {
public:
	static int phase;
	void loaddata(user** &);
	void releasedata(user**);
	void mainmenu(sf::RenderWindow* , sf::Event* );
	void selectuser(sf::RenderWindow*, sf::Event*,char*);


};

int gui::phase = 0;


void gui:: mainmenu(sf::RenderWindow* plane, sf::Event* event) {
	//drawings
	button userbutton("user.png", plane->getSize().y / 14.4, plane->getSize().y / 14.4, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), 0 + ((plane->getSize().y / 14.4) / 2));
	if (userbutton.intersect(plane, event)) {
		std::cout << "Phase switched";
		phase = 1;
	}
	userbutton > plane;


	//functions




	//test

}


void gui::loaddata(user**  & data) {
	std::ifstream file;
	file.open("users.txt");
	user dummy;
	int a;
	int b;
	file >> a;
	dummy.setnoofusers(a);
	data = new user * [a];
	for (int i = 0; i < a; i++) {
		std::string c;
		std::string d;
		file >> c;
		file.ignore();
		std::getline(file, d);
		file >> b;
		data[i] = new user(c, d, b);
	}
	for (int i = 0; i < a; i++) {
		user** temp = new user * [data[i]->getnooffriends()];
		for (int j = 0; j < data[i]->getnooffriends(); j++) {
			std::string f;
			file >> f;
			for (int k = 0; k < a; k++) {
				if (f == data[k]->getid()) {
					temp[j] = data[k];
				}
			}
		}
		data[i]->setfriends(temp);
	}
	file.close();
}

void gui::releasedata(user** data) {
	std::ofstream file;
	file.open("users.txt",std::ofstream::trunc);
	file<<data[0]->getnoofusers();
	file << std::endl << std::endl;
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		file << data[i]->getid() << std::endl;
		file << data[i]->getname() << std::endl;
		file << data[i]->getnooffriends() << std::endl << std::endl;
	}
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		for (int j = 0; j < data[i]->getnooffriends(); j++) {
			file << data[i]->getfriends()[j]->getid() << std::endl;
		}
	}
	file.close();
}

void gui::selectuser(sf::RenderWindow* plane, sf::Event* event,char*text) {
	plane->clear(sf::Color::White);
	button textbox("textbox.png", 200, 50, 300, 300,1.9,1.25);
	textbox.write(plane,event,text);
	std::string a;
	//for (int i = 0; i < 15; i++) {
	//	a[i] = '\0';
	//}
	//for (int i = 0; i < 15; i++) {
	//	a[i] = text[i];
	//}
	char lol[15] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	//std::cout << text;
	textbox > plane;
	texter writer("Inter.ttf", lol, 150, 255, 0, 0, 255, 300, 300);
	plane->draw(writer.data());
}

#endif



