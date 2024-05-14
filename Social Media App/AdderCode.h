#ifndef ADDERCODE_H
#define ADDERCODE_H

#include<iostream>
#include<Gui.h>


void gui::newuser(sf::RenderWindow* plane, sf::Event* event, char* text, std::vector<user*>& data, std::string& b, std::string& c) {
	plane->clear(sf::Color::White);

	switch (tbphase) {
	case 0:
	{texter enter("Inter.ttf", "Enter Id", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {

		b = text;

		tbphase = 1;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, 50, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
	break;
	}
	case 1:
		texter enter("Inter.ttf", "Enter Name", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
		plane->draw(enter.data());
		button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
		if (textbox.write(plane, event, text)) {
			c = text;
			adduser(data, b, c);
			tbphase = 0;
			phase = 0;
		}
		std::string a;
		char lol[50] = {};
		int i = 0;
		for (i = 0; text[i] != '\0'; i++) {
			lol[i] = text[i];
		}
		lol[i] = '\0';
		textbox > plane;
		texter writer("Inter.ttf", lol, 50, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
		plane->draw(writer.data());
	}
}


void gui::newcomment(sf::RenderWindow* plane, sf::Event* event, char* text, std::string& c) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter Comment", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		c = text;
		(currentuser->getfriends()[oned])->getpost(twod)->addcomment(currentuser->getname(), c);
		(currentuser->getfriends()[oned])->getpost(twod)->setnoofcomments((currentuser->getfriends()[oned])->getpost(twod)->getcomments().size());
		//adduser(data, b, c);
		phase = 3;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
}

void gui::searchfriend(sf::RenderWindow* plane, sf::Event* event, std::vector<user*>& data, char* text, std::string& f) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter User ID", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		f = text;
		if (f != currentuser->getid()) {
			for (int i = 0; i < currentuser->getfriends().size(); i++) {
				if (f == currentuser->getfriendid(i)) {
					std::cout << "Friend is already added" << std::endl;
					phase = 0;
					break;
				}
				if (i + 1 == currentuser->getfriends().size()) {
					for (int i = 0; i < data.size(); i++) {
						if (f == data[i]->getid()) {
							currentuser->addfriend(data[i]);
							currentuser->setnooffriends(currentuser->getfriends().size());
							std::cout << "Friend added" << std::endl;
							phase = 0;
							break;
						}
					}
				}
			}
			if (currentuser->getfriends().size() == 0) {
				for (int i = 0; i < data.size(); i++) {
					if (f == data[i]->getid()) {
						currentuser->addfriend(data[i]);
						currentuser->setnooffriends(currentuser->getfriends().size());
						std::cout << "Friend added" << std::endl;
						phase = 0;
					}
				}
			}
			phase = 0;
		}
		phase = 0;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
}

void gui::postadder(sf::RenderWindow* plane, sf::Event* event, char* text, std::string& d, std::string& e) {
	plane->clear(sf::Color::White);
	switch (tbphase) {
	case 0:
	{texter enter("Inter.ttf", "Enter Post Id", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {

		d = text;

		tbphase = 1;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
	break;
	}
	case 1:
		texter enter("Inter.ttf", "Enter Post Content", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
		plane->draw(enter.data());
		button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
		if (textbox.write(plane, event, text)) {
			e = text;
			currentuser->addpost(d, e);
			currentuser->setnoofposts(currentuser->getposts().size());
			tbphase = 0;
			phase = 0;
		}
		std::string a;
		char lol[50] = {};
		int i = 0;
		for (i = 0; text[i] != '\0'; i++) {
			lol[i] = text[i];
		}
		lol[i] = '\0';
		textbox > plane;
		texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
		plane->draw(writer.data());
	}
}

void gui::pageadder(sf::RenderWindow* plane, sf::Event* event, std::vector<page*>& server, char* text, std::string& g) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter Page ID", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		g = text;
		for (int i = 0; i < currentuser->getfollowedpages().size(); i++) {
			if (g == currentuser->getfollowedpages()[i]->getid()) {
				std::cout << "Page is already added" << std::endl;
				phase = 0;
				break;
			}
			if (i + 1 == currentuser->getfollowedpages().size()) {
				for (int i = 0; i < server.size(); i++) {
					if (g == server[i]->getid()) {
						currentuser->addpage(server[i]);
						currentuser->setnooffollowedpages(currentuser->getfollowedpages().size());
						std::cout << "Page added" << std::endl;
						phase = 0;
						break;
					}
				}
			}
		}
		if (currentuser->getfollowedpages().size() == 0) {
			for (int i = 0; i < server.size(); i++) {
				if (g == server[i]->getid()) {
					currentuser->addpage(server[i]);
					currentuser->setnooffollowedpages(currentuser->getfollowedpages().size());
					std::cout << "Page added" << std::endl;
					phase = 0;
				}
			}
		}
		phase = 0;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
}

void gui::pagecomment(sf::RenderWindow* plane, sf::Event* event, char* text, std::string& c) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter Comment", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		c = text;
		(currentuser->getfollowedpages()[oned])->getpost(twod)->addcomment(currentuser->getname(), c);
		(currentuser->getfollowedpages()[oned])->getpost(twod)->setnoofcomments((currentuser->getfollowedpages()[oned])->getpost(twod)->getcomments().size());
		//adduser(data, b, c);
		phase = 7;
	}
	std::string a;
	char lol[50] = {};
	int i = 0;
	for (i = 0; text[i] != '\0'; i++) {
		lol[i] = text[i];
	}
	lol[i] = '\0';
	textbox > plane;
	texter writer("Inter.ttf", lol, plane->getSize().x / 15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
	plane->draw(writer.data());
}














#endif