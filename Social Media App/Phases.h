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
	void mainmenu(sf::RenderWindow* , sf::Event* , std::vector<button*>& menudata, std::vector<texter*> & menutext,char*);
	void selectuser(sf::RenderWindow*, sf::Event*, std::vector<user*> &, std::vector<button*> , std::vector<texter*>,char *);
	void newuser(sf::RenderWindow*, sf::Event*, char*, std::vector<user*> & ,std::string &,std::string &);
	void friendspage(sf::RenderWindow*, sf::Event*);
	void feed(sf::RenderWindow*, sf::Event*, std::vector<button*> , std::vector<texter*>, char*);
	void loadstats(std::vector<user*>, sf::RenderWindow*, std::vector<button*>& menudata, std::vector<texter*>& menutext, std::vector<button*>& selectuserdata, std::vector<texter*>& selectusertext, std::vector<button*>&, std::vector<texter*>&, std::vector<button*> &, std::vector<texter*> &);
	void newcomment(sf::RenderWindow*, sf::Event*, char* , std::string & );
	void searchfriend(sf::RenderWindow*, sf::Event*, std::vector<user*>& , char*, std::string&);
	void home(sf::RenderWindow*, sf::Event*, std::vector<button*>, std::vector<texter*>, char*);
	void postadder(sf::RenderWindow*, sf::Event*,char*text, std::string & , std::string &);




};

void gui::loadstats(std::vector<user*> data, sf::RenderWindow* plane, std::vector<button*>& menudata, std::vector<texter*>& menutext, std::vector<button*>& selectuserdata, std::vector<texter*>& selectusertext , std::vector<button*>& feeddata, std::vector<texter*>& feedtext, std::vector<button*> & homedata, std::vector<texter*> & hometext){

	std::cout << "Initializing and loading Graphics" << std::endl << std::endl;

	//main mennu
	menudata.push_back(new button("user.png", plane->getSize().y / 14.4, plane->getSize().y / 14.4, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), 0 + ((plane->getSize().y / 14.4) / 2)));
	menudata.push_back(new button("friends.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6, 0.03, 0.03));
	menudata.push_back(new button("Post.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 0.15, 0.15));
	menudata.push_back(new button("home.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.16, 1.5,1.5));
	menudata.push_back(new button("addfriend.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x *0.92, plane->getSize().y / 3.6, 0.75, 0.75));
	menutext.push_back(new texter("Inter.ttf", "Signed Out", (plane->getSize().y / 14.4) / 5, 0, 0, 0, 255, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), (0 + ((plane->getSize().y / 14.4) / 2)) + ((plane->getSize().y / 14.4) / 2)));
	menutext.push_back(new texter("Inter.ttf", "Signed In", (plane->getSize().y / 14.4) / 5, 0, 0, 0, 255, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), (0 + ((plane->getSize().y / 14.4) / 2)) + ((plane->getSize().y / 14.4) / 2)));
	//selectuser


	selectusertext.push_back(new texter("Jerse.ttf", "Select User", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 20));
	//plane->draw(heading.data());
	int k = 0;
	int l = 0;
	for (int i = 0; i < data[0]->getnoofusers(); i++) {
		selectuserdata.push_back(new button("user.png", plane->getSize().x / 4.669230769230, plane->getSize().x / 4.669230769230, (l * 2) * (plane->getSize().x / 6.07) + (plane->getSize().x / 6.07), 100 + ((k * 2) * (plane->getSize().y / 13.5) + (plane->getSize().y / 13.5)), 0.4, 0.4));
		selectusertext.push_back(new texter("Inter.ttf", data[i]->getid(), (plane->getSize().x / 4.669230769230) / 4.333333333, 0, 0, 0, 255, (l * 2) * (plane->getSize().x / 6.07) + (plane->getSize().x / 6.07), ((plane->getSize().x / 4.669230769230) / 2) + 100 + ((k * 2) * (plane->getSize().y / 13.5) + (plane->getSize().y / 13.5))));
		l++;
		if (l == 3) {
			l = 0;
			k++;
		}
	}
	selectuserdata.push_back(new button("add.png", plane->getSize().x / 5.0583333333, plane->getSize().x / 5.0583333333, plane->getSize().x / 2, plane->getSize().y * 17 / 20, 0.08, 0.08));

	//posts
	feedtext.push_back(new texter("Jerse.ttf", "Posts", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 25));
	feedtext.push_back(new texter("Inter.ttf", "Comments : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 6, plane->getSize().y / 2));
	feedtext.push_back(new texter("Inter.ttf", "Likers : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x *0.9, plane->getSize().y / 2));
	feeddata.push_back(new button("like.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6, 1.8, 1.8));
	feeddata.push_back(new button("comment.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 1.8, 1.8));

	//home
	hometext.push_back(new texter("Jerse.ttf", "Home Page", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 25));
	hometext.push_back(new texter("Inter.ttf", "Comments : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 6, plane->getSize().y / 2));
	hometext.push_back(new texter("Inter.ttf", "Likers : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x * 0.9, plane->getSize().y / 2));
	homedata.push_back(new button("add.png", plane->getSize().x / 5.0583333333, plane->getSize().x / 5.0583333333, plane->getSize().x / 2, plane->getSize().y * 17 / 20, 0.08, 0.08));




	/*if (currentuser != nullptr) {
		for (int i = 0; i < currentuser->getnooffriends(); i++) {
			for (int j = 0; j < (currentuser->getfriends()[i])->getnoofposts(); j++) {
				std::vector<texter*>* v1=new std::vector<texter*>;
				v1->push_back(new texter("Inter.ttf", (currentuser->getfriends()[i])->getname(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 10));
				v1->push_back(new texter("Inter.ttf", (currentuser->getfriends()[i])->getposttext(j), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 7));
				for (int k = 0; k < (currentuser->getfriends()[oned])->getpost(twod)->getnoofcomments(); k++) {
					v1->push_back( new texter ("Inter.ttf", (currentuser->getfriends()[i])->getpost(j)->getcomment(k)->getusername(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, i * 50 + 50 + plane->getSize().y / 2));
					v1->push_back(new texter("Inter.ttf", (currentuser->getfriends()[i])->getpost(j)->getcomment(k)->gettext(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, i * 50 + 75 + plane->getSize().y / 2));
				}
				feedtextperuser.push_back(v1);

			}
		}
	}
	*/


	std::cout << "Graphics completely loaded" << std::endl << std::endl;
}

int gui::phase = 0;
bool gui::tbphase = 0;
int gui::oned = 0;
int gui::twod = 0;
user* gui::currentuser = nullptr;

void gui :: setcurrentuser(user* a) {
	currentuser = a;
}

void gui::loaddata(std::vector<user*>& data) {

	std::cout << "Initializing and loading User Data" << std::endl << std::endl;

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
	int y;
	std::string pth;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < data[i]->getnoofposts(); j++) {
			file >> p;
			file.ignore();
			std::getline(file, o);
			file >> z;
			file >> pth;
			file >> y;
			data[i]->addpost(p, o, z, pth,y);
			for (int k = 0; k < y; k++) {
				file.ignore();
				std::getline(file, p);
				//file.ignore();
				std::getline(file, o);
				data[i]->getpost(j)->addcomment(p, o);
			}
			int r;
			file >> r;
			data[i]->getpost(j)->setnooflikes(r);
			for (int t = 0; t < data[i]->getpost(j)->getnooflikes(); t++) {
				std::string w;
				file >> w;
				for (int q = 0; q < data[0]->getnoofusers(); q++) {
					if (w == data[q]->getid()) {
						data[i]->getpost(j)->addliker(data[q]);
					}
				}
			}

		}
	}
	file.close();

	std::cout << "User Data completely loaded" << std::endl << std::endl;
	//std::cout<<data[1]->getpost(0)->getcomment(0)->gettext();
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

void gui::feed(sf::RenderWindow* plane, sf::Event* event, std::vector<button*>feeddata, std::vector<texter*> feedtext,char* text) {
	plane->clear(sf::Color::White);
	if (currentuser->getnooffriends() > 0) {
		bool check = 0;
		for (int i = 0; i < currentuser->getnooffriends(); i++) {
			if ((currentuser->getfriends()[i])->getnoofposts() > 0) {
				check = 1;
				break;
			}
			if (i + 1 == currentuser->getnooffriends() || currentuser->getnooffriends() == 0) {
				check = 0;
				//phase = 0;
				break;
				//phase = 0;
			}
		}

		if ((currentuser->getfriends()[oned])->getnoofposts() > 0) {
			check = 1;
		}
		if ((currentuser->getfriends()[oned])->getnoofposts() == 0) {
			check = 0;
			//phase = 0;
		}
		if (currentuser != nullptr) {
			if (event->text.unicode == sf::Keyboard::Tab) {
				twod++;
				check = 0;
			}
			if ((twod == (currentuser->getfriends()[oned])->getnoofposts()) || (currentuser->getfriends()[oned])->getnoofposts() == 0) {
				oned++;
				twod = 0;
				check = 0;
			}
			if (oned == currentuser->getnooffriends()) {
				oned = 0;
				twod = 0;
				check = 0;
			}
			if (check == 1) {


				for (int i = 0; i < feedtext.size(); i++) {
					plane->draw(feedtext[i]->data());
				}
				for (int i = 0; i < feeddata.size(); i++) {
					*feeddata[i] > plane;
					//like button
					if (feeddata[0]->intersect(plane, event)) {
						std::cout << "click" << std::endl;
						bool liked = 0;
						for (int i = 0; i < (currentuser->getfriends()[oned])->getpost(twod)->getlikers().size(); i++) {
							liked = 1;
							if (currentuser->getid() == (currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getid()) {
								(currentuser->getfriends()[oned])->getpost(twod)->removeliker(i);
								
								std::cout << "liker removed" << std::endl;
								break;
							}
						    if (i + 1 == (currentuser->getfriends()[oned])->getpost(twod)->getlikers().size()) {
								std::cout << "liker added" << std::endl;
								(currentuser->getfriends()[oned])->getpost(twod)->addliker(currentuser);
								(currentuser->getfriends()[oned])->getpost(twod)->setnooflikes((currentuser->getfriends()[oned])->getpost(twod)->getlikers().size());
								break;
								

							}
						}
						// dont this check function but seems important
						if (liked==0) {
							//liked = 0;
							std::cout << "liker added" << std::endl;
							(currentuser->getfriends()[oned])->getpost(twod)->addliker(currentuser);
							(currentuser->getfriends()[oned])->getpost(twod)->setnooflikes((currentuser->getfriends()[oned])->getpost(twod)->getlikers().size());
						}

					}
					if (feeddata[1]->intersect(plane, event)) {
						std::cout << "click" << std::endl;
						for (int i = 0; i < (currentuser->getfriends()[oned])->getpost(twod)->getcomments().size(); i++) {
							if (currentuser->getname() == (currentuser->getfriends()[oned])->getpost(twod)->getcomments()[i]->getusername()) {
								std::cout << "Already commented" << std::endl;
								break;
							}
							if (i + 1 == (currentuser->getfriends()[oned])->getpost(twod)->getcomments().size()) {
								for (int i = 0; i < 50; i++) {
									text[i] = '\0';
								}
								phase = 10;
								break;
							}
						}
						//dont know function
						//please check and help
						if ((currentuser->getfriends()[oned])->getpost(twod)->getcomments().size() == 0) {
							std::cout << "commenter added" << std::endl;
							for (int i = 0; i < 50; i++) {
								text[i] = '\0';
							}
							phase = 10;
						}

					}


					//post
					texter ids("Inter.ttf", (currentuser->getfriends()[oned])->getname(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 10);
					texter lel("Inter.ttf", (currentuser->getfriends()[oned])->getposttext(twod), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 7);
					plane->draw(ids.data());
					plane->draw(lel.data());

					//pictures
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
				}
					//comments
					for (int i = 0; i < (currentuser->getfriends()[oned])->getpost(twod)->getnoofcomments(); i++) {

						
						std::string f = (currentuser->getfriends()[oned])->getpost(twod)->getcomment(i)->getusername();
						std::string h = " : ";
						std::string l = (currentuser->getfriends()[oned])->getpost(twod)->getcomment(i)->gettext();
						f+= h;
						f += l;
						texter cmt("Inter.ttf",f, plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x / 3, i * 25 + 50 + plane->getSize().y / 2);
						plane->draw(cmt.data());
					}

					//likes
					for (int i = 0; i < (currentuser->getfriends()[oned])->getpost(twod)->getnooflikes(); i++) {
						texter like("Inter.ttf", (currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getname(), plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x *0.85, i * 25 + 50 + plane->getSize().y / 2);
						plane->draw(like.data());
						//(currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getname();
					}
				}

			}
		}




		//if you are looking to return that is
		if (event->text.unicode == sf::Keyboard::Escape) {
			phase = 0;
			oned = 0;
			twod = 0;
		}
	}

void gui::home(sf::RenderWindow* plane, sf::Event* event, std::vector<button*> homedata, std::vector<texter*> hometext , char*text) {
	plane->clear(sf::Color::White);
	for (int i = 0; i < hometext.size(); i++) {
		plane->draw(hometext[i]->data());
	}
	for (int i = 0; i < homedata.size(); i++) {
		*homedata[i] > plane;
		if (homedata[0]->intersect(plane, event)) {
			for (int i = 0; i < 50; i++) {
				text[i] = '\0';
			}
			phase = 11;
			std::cout << "test complete";
		}
	}

	bool check = 0;
	if (currentuser->getnoofposts() > 0) {
		check = 1;
	}
	if (currentuser->getnoofposts() == 0) {
		check = 0;
		//phase = 0;
	}
	
	if (currentuser != nullptr) {
		if (event->text.unicode == sf::Keyboard::Tab) {
			oned++;
			check = 0;
		}
		if (oned == (currentuser->getnoofposts()) || (currentuser->getnoofposts() == 0)) {
			oned = 0;
			check = 0;
		}
		if (check == 1) {
			//post details
			texter ids("Inter.ttf", currentuser->getname(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 10);
			texter lel("Inter.ttf", currentuser->getposttext(oned), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 7);
			plane->draw(ids.data());
			plane->draw(lel.data());

			//pictures
			sf::Texture texture;
			std::string a = "Resources\\Images\\";
			std::string b = currentuser->getpostpicpath(oned);
			a += b;
			texture.loadFromFile(a);
			sf::Sprite sprite;
			sprite.setTexture(texture);
			sf::FloatRect coords = sprite.getLocalBounds();
			sprite.setOrigin(coords.width / 2, coords.height / 2);
			sprite.setOrigin(150, 150);
			sprite.setPosition(plane->getSize().x / 2, plane->getSize().y / 3);
			plane->draw(sprite);


			//comments
			for (int i = 0; i < currentuser->getpost(oned)->getcomments().size(); i++) {


				std::string f = currentuser->getpost(oned)->getcomment(i)->getusername();
				std::string h = " : ";
				std::string l = currentuser->getpost(oned)->getcomment(i)->gettext();
				f += h;
				f += l;
				texter cmt("Inter.ttf", f, plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x / 3, i * 25 + 50 + plane->getSize().y / 2);
				plane->draw(cmt.data());
			}

			//likes
			for (int i = 0; i < currentuser->getpost(oned)->getlikers().size(); i++) {
				texter like("Inter.ttf", currentuser->getpost(oned)->getlikers()[i]->getname(), plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x * 0.85, i * 25 + 50 + plane->getSize().y / 2);
				plane->draw(like.data());
				//(currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getname();
			}
		}
		
	}
	if (event->text.unicode == sf::Keyboard::Escape) {
		phase = 0;
		oned = 0;
		twod = 0;
	}
	}

void gui::releasedata(std::vector<user*> data) {
	std::cout << "Saving User Data" << std::endl << std::endl;
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
			file << data[i]->getposts()[j]->getnoofcomments() << std::endl;
			for (int k = 0; k < data[i]->getposts()[j]->getcomments().size(); k++) {
				file << data[i]->getpost(j)->getcomment(k)->getusername() << std::endl;
				file << data[i]->getpost(j)->getcomment(k)->gettext() << std::endl;
			}
			file << data[i]->getpost(j)->getnooflikes() << std::endl;
			for (int q = 0; q < data[i]->getpost(j)->getlikers().size(); q++) {
				file << data[i]->getpost(j)->getlikers()[q]->getid() << std::endl;
			}
			file << std::endl;

		}
	}
	file.close();

	std::cout << "User Data completely saved" << std::endl << std::endl;
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

void gui::newcomment(sf::RenderWindow* plane, sf::Event* event, char* text,std::string& c) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter Comment", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		c = text;
		(currentuser->getfriends()[oned])->getpost(twod)->addcomment(currentuser->getname(),c);
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
	texter writer("Inter.ttf", lol, plane->getSize().x/15, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 2);
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
			currentuser->addpost(d,e);
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

void gui::searchfriend(sf::RenderWindow* plane, sf::Event* event, std::vector<user*>& data, char* text, std::string& f) {
	plane->clear(sf::Color::White);
	texter enter("Inter.ttf", "Enter User ID", 75, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 5);
	plane->draw(enter.data());
	button textbox("textbox.png", 350, 100, plane->getSize().x / 2, plane->getSize().y / 2, 3.3, 2.5);
	if (textbox.write(plane, event, text)) {
		f= text;
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



#endif



