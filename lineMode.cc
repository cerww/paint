#include "lineMode.h"
#include <cmath>
void lineMode::update(const app& win,sf::Texture& t){
	static unsigned numClicks = 0;
	static sf::Vector2f k[2] = {{},{}};
	const auto temp = updateSliders(win);
	if(temp.first){
		m_c = temp.second;
		m_b.setColor(m_c);
	}
	const auto temp2 = updateSizeSlider(win);
	if(temp2.first){
		m_b.setSize(temp2.second);
	}
	
	if(pointInBox(win.getMouseCoords("main"),{0.0f,100.0f},500,500)){
		if(win.getMouseClick("main",mouseButton::LEFT)==1){
			++numClicks;
			k[0] = k[1];
			k[1] = win.getMouseCoords("main")-sf::Vector2f(0,100);
			if(!(numClicks&1)){
				drawLine(t,k[0],k[1]);
			}
		}
	}
}

void lineMode::drawLine(sf::Texture& t,sf::Vector2f p1,const sf::Vector2f p2){
	const auto temp = p2-p1;
	const auto radians = std::atan2(temp.y,temp.x);
	sf::Vector2f unit((m_b.getSize()/2)*std::cos(radians),(m_b.getSize()/2)*std::sin(radians));
	
	int m = 1 + temp.x/unit.x;
	for(int i = 0;i<m;++i){
		m_b.brush(t,p1);
		p1+=unit;
	}
	
}

void lineMode::draw(sf::RenderWindow& win){
	drawSliders(win);
	drawSizeSlider(win);
}

