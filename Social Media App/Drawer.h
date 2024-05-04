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

}

texter::~texter() {
	delete text;
	delete font;
}

sf::Text texter::data() {
	return *text;
}

class button {
	sf::RectangleShape body;
	texter function;
public:
	void draw(sf::RenderWindow*);
};

void button::draw(sf::RenderWindow* place) {
	place->draw(body);
	place->draw(function.data());

}