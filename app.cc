#include "app.h"

void app::update(){

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		++MouseLeft;
	}else{
		MouseLeft = 0;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		++MouseRight;
	}else{
		MouseRight = 0;	
	}
	sf::Event event;
	
	for(auto& window:windows){
		while(window.second->pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.second->close();
				--wins;
			}
			else if(event.type==sf::Event::MouseMoved){
				PressedKeys[window.first]->x=event.mouseMove.x;
				PressedKeys[window.first]->y=event.mouseMove.y;
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button==sf::Mouse::Right)++PressedKeys[window.first]->mouse[(int)mouseButton::RIGHT];
				else if(event.mouseButton.button==sf::Mouse::Left)++PressedKeys[window.first]->mouse[(int)mouseButton::LEFT];
				else if(event.mouseButton.button==sf::Mouse::Middle)++PressedKeys[window.first]->mouse[(int)mouseButton::MIDDLE];
			}
			else if(event.type == sf::Event::MouseButtonReleased){
				if(event.mouseButton.button==sf::Mouse::Right)PressedKeys[window.first]->mouse[(int)mouseButton::RIGHT]=0;
				else if(event.mouseButton.button==sf::Mouse::Left)PressedKeys[window.first]->mouse[(int)mouseButton::LEFT]=0;
				else if(event.mouseButton.button==sf::Mouse::Middle)PressedKeys[window.first]->mouse[(int)mouseButton::MIDDLE]=0;
			}
			else if(event.type==sf::Event::KeyPressed){
				if(event.key.code==sf::Keyboard::A)++PressedKeys[window.first]->keys[(int)keyIDs::A];
				else if(event.key.code==sf::Keyboard::B)++PressedKeys[window.first]->keys[(int)keyIDs::B];
				else if(event.key.code==sf::Keyboard::C)++PressedKeys[window.first]->keys[(int)keyIDs::C];
				else if(event.key.code==sf::Keyboard::D)++PressedKeys[window.first]->keys[(int)keyIDs::D];
				else if(event.key.code==sf::Keyboard::E)++PressedKeys[window.first]->keys[(int)keyIDs::E];
				else if(event.key.code==sf::Keyboard::F)++PressedKeys[window.first]->keys[(int)keyIDs::F];
				else if(event.key.code==sf::Keyboard::G)++PressedKeys[window.first]->keys[(int)keyIDs::G];
				else if(event.key.code==sf::Keyboard::H)++PressedKeys[window.first]->keys[(int)keyIDs::H];
				else if(event.key.code==sf::Keyboard::I)++PressedKeys[window.first]->keys[(int)keyIDs::I];
				else if(event.key.code==sf::Keyboard::J)++PressedKeys[window.first]->keys[(int)keyIDs::J];
				else if(event.key.code==sf::Keyboard::K)++PressedKeys[window.first]->keys[(int)keyIDs::K];
				else if(event.key.code==sf::Keyboard::L)++PressedKeys[window.first]->keys[(int)keyIDs::L];
				else if(event.key.code==sf::Keyboard::M)++PressedKeys[window.first]->keys[(int)keyIDs::M];
				else if(event.key.code==sf::Keyboard::N)++PressedKeys[window.first]->keys[(int)keyIDs::N];
				else if(event.key.code==sf::Keyboard::O)++PressedKeys[window.first]->keys[(int)keyIDs::O];
				else if(event.key.code==sf::Keyboard::P)++PressedKeys[window.first]->keys[(int)keyIDs::P];
				else if(event.key.code==sf::Keyboard::Q)++PressedKeys[window.first]->keys[(int)keyIDs::Q];
				else if(event.key.code==sf::Keyboard::R)++PressedKeys[window.first]->keys[(int)keyIDs::R];
				else if(event.key.code==sf::Keyboard::S)++PressedKeys[window.first]->keys[(int)keyIDs::S];
				else if(event.key.code==sf::Keyboard::T)++PressedKeys[window.first]->keys[(int)keyIDs::T];
				else if(event.key.code==sf::Keyboard::U)++PressedKeys[window.first]->keys[(int)keyIDs::U];
				else if(event.key.code==sf::Keyboard::V)++PressedKeys[window.first]->keys[(int)keyIDs::V];
				else if(event.key.code==sf::Keyboard::W)++PressedKeys[window.first]->keys[(int)keyIDs::W];
				else if(event.key.code==sf::Keyboard::X)++PressedKeys[window.first]->keys[(int)keyIDs::X];
				else if(event.key.code==sf::Keyboard::Y)++PressedKeys[window.first]->keys[(int)keyIDs::Y];
				else if(event.key.code==sf::Keyboard::Z)++PressedKeys[window.first]->keys[(int)keyIDs::Z];
				else if(event.key.code==sf::Keyboard::Num0)++PressedKeys[window.first]->keys[(int)keyIDs::NUM0];
				else if(event.key.code==sf::Keyboard::Num1)++PressedKeys[window.first]->keys[(int)keyIDs::NUM1];
				else if(event.key.code==sf::Keyboard::Num2)++PressedKeys[window.first]->keys[(int)keyIDs::NUM2];
				else if(event.key.code==sf::Keyboard::Num3)++PressedKeys[window.first]->keys[(int)keyIDs::NUM3];
				else if(event.key.code==sf::Keyboard::Num4)++PressedKeys[window.first]->keys[(int)keyIDs::NUM4];
				else if(event.key.code==sf::Keyboard::Num5)++PressedKeys[window.first]->keys[(int)keyIDs::NUM5];
				else if(event.key.code==sf::Keyboard::Num6)++PressedKeys[window.first]->keys[(int)keyIDs::NUM6];
				else if(event.key.code==sf::Keyboard::Num7)++PressedKeys[window.first]->keys[(int)keyIDs::NUM7];
				else if(event.key.code==sf::Keyboard::Num8)++PressedKeys[window.first]->keys[(int)keyIDs::NUM8];
				else if(event.key.code==sf::Keyboard::Num9)++PressedKeys[window.first]->keys[(int)keyIDs::NUM9];
				else if(event.key.code==sf::Keyboard::LControl)++PressedKeys[window.first]->keys[(int)keyIDs::LCTRL];
				else if(event.key.code==sf::Keyboard::RControl)++PressedKeys[window.first]->keys[(int)keyIDs::RCTRL];
				else if(event.key.code==sf::Keyboard::LShift)++PressedKeys[window.first]->keys[(int)keyIDs::LSHIFT];
				else if(event.key.code==sf::Keyboard::RShift)++PressedKeys[window.first]->keys[(int)keyIDs::RSHIFT];
			}
			else if(event.type==sf::Event::KeyReleased){
				if(event.key.code==sf::Keyboard::A)PressedKeys[window.first]->keys[(int)keyIDs::A]=0;
				else if(event.key.code==sf::Keyboard::B)PressedKeys[window.first]->keys[(int)keyIDs::B]=0;
				else if(event.key.code==sf::Keyboard::C)PressedKeys[window.first]->keys[(int)keyIDs::C]=0;
				else if(event.key.code==sf::Keyboard::D)PressedKeys[window.first]->keys[(int)keyIDs::D]=0;
				else if(event.key.code==sf::Keyboard::E)PressedKeys[window.first]->keys[(int)keyIDs::E]=0;
				else if(event.key.code==sf::Keyboard::F)PressedKeys[window.first]->keys[(int)keyIDs::F]=0;
				else if(event.key.code==sf::Keyboard::G)PressedKeys[window.first]->keys[(int)keyIDs::G]=0;
				else if(event.key.code==sf::Keyboard::H)PressedKeys[window.first]->keys[(int)keyIDs::H]=0;
				else if(event.key.code==sf::Keyboard::I)PressedKeys[window.first]->keys[(int)keyIDs::I]=0;
				else if(event.key.code==sf::Keyboard::J)PressedKeys[window.first]->keys[(int)keyIDs::J]=0;
				else if(event.key.code==sf::Keyboard::K)PressedKeys[window.first]->keys[(int)keyIDs::K]=0;
				else if(event.key.code==sf::Keyboard::L)PressedKeys[window.first]->keys[(int)keyIDs::L]=0;
				else if(event.key.code==sf::Keyboard::M)PressedKeys[window.first]->keys[(int)keyIDs::M]=0;
				else if(event.key.code==sf::Keyboard::N)PressedKeys[window.first]->keys[(int)keyIDs::N]=0;
				else if(event.key.code==sf::Keyboard::O)PressedKeys[window.first]->keys[(int)keyIDs::O]=0;
				else if(event.key.code==sf::Keyboard::P)PressedKeys[window.first]->keys[(int)keyIDs::P]=0;
				else if(event.key.code==sf::Keyboard::Q)PressedKeys[window.first]->keys[(int)keyIDs::Q]=0;
				else if(event.key.code==sf::Keyboard::R)PressedKeys[window.first]->keys[(int)keyIDs::R]=0;
				else if(event.key.code==sf::Keyboard::S)PressedKeys[window.first]->keys[(int)keyIDs::S]=0;
				else if(event.key.code==sf::Keyboard::T)PressedKeys[window.first]->keys[(int)keyIDs::T]=0;
				else if(event.key.code==sf::Keyboard::U)PressedKeys[window.first]->keys[(int)keyIDs::U]=0;
				else if(event.key.code==sf::Keyboard::V)PressedKeys[window.first]->keys[(int)keyIDs::V]=0;
				else if(event.key.code==sf::Keyboard::W)PressedKeys[window.first]->keys[(int)keyIDs::W]=0;
				else if(event.key.code==sf::Keyboard::X)PressedKeys[window.first]->keys[(int)keyIDs::X]=0;
				else if(event.key.code==sf::Keyboard::Y)PressedKeys[window.first]->keys[(int)keyIDs::Y]=0;
				else if(event.key.code==sf::Keyboard::Z)PressedKeys[window.first]->keys[(int)keyIDs::Z]=0;
				else if(event.key.code==sf::Keyboard::Num0)PressedKeys[window.first]->keys[(int)keyIDs::NUM0]=0;
				else if(event.key.code==sf::Keyboard::Num1)PressedKeys[window.first]->keys[(int)keyIDs::NUM1]=0;
				else if(event.key.code==sf::Keyboard::Num2)PressedKeys[window.first]->keys[(int)keyIDs::NUM2]=0;
				else if(event.key.code==sf::Keyboard::Num3)PressedKeys[window.first]->keys[(int)keyIDs::NUM3]=0;
				else if(event.key.code==sf::Keyboard::Num4)PressedKeys[window.first]->keys[(int)keyIDs::NUM4]=0;
				else if(event.key.code==sf::Keyboard::Num5)PressedKeys[window.first]->keys[(int)keyIDs::NUM5]=0;
				else if(event.key.code==sf::Keyboard::Num6)PressedKeys[window.first]->keys[(int)keyIDs::NUM6]=0;
				else if(event.key.code==sf::Keyboard::Num7)PressedKeys[window.first]->keys[(int)keyIDs::NUM7]=0;
				else if(event.key.code==sf::Keyboard::Num8)PressedKeys[window.first]->keys[(int)keyIDs::NUM8]=0;
				else if(event.key.code==sf::Keyboard::Num9)PressedKeys[window.first]->keys[(int)keyIDs::NUM9]=0;
				else if(event.key.code==sf::Keyboard::LControl)PressedKeys[window.first]->keys[(int)keyIDs::LCTRL]=0;
				else if(event.key.code==sf::Keyboard::RControl)PressedKeys[window.first]->keys[(int)keyIDs::RCTRL]=0;
				else if(event.key.code==sf::Keyboard::LShift)PressedKeys[window.first]->keys[(int)keyIDs::LSHIFT]=0;
				else if(event.key.code==sf::Keyboard::RShift)PressedKeys[window.first]->keys[(int)keyIDs::RSHIFT]=0;
			}
		}
	}
}
void app::run(){
update();
}
void app::newWindow(const std::string &st,const int &x,const int &y){
	windows[st]=std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(x, y),st));
	PressedKeys[st]=std::unique_ptr<inputManager>(new inputManager());
	windows[st]->setFramerateLimit(60);
	m_winNames.push_back(st);
	++wins;
}
const sf::Texture& app::getTexture(const std::string& fileName){
	auto it = m_textures.find(fileName);
	if(it==m_textures.end()){
		m_textures[fileName]=std::unique_ptr<sf::Texture>(new sf::Texture);
		m_textures[fileName]->loadFromFile(fileName);
	}return *m_textures[fileName];
}
sf::Font& app::getFont(const std::string& fontName){
	auto it = m_fonts.find(fontName);
	if(it==m_fonts.end()){
		m_fonts[fontName]=std::unique_ptr<sf::Font>(new sf::Font);
		m_fonts[fontName]->loadFromFile(fontName);
	}return *m_fonts[fontName];
}
app::app(){
//sf::RenderWindow* window;
//window = new sf::RenderWindow(sf::VideoMode(700, 700), "SFML works!");

}
app::~app(){
//delete window;
//for(unsigned int x =0;x<m_winNames.size();++x)
//delete windows[window.first];
}
