#ifndef DRAWER_H
#define DRAWER_H

#include<iostream>
#include<SFML\Graphics.hpp>
#include<vector>

class texter {
	sf::Text* text;
	sf::Font* font;
public:
	texter(std::string, std::string,int,int,int,int,int,float,float);
	~texter();
	sf::Text data();
	void setmessage(std::string);
	void setpos(float,float);
	void setsize(int);

};

texter::texter(std::string addpath = "Inter.ttf", std::string message = "No Name", int size = 30, int r = 255, int g = 255, int b = 255, int alpha = 255, float x = 50, float y = 50) {
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

void texter::setmessage(std::string a) {
	text->setString(a);
}

void texter::setpos(float a, float b) {
	text->setPosition(sf::Vector2f(a, b));
}

void texter::setsize(int a) {
	text->setCharacterSize(a);
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
	//texter function;
	sf::Texture* texture;
	sf::Sprite* face;
	static int click;
	static int character;
	//static char* test;
	//static char test[30];
	static bool caps;
public:
	button(std::string,float,float,int,int,float,float);
	~button();
	bool intersect(sf::RenderWindow*, sf::Event*);
	void operator > (sf::RenderWindow*);
	bool write(sf::RenderWindow*, sf::Event*,char*);
	

};

int button::click = 0;
int button::character = 0;
bool button::caps = 0;
//char* button::test = new char[30];

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
	if (scaleoffacex == 0.2 && scaleoffacey == 0.2) {
		scaleoffacex = xsize / face->getLocalBounds().width;
		scaleoffacey = ysize / face->getLocalBounds().height;
	}
	

	face->setScale(scaleoffacex*0.8, scaleoffacey*0.8);
	face->setPosition(posx, posy);


	//text
	//function.setsize(15);
	//sf::FloatRect coords = function.data().getLocalBounds();
	//function.data().setOrigin(coords.width / 2, coords.height / 2);
	//function.setpos(posx, posy + (body->getLocalBounds().height/2)+10);
}

button::~button() {
	delete body;
	delete texture;
	delete face;
}

void button :: operator > (sf::RenderWindow* plane) {
	plane->draw(*body);
	//plane->draw(function.data());
	plane->draw(*face);
	//plane->draw(function.data());
}

bool button::intersect(sf::RenderWindow* plane, sf::Event* event) {
	//if(sf::Mouse::getPosition(*plane).x>(body->getLocalBounds().width+body->))
	if ((sf::Mouse::getPosition(*plane).x > (body->getPosition().x - body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).x < (body->getPosition().x + body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).y > (body->getPosition().y - body->getOrigin().y)) && (sf::Mouse::getPosition(*plane).y < (body->getPosition().y + body->getOrigin().y))) {
		body->setFillColor(sf::Color(255, 0, 0));
		if (sf::Event::MouseButtonPressed && event->key.code == sf::Mouse::Left || (click > 0) && (click < 10)) {
			click++;
			body->setFillColor(sf::Color(255 * click * 10 / 100, 0, 0));
			if (click == 10) {
				return 1;
			}
			else
				return 0;
		}
		else {
			click = 0;
			return 0;
		}
	}
	else
		return 0;
}

bool  button::write (sf::RenderWindow* plane, sf::Event* event,char*text) {
	if ((sf::Mouse::getPosition(*plane).x > (body->getPosition().x - body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).x < (body->getPosition().x + body->getOrigin().x)) && (sf::Mouse::getPosition(*plane).y > (body->getPosition().y - body->getOrigin().y)) && (sf::Mouse::getPosition(*plane).y < (body->getPosition().y + body->getOrigin().y))) {
		body->setFillColor(sf::Color(255, 0, 0));
		if ((sf::Event::MouseButtonPressed && event->key.code == sf::Mouse::Left) || click == 1) {
			click = 1;
		}
	}
	if (click == 1) {
		body->setFillColor(sf::Color(160, 0, 0));
		if (event->key.scancode == sf::Keyboard::A) {
			text[character] = (caps) ? 'A' : 'a';
			character++;
		}
		//std::cout << event->text.unicode;
		switch (event->text.unicode) {
		case sf::Keyboard::Escape:
			//exit
			break;
		    case sf::Keyboard::Enter:
				text[character-1] = '\0';
				character = 0;
				caps = 0;
				click = 0;
				return 1;
			    break;
			case sf::Keyboard::Tab:
				//capital
				caps = !caps;
				break;
			case sf::Keyboard::Tilde:
				//delete
				text[character] = '\0';
				character--;
				break;
			case sf::Keyboard::Space:
				text[character] = ' ';
				character++;
				break;
			case sf::Keyboard::B:
				text[character] = (caps) ? 'B' : 'b';
				character++;
				break;
			case sf::Keyboard::C:
				text[character] = (caps) ? 'C' : 'c';
				character++;
				break;
			case sf::Keyboard::D:
				text[character] = (caps) ? 'D' : 'd';
				character++;
				break;
			case sf::Keyboard::E:
				text[character] = (caps) ? 'E' : 'e';
				character++;
				break;
			case sf::Keyboard::F:
				text[character] = (caps) ? 'F' : 'f';
				character++;
				break;
			case sf::Keyboard::H:
				text[character] = (caps) ? 'H' : 'h';
				character++;
				break;
			case sf::Keyboard::I:
				text[character] = (caps) ? 'I' : 'i';
				character++;
				break;
			case sf::Keyboard::J:
				text[character] = (caps) ? 'J' : 'j';
				character++;
				break;
			case sf::Keyboard::K:
				text[character] = (caps) ? 'K' : 'k';
				character++;
				break;
			case sf::Keyboard::L:
				text[character] = (caps) ? 'L' : 'l';
				character++;
				break;
			case sf::Keyboard::M:
				text[character] = (caps) ? 'M' : 'm';
				character++;
				break;
			case sf::Keyboard::N:
				text[character] = (caps) ? 'N' : 'n';
				character++;
				break;
			case sf::Keyboard::O:
				text[character] = (caps) ? 'O' : 'o';
				character++;
				break;
			case sf::Keyboard::P:
				text[character] = (caps) ? 'P' : 'p';
				character++;
				break;
			case sf::Keyboard::Q:
				text[character] = (caps) ? 'Q' : 'q';
				character++;
				break;
			case sf::Keyboard::R:
				text[character] = (caps) ? 'R' : 'r';
				character++;
				break;
			case sf::Keyboard::S:
				text[character] = (caps) ? 'S' : 's';
				character++;
				break;
			case sf::Keyboard::T:
				text[character] = (caps) ? 'T' : 't';
				character++;
				break;
			case sf::Keyboard::U:
				text[character] = (caps) ? 'U' : 'u';
				character++;
				break;
			case sf::Keyboard::V:
				text[character] = (caps) ? 'V' : 'v';
				character++;
				break;
			case sf::Keyboard::W:
				text[character] = (caps) ? 'W' : 'w';
				character++;
				break;
			case sf::Keyboard::X:
				text[character] = (caps) ? 'X' : 'x';
				character++;
				break;
			case sf::Keyboard::Y:
				text[character] = (caps) ? 'Y' : 'y';
				character++;
				break;
			case sf::Keyboard::Z:
				text[character] = (caps) ? 'Z' : 'z';
				character++;
				break;


			}

	}
	if (click == 0) {
		for (int i = 0; i < 50; i++) {
		text[i] = '\0';
	}
	}
	return 0;
}


#endif // DRAWER_H
