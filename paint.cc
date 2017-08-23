#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <array>
#include <random>
#include <algorithm>
#include "app.h"
#include "button.h"
#include <functional>
#include "slider.h"
#include "brush.h"
#include "brushMode.h"
#include "bucketMode.h"
#include "lineMode.h"

/* canvas starts at 0,100 
 * size is 500 by 500
 * */
class paint{
	public:
		paint();// = default;
		void draw();
		bool update();
		void doStuff();
	private:
		app m_window;
		sf::Texture m_text;
		std::unique_ptr<iMode> m_currentMode;
		sf::Image m_undoImage;
};

paint::paint(){
	m_window.newWindow("main",900,700);
	m_window.windows["main"]->setFramerateLimit(120);
	m_text.create(500,500);
	//m_text.loadFromFile("testy1.png");
	
	m_undoImage = m_text.copyToImage();
	m_currentMode = std::unique_ptr<brushMode>(new brushMode);
}

void paint::draw(){
	static const sf::Vertex verts[4] = {sf::Vertex(sf::Vector2f(0,100),sf::Color::White,sf::Vector2f(0,0)),
										sf::Vertex(sf::Vector2f(0,600),sf::Color::White,sf::Vector2f(0,500)),
										sf::Vertex(sf::Vector2f(500,600),sf::Color::White,sf::Vector2f(500,500)),
										sf::Vertex(sf::Vector2f(500,100),sf::Color::White,sf::Vector2f(500,0)) };
		
	m_window.windows["main"]->draw(verts,4,sf::Quads);
	m_window.windows["main"]->draw(verts,4,sf::Quads,&m_text);
	m_currentMode->draw(*m_window.windows["main"]);
	
	m_window.windows["main"]->display();
}

bool paint::update(){
	m_window.update();
	static bool prevMouseDown = 0;
	if(pointInBox(m_window.getMouseCoords("main"),{0,100},500,500)){
		bool temp = m_window.getMouseClick("main",mouseButton::LEFT)>0;
		if(temp!=prevMouseDown){
			if(!prevMouseDown){
				m_undoImage = m_text.copyToImage();
			}
			prevMouseDown = temp;
		}
	}
	m_currentMode->update(m_window,m_text);
	return m_window.isRunning();
}

void paint::doStuff(){
	auto& window = m_window.windows["main"];
	button brushModeButton(	sf::Vector2f(30,30),
							{80,80},
							{{m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png")}},
							[&](){m_currentMode = std::unique_ptr<brushMode>(new brushMode); });
	button bucketModeButton(sf::Vector2f(120,30),
							{80,80},
							{{m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png")}},
							[&](){m_currentMode = std::unique_ptr<bucketMode>(new bucketMode); });
	button undoButton(sf::Vector2f(210,30),
					 {80,80},
					 {{m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png")}},
					 [&](){m_text.update(m_undoImage);}
					 );
	
	button lineModeButton(sf::Vector2f(300,30),
							{80,80},
							{{m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png"),m_window.getTexture("buttonImg.png")}},
							[&](){m_currentMode = std::unique_ptr<lineMode>(new lineMode); });
	while(update()){
		window->clear(sf::Color(222,222,222,255));
		
		undoButton.update(m_window);
		brushModeButton.update(m_window);
		bucketModeButton.update(m_window);
		lineModeButton.update(m_window);
		
		brushModeButton.draw(*window);
		bucketModeButton.draw(*window);
		undoButton.draw(*window);
		lineModeButton.draw(*window);
		draw();
	}
}

int main(){
	paint p;
	p.doStuff();
	return 0;
}

