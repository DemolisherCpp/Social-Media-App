#include <iostream>
//#include <Drawer.h>
#include <SFML/Graphics.hpp>

class texter {
	sf::Text* text;
	sf::Font* font;
public:
	texter(std::string,std::string);
	~texter();
	sf::Text data();

};

texter::texter(std::string addpath = "Jersey Sharp.ttf",std::string message = "No Name") {
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

}

texter::~texter() {
	delete text;
	delete font;
}

sf::Text texter:: data() {
	return *text;
}



int main() {
	//std::cout << sf::VideoMode::getDesktopMode().width;
	//std::cout << sf::VideoMode::getDesktopMode().height;
	//std::cout << 0.5625 * sf::VideoMode::getDesktopMode().height;


	//test area


	sf::RenderWindow Application(sf::VideoMode(0.5625 * sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().height), "Omernator", sf::Style::Titlebar | sf::Style::Close);


	while (Application.isOpen()) {
		sf::Event Platform;
		while (Application.pollEvent(Platform)) {
			if (Platform.type == Platform.Closed) {
				Application.close();
			}
		}


		//Application.clear();
		texter test;
		Application.draw(test.data());
		Application.display();
		//std::cout << "test";

	}

}





