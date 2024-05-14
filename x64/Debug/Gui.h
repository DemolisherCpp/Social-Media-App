#ifndef GUI_H
#define GUI_H

#include<iostream>
#include<vector>
#include<Drawer.h>
#include<Structure.h>
#include <SFML/Graphics.hpp>
#include<fstream>
class gui {
public:
	static int phase;
	static bool tbphase;
	static int oned;
	static int twod;
	static user* currentuser;
	void adduser(std::vector<user*> & ,std::string,std::string);
	void setcurrentuser(user*);
	void loaddata(std::vector<user*> & data , std::vector<page*>& server);
	void releasedata(std::vector<user*> , std::vector<page*>& server);
	void mainmenu(sf::RenderWindow* , sf::Event* , std::vector<button*>& menudata, std::vector<texter*> & menutext,char*);
	void selectuser(sf::RenderWindow*, sf::Event*, std::vector<user*> &, std::vector<button*> , std::vector<texter*>,char *);
	void newuser(sf::RenderWindow*, sf::Event*, char*, std::vector<user*> & ,std::string &,std::string &);
	void friendspage(sf::RenderWindow*, sf::Event*);
	void feed(sf::RenderWindow*, sf::Event*, std::vector<button*> , std::vector<texter*>, char*);
	void pagefeed(sf::RenderWindow*, sf::Event*, std::vector<button*>, std::vector<texter*>, char*);
	void loadstats(std::vector<user*>, sf::RenderWindow*, std::vector<button*>& menudata, std::vector<texter*>& menutext, std::vector<button*>& selectuserdata, std::vector<texter*>& selectusertext, std::vector<button*>&, std::vector<texter*>&, std::vector<button*> &, std::vector<texter*> & , std::vector<button*>&, std::vector<texter*>&);
	void newcomment(sf::RenderWindow*, sf::Event*, char* , std::string & );
	void searchfriend(sf::RenderWindow*, sf::Event*, std::vector<user*>& , char*, std::string&);
	void home(sf::RenderWindow*, sf::Event*, std::vector<button*>, std::vector<texter*>, char*);
	void postadder(sf::RenderWindow*, sf::Event*,char*text, std::string & , std::string &);
	void pageadder(sf::RenderWindow*, sf::Event*, std::vector<page*>&, char*, std::string&);
	void pagecomment(sf::RenderWindow*, sf::Event*, char*, std::string&);




};

int gui::phase = 0;
bool gui::tbphase = 0;
int gui::oned = 0;
int gui::twod = 0;
user* gui::currentuser = nullptr;

void gui :: setcurrentuser(user* a) {
	currentuser = a;
}



void gui::adduser(std::vector<user*> & data,std::string a,std::string b) {
	user* dummy = new user(a, b);
	data.push_back(dummy);
	data[0]->setnoofusers(data.size());
}


void gui:: mainmenu(sf::RenderWindow* plane, sf::Event* event, std::vector<button*>& menudata, std::vector<texter*>& menutext,char*text) {
	//drawings
	plane->clear(sf::Color::White);
	//print stats
	for (int i = 0; i < menudata.size(); i++) {
		*(menudata[i]) > plane;
		if (menudata[i]->intersect(plane, event)) {
			if (i == 4||i==5) {
				for (int i = 0; i < 50; i++) {
					text[i] = '\0';
				}
				phase = i + 1;
			}
			else {
				phase = i + 1;
			}
		}
	}
	if (currentuser == nullptr) {
		plane->draw(menutext[0]->data());
	}
	else if (currentuser != nullptr) {
		plane->draw(menutext[1]->data());
	}
	//functions
	//test
}

void gui::friendspage(sf::RenderWindow* plane, sf::Event* event) {
	plane->clear(sf::Color::White);
	texter heading("Jerse.ttf", "Friends", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 20);
	plane->draw(heading.data());
	if (currentuser != nullptr) {
		for (int i = 0; i < currentuser->getfriends().size(); i++) {
			texter ids("Inter.ttf",currentuser->getfriendid(i), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, i * (plane->getSize().y / 10.8) + plane->getSize().y / 5);
			texter names("Inter.ttf", currentuser->getfriendname(i), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, ((plane->getSize().y / 10.8) / 2) + i * (plane->getSize().y / 10.8) + plane->getSize().y / 5);
			plane->draw(ids.data());
			plane->draw(names.data());
		}
	}
	//if you are looking to return that is
	if (event->text.unicode == sf::Keyboard::Escape) {
		phase = 0;
	}

}

void gui::selectuser(sf::RenderWindow* plane, sf::Event* event, std::vector<user*> & data  , std::vector<button*> selectuserdata, std::vector<texter*> selectusertext, char* text) {
	plane->clear(sf::Color::White);
	for (int i = 0; i < selectuserdata.size()-1; i++) {
		*selectuserdata[i] > plane;
		if (selectuserdata[i]->intersect(plane, event)) {
			currentuser = data[i];
			phase = 0;
		}
	}
	for (int i = 0; i < selectusertext.size(); i++) {
		plane->draw(selectusertext[i]->data());
	}
	*(selectuserdata[selectuserdata.size() - 1]) > plane;
		if (selectuserdata[selectuserdata.size() - 1]->intersect(plane, event)) {
			for (int i = 0; i < 50; i++) {
				text[i] = '\0';
			}
			phase = 9;
		}

}
#endif



