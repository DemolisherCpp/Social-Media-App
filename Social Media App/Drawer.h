#ifndef DRAWER_H
#define DRAWER_H

#include<iostream>
#include<SFML\Graphics.hpp>

class texter {
	sf::Text* text;
	sf::Font* font;
public:
	texter(std::string, std::string,int,int,int,int,int,float,float);
	~texter();
	sf::Text data();

};

texter::texter(std::string addpath = "Jersey Sharp.ttf", std::string message = "No Name",int size=30,int r=255,int g=255,int b=255,int alpha=255,float x=50,float y=50) {
	std::string path = "Resources\\Fonts\\";
	path += addpath;


	font = new sf::Font;
	if (!font->loadFromFile(path)) {
		std::cout << "The font of one of the texts could not be loaded" << std::endl;
		exit(0);
	}


	text = new sf::Text;
	text->setFont(*font);

	text->setString(message);
	text->setCharacterSize(size);
	text->setFillColor(sf::Color(r,g,b,alpha));
	text->setPosition(sf::Vector2f(x,y));



	sf::FloatRect coords = text->getLocalBounds();
	text->setOrigin(coords.width / 2, coords.height / 2);

}

texter::~texter() {
	delete text;
	delete font;
}

sf::Text texter::data() {
	return *text;
}

class button {
	sf::RectangleShape* body;
	texter function;
	sf::Texture* texture;
	sf::Sprite* face;
public:
	button(std::string,float,float,int,int,float,float);
	~button();
	void intersect(sf::RenderWindow*, sf::Event*);
	void operator > (sf::RenderWindow*);

};

button::button(std :: string addpath = "user.png" ,float xsize=75, float ysize=75,int posx=303.5,int posy=540,float scaleoffacex=0.2,float scaleoffacey=0.2) {
	body = new sf::RectangleShape;
	texture = new sf::Texture;
	face = new sf::Sprite;

	body->setSize(sf::Vector2f(xsize,ysize));
	body->setOrigin(xsize/2,ysize/2);
	body->setPosition(posx, posy);



	std::string path = "Resources\\Images\\";
	path += addpath;
	if (!texture->loadFromFile(path)) {
		std::cout << "The image of one of the faces could not be loaded" << std::endl;
		exit(0);
	}


	face->setTexture(*texture);


	face->setOrigin(face->getLocalBounds().width / 2, face->getLocalBounds().height / 2);
	scaleoffacex = xsize / face->getLocalBounds().width;
	scaleoffacey = ysize / face->getLocalBounds().height;
	face->setScale(scaleoffacex*0.8, scaleoffacey*0.8);
	face->setPosition(posx, posy);


	//text
	//function.data().getFont().loadFromFile("Resources\\Fonts\\Inter.ttf");
	body->getLocalBounds().height - face->getLocalBounds().height / 2;
}

button::~button() {
	delete body;
	delete texture;
	delete face;
}

void button :: operator > (sf::RenderWindow* plane) {
	plane->draw(*body);
	plane->draw(function.data());
	plane->draw(*face);
}

void button::intersect(sf::RenderWindow* plane, sf::Event* event) {
	//if(sf::Mouse::getPosition(*plane).x>(body->getLocalBounds().width+body->))
	if ((sf::Mouse::getPosition(*plane).x > (body->getPosition().x - body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).x < (body->getPosition().x + body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).y > (body->getPosition().y - body->getOrigin().y)) && (sf::Mouse::getPosition(*plane).y < (body->getPosition().y + body->getOrigin().y))) {
		std::cout << "test accomplished";
	}
}


#endif // DRAWER_H
