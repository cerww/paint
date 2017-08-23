#include "ColorMode.h"

void iColorMode::drawSliders(sf::RenderWindow& win){
	static const sf::Vertex sampleTextVerts[4] = 
	{sf::Vertex(sf::Vector2f(800,40),sf::Color::White,sf::Vector2f(0,0)),
	 sf::Vertex(sf::Vector2f(800,90),sf::Color::White,sf::Vector2f(0,1)),
	 sf::Vertex(sf::Vector2f(880,90),sf::Color::White,sf::Vector2f(1,1)),
	 sf::Vertex(sf::Vector2f(880,40),sf::Color::White,sf::Vector2f(1,0)) };

	for(const auto& i:m_rgbSliders){
		i.draw(win);
	}
	win.draw(sampleTextVerts,4,sf::Quads,&m_colorSample);
}

std::pair<bool,sf::Color> iColorMode::updateSliders(const app& win){
	bool colorChanged = 0;
	for(int i = 0;i<3;++i){
		colorChanged |= m_rgbSliders[i].changeVal(win.getMouseCoords("main"),
												  win.getMouseClick("main",mouseButton::LEFT));//this is long, i should fix it
	}
	if(colorChanged){
		m_currentColor = {(uint8_t)m_rgbSliders[0].getVal(),
						  (uint8_t)m_rgbSliders[1].getVal(),
						  (uint8_t)m_rgbSliders[2].getVal(),
						  255};
		changeSampleColorThingy();
	}
	return {colorChanged,m_currentColor};
}

void iColorMode::changeSampleColorThingy(){
	sf::Image temp;
	temp.create(1,1,m_currentColor);
	m_colorSample.update(temp);
}

