#include "brushMode.h"

void brushMode::update(const app& win,sf::Texture& text){
	
	circleMode->update(win);
	squareMode->update(win);
	
	const auto temp = updateSliders(win);
	
	if(temp.first){
		m_brush->setColor(temp.second);
	}

	const auto temp2 = updateSizeSlider(win);
	if(temp2.first){
		m_brush->setSize(temp2.second);
	}
	
	if(pointInBox({0,100},500,500,win.getMouseCoords("main"))){
		if(win.getMouseClick("main",mouseButton::LEFT)){
			m_brush->brush(text,win.getMouseCoords("main") - sf::Vector2f{0.0f,100.0f});
		}
	}
}

void brushMode::draw(sf::RenderWindow& win){
	drawSliders(win);
	
	drawSizeSlider(win);
	
	squareMode->draw(win);
	circleMode->draw(win);
	
}

