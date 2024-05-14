#ifndef FEEDS_H
#define FEEDS_H


#include<iostream>
#include<Gui.h>




void gui::feed(sf::RenderWindow* plane, sf::Event* event, std::vector<button*>feeddata, std::vector<texter*> feedtext, char* text) {
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
						if (liked == 0) {
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
					f += h;
					f += l;
					texter cmt("Inter.ttf", f, plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x / 3, i * 25 + 50 + plane->getSize().y / 2);
					plane->draw(cmt.data());
				}

				//likes
				for (int i = 0; i < (currentuser->getfriends()[oned])->getpost(twod)->getnooflikes(); i++) {
					texter like("Inter.ttf", (currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getname(), plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x * 0.85, i * 25 + 50 + plane->getSize().y / 2);
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

void  gui::pagefeed(sf::RenderWindow* plane, sf::Event* event, std::vector<button*> pagefeeddata, std::vector<texter*> pagefeedtext, char* text) {
	plane->clear(sf::Color::White);
	if (currentuser->getnooffollowedpages() > 0) {
		bool check = 0;
		for (int i = 0; i < currentuser->getnooffollowedpages(); i++) {
			if ((currentuser->getfollowedpages()[i])->getnoofposts() > 0) {
				check = 1;
				break;
			}
			if (i + 1 == currentuser->getnooffollowedpages() || currentuser->getnooffollowedpages() == 0) {
				check = 0;
				//phase = 0;
				break;
				//phase = 0;
			}
		}

		if ((currentuser->getfollowedpages()[oned])->getnoofposts() > 0) {
			check = 1;
		}
		if ((currentuser->getfollowedpages()[oned])->getnoofposts() == 0) {
			check = 0;
			//phase = 0;
		}
		if (currentuser != nullptr) {
			if (event->text.unicode == sf::Keyboard::Tab) {
				twod++;
				check = 0;
			}
			if ((twod == (currentuser->getfollowedpages()[oned])->getnoofposts()) || (currentuser->getfollowedpages()[oned])->getnoofposts() == 0) {
				oned++;
				twod = 0;
				check = 0;
			}
			if (oned == currentuser->getfollowedpages().size()) {
				oned = 0;
				twod = 0;
				check = 0;
			}
			if (check == 1) {


				for (int i = 0; i < pagefeedtext.size(); i++) {
					plane->draw(pagefeedtext[i]->data());
				}
				for (int i = 0; i < pagefeeddata.size(); i++) {
					*pagefeeddata[i] > plane;
					//like button
					if (pagefeeddata[0]->intersect(plane, event)) {
						std::cout << "click" << std::endl;
						bool liked = 0;
						for (int i = 0; i < (currentuser->getfollowedpages()[oned])->getpost(twod)->getlikers().size(); i++) {
							liked = 1;
							if (currentuser->getid() == (currentuser->getfollowedpages()[oned])->getpost(twod)->getlikers()[i]->getid()) {
								(currentuser->getfollowedpages()[oned])->getpost(twod)->removeliker(i);

								std::cout << "liker removed" << std::endl;
								break;
							}
							if (i + 1 == (currentuser->getfollowedpages()[oned])->getpost(twod)->getlikers().size()) {
								std::cout << "liker added" << std::endl;
								(currentuser->getfollowedpages()[oned])->getpost(twod)->addliker(currentuser);
								(currentuser->getfollowedpages()[oned])->getpost(twod)->setnooflikes((currentuser->getfriends()[oned])->getpost(twod)->getlikers().size());
								break;


							}
						}
						// dont this check function but seems important
						if (liked == 0) {
							//liked = 0;
							std::cout << "liker added" << std::endl;
							(currentuser->getfollowedpages()[oned])->getpost(twod)->addliker(currentuser);
							(currentuser->getfollowedpages()[oned])->getpost(twod)->setnooflikes((currentuser->getfriends()[oned])->getpost(twod)->getlikers().size());
						}

					}
					if (pagefeeddata[1]->intersect(plane, event)) {
						std::cout << "click" << std::endl;
						for (int i = 0; i < (currentuser->getfollowedpages()[oned])->getpost(twod)->getcomments().size(); i++) {
							if (currentuser->getname() == (currentuser->getfollowedpages()[oned])->getpost(twod)->getcomments()[i]->getusername()) {
								std::cout << "Already commented" << std::endl;
								break;
							}
							if (i + 1 == (currentuser->getfollowedpages()[oned])->getpost(twod)->getcomments().size()) {
								for (int i = 0; i < 50; i++) {
									text[i] = '\0';
								}
								phase = 12;
								break;
							}
						}
						//dont know function
						//please check and help
						if ((currentuser->getfollowedpages()[oned])->getpost(twod)->getcomments().size() == 0) {
							std::cout << "commenter added" << std::endl;
							for (int i = 0; i < 50; i++) {
								text[i] = '\0';
							}
							phase = 12;
						}

					}


					//post
					texter ids("Inter.ttf", (currentuser->getfollowedpages()[oned])->getname(), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 10);
					texter lel("Inter.ttf", (currentuser->getfollowedpages()[oned])->getposttext(twod), plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 7);
					plane->draw(ids.data());
					plane->draw(lel.data());

					//pictures
					sf::Texture texture;
					std::string a = "Resources\\Images\\";
					std::string b = (currentuser->getfollowedpages()[oned])->getpostpicpath(twod);
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
				for (int i = 0; i < (currentuser->getfollowedpages()[oned])->getpost(twod)->getnoofcomments(); i++) {


					std::string f = (currentuser->getfollowedpages()[oned])->getpost(twod)->getcomment(i)->getusername();
					std::string h = " : ";
					std::string l = (currentuser->getfollowedpages()[oned])->getpost(twod)->getcomment(i)->gettext();
					f += h;
					f += l;
					texter cmt("Inter.ttf", f, plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x / 3, i * 25 + 50 + plane->getSize().y / 2);
					plane->draw(cmt.data());
				}

				//likes
				for (int i = 0; i < (currentuser->getfollowedpages()[oned])->getpost(twod)->getlikers().size(); i++) {
					texter like("Inter.ttf", (currentuser->getfollowedpages()[oned])->getpost(twod)->getlikers()[i]->getname(), plane->getSize().x / 40, 0, 0, 0, 255, plane->getSize().x * 0.85, i * 25 + 50 + plane->getSize().y / 2);
					plane->draw(like.data());
					//(currentuser->getfriends()[oned])->getpost(twod)->getlikers()[i]->getname();
				}
			}

		}
	}
	if (event->text.unicode == sf::Keyboard::Escape) {
		phase = 0;
		oned = 0;
		twod = 0;
	}
}

void gui::home(sf::RenderWindow* plane, sf::Event* event, std::vector<button*> homedata, std::vector<texter*> hometext, char* text) {
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


#endif