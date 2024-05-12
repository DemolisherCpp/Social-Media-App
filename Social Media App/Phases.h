#ifndef PHASES_H
#define PHASES_H

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
	void loaddata(std::vector<user*> & data);
	void releasedata(std::vector<user*>);
	void mainmenu(sf::RenderWindow* , sf::Event* );
	void selectuser(sf::RenderWindow*, sf::Event*, std::vector<user*> &);
	void newuser(sf::RenderWindow*, sf::Event*, char*, std::vector<user*> & ,std::string &,std::string &);
	void friendspage(sf::RenderWindow*, sf::Event*);
	void feed(sf::RenderWindow*, sf::Event*);




};

int gui::phase = 0;
bool gui::tbphase = 0;
int gui::oned = 0;
int gui::twod = 0;
user* gui::currentuser = nullptr;

void gui :: setcurrentuser(user* a) {
	currentuser = a;
}

void gui::loaddata(std::vector<user*>& data) {
	std::ifstream file;
	file.open("users.txt");
	user dummy;
	int a;
	int b;
	int e;
	file >> a;
	dummy.setnoofusers(a);
	//users
	for (int i = 0; i < a; i++) {
		std::string c;
		std::string d;
		file >> c;
		file.ignore();
		std::getline(file, d);
		file >> b;
		file >> e;
		data.push_back(new user(c, d, b,e));
	}
	//friends
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < data[i]->getnooffriends(); j++) {
			std::string f;
			file >> f;
			for (int k = 0; k < a; k++) {
				if (f == (data[k]->getid())) {
					data[i]->addfriend(data[k]);
				}
			}
		}
	}
	//posts
	std::string p;
	std::string o;
	int z;
	std::string pth;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < data[i]->getnoofposts(); j++) {
			file >> p;
			file.ignore();
			std::getline(file, o);
			file >> z;
			file >> pth;
			file >> a;
			data[i]->addpost(p, o, z, pth,a);
			for (int k = 0; k < a; k++) {
				file.ignore();
				std::getline(file, p);
				file.ignore();
				std::getline(file, o);
				data[i]->getposts()[j].addcomment(p,o);
			}
		}
	}
	file.close();
}

void gui::adduser(std::vector<user*> & data,std::string a,std::string b) {
	user* dummy = new user(a, b);
	data.push_back(dummy);
	data[0]->setnoofusers(data.size());
}


void gui:: mainmenu(sf::RenderWindow* plane, sf::Event* event) {
	//drawings
	plane->clear(sf::Color::White);
	button userbutton("user.png", plane->getSize().y / 14.4, plane->getSize().y / 14.4, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), 0 + ((plane->getSize().y / 14.4) / 2));
	if (userbutton.intersect(plane, event)) {
		std::cout << "Phase switched";
		phase = 1;
	}
	userbutton > plane;
	if (currentuser == nullptr) {
		texter userbuttontext("Inter.ttf", "Signed Out", (plane->getSize().y / 14.4)/5, 0, 0, 0, 255, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), (0 + ((plane->getSize().y / 14.4) / 2))+ ((plane->getSize().y / 14.4)/2));
		plane->draw(userbuttontext.data());
	}
	else if (currentuser != nullptr) {
		texter userbuttontext("Inter.ttf", "Signed In", (plane->getSize().y / 14.4) / 5, 0, 0, 0, 255, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), (0 + ((plane->getSize().y / 14.4) / 2)) + ((plane->getSize().y / 14.4) / 2));
		plane->draw(userbuttontext.data());
	}
	button friends("friends.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6,0.03,0.03);
	if (friends.intersect(plane, event)) {
		phase = 3;
	}
	friends > plane;
	button posts("Post.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 0.15, 0.15);
	if (posts.intersect(plane, event)) {
		phase = 4;
	}
	posts > plane;


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

void gui :: feed (sf::RenderWindow* plane, sf::Event* event) {
	plane->clear(sf::Color::White);
	texter heading("Jerse.ttf", "Posts", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 25);
	plane->draw(heading.data());
    if (currentuser != nullptr) {
	    if (event->text.unicode == sf::Keyboard::Tab) {
		       twod++;
	       }
	    if (twod == (currentuser->getfriends()[oned])->getnoofposts()) {
		 oned++;
		 twod = 0;
	       }
		if (oned == currentuser->getnooffriends()) {
			oned = 0;
			twod = 0;
		}
		texter ids("Inter.ttf", (currentuser->getfriends()[oned])->getname(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2,plane->getSize().y / 10);
				texter lel("Inter.ttf", (currentuser->getfriends()[oned])->getposttext(twod), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2,plane->getSize().y / 7);
				texter chead("Inter.ttf","Comments : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
				sf::Texture texture;
				std::string a = "Resources\\Images\\";
				std::string b = (currentuser->getfriends()[oned])->getpostpicpath(twod);
				a += b;
				texture.loadFromFile(a);
				sf::Sprite sprite;
				sprite.setTexture(texture);
				sf::FloatRect coords = sprite.getLocalBounds();
				sprite.setOrigin(coords.width / 2, coords.height / 2);
				sprite.setOrigin(150, 150);
				sprite.setPosition(plane->getSize().x / 2, plane->getSize().y / 3);
				plane->draw(sprite);
				plane->draw(ids.data());
				plane->draw(lel.data());
				plane->draw(chead.data());
	}




	//if you are looking to return that is
	if (event->text.unicode == sf::Keyboard::Escape) {
		phase = 0;
	}
}

void gui::releasedata(std::vector<user*> data) {
	std::ofstream file;
	file.open("users.txt",std::ofstream::trunc);
	file<<data[0]->getnoofusers();
	file << std::endl << std::endl;
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		file << data[i]->getid() << std::endl;
		file << data[i]->getname() << std::endl;
		file << data[i]->getnooffriends() << std::endl;
		file << data[i]->getnoofposts() << std::endl << std::endl;
	}
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		for (int j = 0; j < data[i]->getnooffriends(); j++) {
			file << data[i]->getfriends()[j]->getid() << std::endl;
		}
	}
	file << std::endl;
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		for (int j = 0; j < data[i]->getnoofposts(); j++) {
			file << data[i]->getpostid(j) << std::endl;
			file << data[i]->getposttext(j) << std::endl;
			file << data[i]->getpostdate(j) << std::endl;
			file << data[i]->getpostpicpath(j) << std::endl;
			file << data[i]->getposts()[j].getnoofcomments() << std::endl;
			for (int k = 0; k < data[i]->getposts()[j].getcomments().size(); k++) {
				file << data[i]->getposts()[j].getcomments()[k].getusername() << std::endl;
				file << data[i]->getposts()[j].getcomments()[k].gettext() << std::endl;
			}
			file << std::endl;

		}
	}
	file.close();
}

void gui::selectuser(sf::RenderWindow* plane, sf::Event* event, std::vector<user*> & data) {
	plane->clear(sf::Color::White);
	texter heading("Jerse.ttf", "Select User", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x/2, plane->getSize().y/20);
	plane->draw(heading.data());
	int k = 0;
	int l = 0;
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		button users("user.png", plane->getSize().x / 4.669230769230, plane->getSize().x / 4.669230769230, (l*2)*(plane->getSize().x/6.07)+(plane->getSize().x / 6.07), 100+((k * 2) * (plane->getSize().y / 13.5) + (plane->getSize().y / 13.5)),0.4,0.4);
		texter id("Inter.ttf", data[i]->getid(), (plane->getSize().x / 4.669230769230)/4.333333333, 0, 0, 0, 255, (l * 2) * (plane->getSize().x / 6.07) + (plane->getSize().x / 6.07), ((plane->getSize().x / 4.669230769230)/2)+ 100 + ((k * 2) * (plane->getSize().y / 13.5) + (plane->getSize().y / 13.5)));
		if (users.intersect(plane, event)) {
			std::cout << "Phase switched";
			currentuser = data[i];
			phase = 0;
		}
		users > plane;
		plane->draw(id.data());
		l++;
		if (l == 3) {
			l = 0;
			k++;
		}

	}
	button add("add.png", plane->getSize().x / 5.0583333333, plane->getSize().x / 5.0583333333,plane->getSize().x/2,plane->getSize().y*17/20,0.08,0.08);
		if (add.intersect(plane, event)) {
			std::cout << "Phase switched";
			phase = 2;
		}
		add > plane;

}

void gui::newuser(sf::RenderWindow* plane, sf::Event* event, char* text, std::vector<user*> & data, std::string & b,std::string & c) {
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
			adduser(data,b,c);
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



#endif



