#ifndef GUIFILEHANDLERS_H
#define GUIFILEHANDLERS_H


#include<iostream>
#include<Gui.h>

void gui::loaddata(std::vector<user*>& data, std::vector<page*>& server) {

	//users
	std::cout << "Initializing and loading User Data" << std::endl << std::endl;

	std::ifstream sata;
	sata.open("users.txt");
	user dummy;
	int a;
	int b;
	int e;
	sata >> a;
	dummy.setnoofusers(a);
	//users
	for (int i = 0; i < a; i++) {
		std::string c;
		std::string d;
		sata >> c;
		sata.ignore();
		std::getline(sata, d);
		sata >> b;
		sata >> e;
		data.push_back(new user(c, d, b, e));
		int r;
		sata >> r;
		data[i]->setnooffollowedpages(r);
	}

	//pages

	{
		std::cout << "Initializing and loading Page Data" << std::endl << std::endl;

		std::ifstream file;
		file.open("pages.txt");
		page dummy;
		int a;
		file >> a;
		dummy.setnoofpages(a);
		//pages
		for (int i = 0; i < a; i++) {
			std::string b;
			std::string c;
			int d;
			file >> b;
			file.ignore();
			std::getline(file, c);
			file >> d;
			server.push_back(new page(b, c, d));
		}
		//posts
		std::string e;
		std::string f;
		int v;
		int w;
		std::string pth;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < server[i]->getnoofposts(); j++) {
				file >> e;
				file.ignore();
				std::getline(file, f);
				file >> v;
				file >> pth;
				file >> w;
				server[i]->addpost(e, f, v, pth, w);
				for (int k = 0; k < w; k++) {
					std::string l;
					std::string m;
					file.ignore();
					std::getline(file, l);
					//file.ignore();
					std::getline(file, m);
					server[i]->getpost(j)->addcomment(l, m);
				}
				int u;
				file >> u;
				server[i]->getpost(j)->setnooflikes(u);
				for (int t = 0; t < server[i]->getpost(j)->getnooflikes(); t++) {
					std::string w;
					file >> w;
					for (int q = 0; q < data[0]->getnoofusers(); q++) {
						if (w == data[q]->getid()) {
							server[i]->getpost(j)->addliker(data[q]);
						}
					}
				}


			}
		}
		file.close();
		std::cout << "Page Data completely loaded" << std::endl << std::endl;
	}
	{

		//friends
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < data[i]->getnooffriends(); j++) {
				std::string f;
				sata >> f;
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
				sata >> p;
				sata.ignore();
				std::getline(sata, o);
				sata >> z;
				sata >> pth;
				sata >> y;
				data[i]->addpost(p, o, z, pth, y);
				for (int k = 0; k < y; k++) {
					sata.ignore();
					std::getline(sata, p);
					//sata.ignore();
					std::getline(sata, o);
					data[i]->getpost(j)->addcomment(p, o);
				}
				int r;
				sata >> r;
				data[i]->getpost(j)->setnooflikes(r);
				for (int t = 0; t < data[i]->getpost(j)->getnooflikes(); t++) {
					std::string w;
					sata >> w;
					for (int q = 0; q < data[0]->getnoofusers(); q++) {
						if (w == data[q]->getid()) {
							data[i]->getpost(j)->addliker(data[q]);
						}
					}
				}

			}
		}
		//pages
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < data[i]->getnooffollowedpages(); j++) {
				std::string h;
				sata >> h;
				for (int k = 0; k < server.size(); k++) {
					if (h == server[k]->getid()) {
						data[i]->addpage(server[k]);
					}
				}
			}
		}
		sata.close();

		std::cout << "User Data completely loaded" << std::endl << std::endl;
		//std::cout<<data[1]->getpost(0)->getcomment(0)->gettext();
	}


}

void gui::releasedata(std::vector<user*> data, std::vector<page*>& server) {

	//users
	{
		std::cout << "Saving User Data" << std::endl << std::endl;
		std::ofstream file;
		file.open("users.txt", std::ofstream::trunc);
		file << data[0]->getnoofusers();
		file << std::endl << std::endl;
		for (int i = 0; i < data[0]->getnoofusers(); i++) {
			file << data[i]->getid() << std::endl;
			file << data[i]->getname() << std::endl;
			file << data[i]->getnooffriends() << std::endl;
			file << data[i]->getnoofposts() << std::endl;
			file << data[i]->getnooffollowedpages() << std::endl << std::endl;
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


		for (int i = 0; i < data[0]->getnoofusers(); i++) {
			for (int j = 0; j < data[i]->getnooffollowedpages(); j++) {
				file << data[i]->getfollowedpages()[j]->getid() << std::endl;
			}
		}
		file.close();

		std::cout << "User Data completely saved" << std::endl << std::endl;
	}

	//pages
	{
		//pages
		std::ofstream file;
		file.open("pages.txt", std::ofstream::trunc);
		file << server[0]->getnoofpages() << std::endl << std::endl;
		for (int i = 0; i < server[0]->getnoofpages(); i++) {
			file << server[i]->getid() << std::endl;
			file << server[i]->getname() << std::endl;
			file << server[i]->getnoofposts() << std::endl << std::endl;
		}
		//posts
		for (int i = 0; i < server[0]->getnoofpages(); i++) {
			for (int j = 0; j < server[i]->getnoofposts(); j++) {
				file << server[i]->getpostid(j) << std::endl;
				file << server[i]->getposttext(j) << std::endl;
				file << server[i]->getpostdate(j) << std::endl;
				file << server[i]->getpostpicpath(j) << std::endl;
				file << server[i]->getposts()[j]->getnoofcomments() << std::endl;
				for (int k = 0; k < server[i]->getposts()[j]->getcomments().size(); k++) {
					file << server[i]->getpost(j)->getcomment(k)->getusername() << std::endl;
					file << server[i]->getpost(j)->getcomment(k)->gettext() << std::endl;
				}
				file << server[i]->getpost(j)->getnooflikes() << std::endl;
				for (int q = 0; q < server[i]->getpost(j)->getnooflikes(); q++) {
					file << server[i]->getpost(j)->getlikers()[q]->getid() << std::endl;
				}
				file << std::endl;
			}
		}
	}
}

#endif

