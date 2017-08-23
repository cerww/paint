#include "sizeMode.h"

std::pair<bool,int> iSizeMode::updateSizeSlider(const app& win){
	if(m_sizeSlider.changeVal(win.getMouseCoords("main"),
							  win.getMouseClick("main",mouseButton::LEFT))){
		size = m_sizeSlider.getVal();
		return {1,m_sizeSlider.getVal()};
	};
	return {0,0};
}

void iSizeMode::drawSizeSlider(sf::RenderWindow& win){
	m_sizeSlider.draw(win);
}

