#include<iostream>
#include<Drawer.h>
#include <SFML/Graphics.hpp>

void mainmenu(sf::RenderWindow* plane, sf::Event* event) {
	//drawings
	button userbutton("user.png", plane->getSize().y / 14.4, plane->getSize().y / 14.4, plane->getSize().x - ((plane->getSize().y / 14.4) / 2), 0 + ((plane->getSize().y / 14.4) / 2));
	userbutton > plane;
	userbutton.intersect(plane, event);


	//functions



}
