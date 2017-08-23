#include "bucketMode.h"

void bucketMode::draw(sf::RenderWindow& win){
	drawSliders(win);
}
void bucketMode::update(const app& win,sf::Texture& text){
	auto temp = updateSliders(win);
	
	if(temp.first){
		m_b.setColor(temp.second);
	}
	if(pointInBox({0,100},500,500,win.getMouseCoords("main"))){
		if(win.getMouseClick("main",mouseButton::LEFT)){
			m_b.brush(text,win.getMouseCoords("main") - sf::Vector2f{0.0f,100.0f});
		}
	}
}

