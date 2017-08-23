#ifndef APP_H
#define APP_H
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "inputManager.h"
#include <unordered_map>
inline bool pointInBox(sf::Vector2f a,sf::Vector2f b,float z,float w){
	return a.x>b.x&&a.x<b.x+z&&a.y>b.y&&a.y<b.y+w;
}
inline bool pointInBox(sf::Vector2f a,float width,float height,sf::Vector2f b){
	return a.x<=b.x&&
		   a.y<=b.y&&
		   a.x+width>b.x&&
		   a.y+height>b.y;
}
class app{
	public:
		virtual void update();
		app();
		virtual ~app();
		void newWindow(const std::string &,const int &x,const int &y);

		bool isRunning()const{return wins;};
		virtual void run();
		void quit(){m_running = 0;};
		const sf::Texture& getTexture(const std::string&);
		int getKey(const std::string& window,keyIDs key)const {return PressedKeys.at(window)->getKey(key);};
		sf::Font& getFont(const std::string& fontName);
		int getMouseClick(const std::string& window,mouseButton button)const{
			if(button == mouseButton::LEFT){
				return MouseLeft;
			}return MouseRight;
			const auto it = PressedKeys.find(window);
			if(it!=PressedKeys.end()){
				return it->second->getMouse(button);
			}return 0;
			//return PressedKeys[window]->getMouse(button);
		};
		sf::Vector2f getMouseCoords(const std::string& window) const {
			return sf::Vector2f(PressedKeys.at(window)->x,PressedKeys.at(window)->y);
		};
		std::unordered_map<std::string,std::unique_ptr<sf::RenderWindow> > windows;
	protected:
		
		
	private:
		std::unordered_map<std::string,std::unique_ptr<sf::Texture> > m_textures;
		std::unordered_map<std::string,std::unique_ptr<sf::Font> > m_fonts;

		std::vector<std::string> m_winNames;
		std::unordered_map<std::string,std::unique_ptr<inputManager> > PressedKeys;
		bool m_running=true;
		unsigned int MouseLeft=0;
		unsigned int MouseRight=0;
		unsigned wins = 0;
		
};
#endif

