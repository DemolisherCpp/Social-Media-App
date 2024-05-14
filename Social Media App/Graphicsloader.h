#ifndef GRAPHICSLOADER_H
#define GRAPHICSLOADER_H

#include<iostream>
#include<Gui.h>


void gui::loadstats(std::vector<user*> data, sf::RenderWindow* plane, std::vector<button*>& menudata, std::vector<texter*>& menutext, std::vector<button*>& selectuserdata, std::vector<texter*>& selectusertext, std::vector<button*>& feeddata, std::vector<texter*>& feedtext, std::vector<button*>& homedata, std::vector<texter*>& hometext, std::vector<button*>& pagefeeddata, std::vector<texter*>& pagefeedtext) {

	std::cout << "Initializing and loading Graphics" << std::endl << std::endl;

	//main mennu
	menudata.push_back(new button("user.png", plane->getSize().y / 14.4, plane->getSize().y / 14.4, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), 0 + ((plane->getSize().y / 14.4) / 2)));
	menudata.push_back(new button("friends.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6, 0.03, 0.03));
	menudata.push_back(new button("Post.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 0.15, 0.15));
	menudata.push_back(new button("home.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.16, 1.5, 1.5));
	menudata.push_back(new button("addfriend.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x * 0.92, plane->getSize().y / 3.6, 0.75, 0.75));
	menudata.push_back(new button("addpage.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x * 0.92, plane->getSize().y / 2.7, 0.75, 0.75));
	menudata.push_back(new button("page.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x * 0.92, plane->getSize().y / 2.16, 0.75, 0.75));
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
	feedtext.push_back(new texter("Inter.ttf", "Likers : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x * 0.9, plane->getSize().y / 2));
	feeddata.push_back(new button("like.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6, 1.8, 1.8));
	feeddata.push_back(new button("comment.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 1.8, 1.8));

	//home
	hometext.push_back(new texter("Jerse.ttf", "Home Page", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 25));
	hometext.push_back(new texter("Inter.ttf", "Comments : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 6, plane->getSize().y / 2));
	hometext.push_back(new texter("Inter.ttf", "Likers : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x * 0.9, plane->getSize().y / 2));
	homedata.push_back(new button("add.png", plane->getSize().x / 5.0583333333, plane->getSize().x / 5.0583333333, plane->getSize().x / 2, plane->getSize().y * 17 / 20, 0.08, 0.08));

	//pages
	pagefeedtext.push_back(new texter("Jerse.ttf", "Pages", plane->getSize().x / 10.116666666, 0, 0, 0, 255, plane->getSize().x / 2, plane->getSize().y / 25));
	pagefeedtext.push_back(new texter("Inter.ttf", "Comments : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x / 6, plane->getSize().y / 2));
	pagefeedtext.push_back(new texter("Inter.ttf", "Likers : ", plane->getSize().x / 20, 0, 0, 0, 255, plane->getSize().x * 0.9, plane->getSize().y / 2));
	pagefeeddata.push_back(new button("like.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 3.6, 1.8, 1.8));
	pagefeeddata.push_back(new button("comment.png", plane->getSize().x / 6.07, plane->getSize().x / 6.07, plane->getSize().x / 12.14, plane->getSize().y / 2.7, 1.8, 1.8));
	std::cout << "Graphics completely loaded" << std::endl << std::endl;
}


#endif